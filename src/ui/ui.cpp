#include "ui/ui.h"
#include "decoding/album.h"
#include "decoding/song.h"
#include "org/additional.h"

#include <iostream>

Album playlist;

int indexOfCurrentTrack = 0;

static std::string currentDirectory = "/home/kusneid/Documents/MusicPlayer/Low Roar - ross";//сюда вставлять путь с треками

uiResources::ResourceManager::ResourceManager()
{
  LoadFromDirectory("../icons");
  LoadFonts();
}

int uiResources::ResourceManager::LoadFonts()
{
  if (!font.loadFromFile("../fonts/Roboto-Light.ttf"))
  {
    std::cerr << "error loading fonts" << std::endl;
    return -1;
  }
  else
  {
    std::cout << "fonts loaded" << std::endl;
  }
  return 0;
}

int uiResources::ResourceManager::LoadFromDirectory(const std::string &directory)
{

  for (const auto &textureFile : std::filesystem::directory_iterator(directory))
  {
    if (textureFile.is_regular_file())
    {
      if (textureFile.path().extension() == ".png")
      {
        sf::Texture texture;
        if (texture.loadFromFile(textureFile.path().string()))
        {
          std::string filename = textureFile.path().stem().string();
          textures[filename] = texture;
          std::cout << "texture " << filename << " is loaded\n";
        }
        else
        {
          std::cerr << "failed to load " << textureFile.path().filename().string() << std::endl;
        }
      }
    }
  }
  return 0;
}

sf::Texture &uiResources::ResourceManager::GetTexture(const std::string &name)
{
  return textures.at(name);
}

sf::Font &uiResources::ResourceManager::GetFont()
{
  return font;
}

namespace gui
{
  void rewind(Album &playlist, int &indexOfCurrentTrack, bool direction)
  {
    playlist.getSong(indexOfCurrentTrack).pause();
    if (direction)
    {
      indexOfCurrentTrack++;
      if (indexOfCurrentTrack == playlist.getSize())
      {
        indexOfCurrentTrack = 0;
      }
    }
    else
    {
      indexOfCurrentTrack--;
      if (indexOfCurrentTrack < 0)
      {
        indexOfCurrentTrack = playlist.getSize() - 1;
      }
    }
    playlist.getSong(indexOfCurrentTrack).playback(sf::seconds(0));
  }
  GUISong::GUISong(Song s, sf::Text t) : songClass(s), songNameSF(t) {}

  int GUIRenderBase(sf::RenderWindow &window, uiResources::ResourceManager &resourceManager)
  {

    
    
    playlist.getMusicFiles(currentDirectory); // забираем названия песен
    
    
    bool iconLoaded = false;
    if (!iconLoaded)
    {
      sf::Image icon;
      if (!icon.loadFromFile("../icons/icon.png"))
      {
        std::cerr << "Error loading icon" << std::endl;
        return -1;
      }
      window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
      iconLoaded = true;
    }

    sf::Sprite backgroundSprite(resourceManager.GetTexture("background"));
    backgroundSprite.setScale(
        static_cast<float>(window.getSize().x) / resourceManager.GetTexture("background").getSize().x,
        static_cast<float>(window.getSize().y) / resourceManager.GetTexture("background").getSize().y);

    while (window.isOpen())
    {
      static sf::Event event;
      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
        {
          window.close();
        }
      }

      window.clear(sf::Color::Black);
      window.draw(backgroundSprite);

      static sf::Text sName;

      if (CurrentTrackControlGUI(window, resourceManager, event, sName) != 0)
      {
        throw std::runtime_error("unable to render gui of track control");
        return -1;
      }

      if (PlaylistsGUI(window, resourceManager, event, sName) != 0)
      {
        throw std::runtime_error("unable to render gui of track control");
        return -1;
      }

      window.display();
    }

    return 0;
  }

  int CurrentTrackControlGUI(sf::RenderWindow &window, uiResources::ResourceManager &resourceManager, sf::Event &event, sf::Text &sName)
  {
    static bool initialized = false;
    static float volumeDotCurrentX = 0.0f;
    static bool musicIsPlaying = false;

    static bool mousePressed = false;
    static bool sliderPressed = false;

    static sf::Sprite prevButton;
    static sf::Sprite playButton;
    static sf::Sprite nextButton;
    static sf::RectangleShape volumeSlider;
    static sf::CircleShape volumeDot;

    if (!initialized)
    {
      float bottomStart = BOTTOM_LINE;

      std::string songNameFull = "Select song to play"; // = исполнитель - трек
      sName.setFont(resourceManager.GetFont());
      sName.setString(songNameFull);
      sName.setCharacterSize(40);
      sName.setFillColor(sf::Color::Black);
      sName.setPosition(40.f, bottomStart);

      float buttonS = 65.f;
      sf::Vector2f buttonSize(DEFAULT_BUTTON_SIZE, DEFAULT_BUTTON_SIZE);
      sf::Vector2f volumeSize(200.f, 15.f);
      float buttonSpacing = 30.f;
      float startX = 480.f;

      prevButton.setTexture(resourceManager.GetTexture("prev"));
      prevButton.setPosition(startX, bottomStart);
      prevButton.setScale(buttonSize.x / prevButton.getTexture()->getSize().x, buttonSize.y / prevButton.getTexture()->getSize().y);

      playButton.setTexture(resourceManager.GetTexture("play"));
      playButton.setPosition(startX + (buttonSize.x + buttonSpacing), bottomStart);
      playButton.setScale(buttonSize.x / playButton.getTexture()->getSize().x, buttonSize.y / playButton.getTexture()->getSize().y);

      nextButton.setTexture(resourceManager.GetTexture("next"));
      nextButton.setPosition(startX + 2 * (buttonSize.x + buttonSpacing), bottomStart);
      nextButton.setScale(buttonSize.x / nextButton.getTexture()->getSize().x, buttonSize.y / nextButton.getTexture()->getSize().y);

      volumeSlider.setSize(volumeSize);
      volumeSlider.setFillColor(sf::Color::Black);
      volumeSlider.setPosition(startX + 6 * (buttonSize.x + buttonSpacing), bottomStart + (buttonSize.y - volumeSize.y));

      volumeDot.setRadius(10.f);
      volumeDot.setFillColor(sf::Color::Cyan);
      volumeDotCurrentX = volumeSlider.getPosition().x + (volumeSlider.getSize().x / 2.f) - volumeDot.getRadius();
      volumeDot.setPosition(volumeDotCurrentX, volumeSlider.getPosition().y - 3.f);

      initialized = true;
    }

    if (sliderPressed && mousePressed)
    {
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      float newX = static_cast<float>(mousePos.x);
      float sliderStartX = volumeSlider.getPosition().x;
      float sliderEndX = sliderStartX + volumeSlider.getSize().x - 2 * volumeDot.getRadius();

      if (newX < sliderStartX)
      {
        newX = sliderStartX;
      }
      else if (newX > sliderEndX)
      {
        newX = sliderEndX;
      }

      volumeDotCurrentX = newX;

      float volumeLevel = (newX - sliderStartX) / (sliderEndX - sliderStartX);
      playlist.getSong(indexOfCurrentTrack).get_sfMusic().setVolume(volumeLevel * 100);
    }

    volumeDot.setPosition(volumeDotCurrentX, volumeDot.getPosition().y);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
      mousePressed = true;

      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      if (volumeDot.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
      {
        sliderPressed = true;
      }
    }
    else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
      if (mousePressed)
      {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (prevButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
          std::cout << "prev" << std::endl;
          rewind(playlist, indexOfCurrentTrack, 0);
          sName.setString(playlist.getSong(indexOfCurrentTrack).get_name());
        }
        else if (playButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
          std::cout << "play" << std::endl;

          if (!playlist.getSong(indexOfCurrentTrack).get_status())
          {
            playButton.setTexture(resourceManager.GetTexture("pause"));
            std::cout << playlist.getSong(indexOfCurrentTrack).get_path() << '\n';
            playlist.getSong(indexOfCurrentTrack).playback(playlist.getSong(indexOfCurrentTrack).get_current_time());
          }
          else
          {
            playButton.setTexture(resourceManager.GetTexture("play"));
            playlist.getSong(indexOfCurrentTrack).pause();
          }
          sName.setString(playlist.getSong(indexOfCurrentTrack).get_name()); // меняет название в интерфейсе слева сверху
        }
        else if (nextButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
          std::cout << "next" << std::endl;
          rewind(playlist, indexOfCurrentTrack, 1);
          sName.setString(playlist.getSong(indexOfCurrentTrack).get_name());
        }

        sliderPressed = false;
        mousePressed = false;
      }
    }

    window.draw(sName);
    window.draw(playButton);
    window.draw(nextButton);
    window.draw(prevButton);
    window.draw(volumeSlider);
    window.draw(volumeDot);

    return 0;
  }

  int PlaylistsGUI(sf::RenderWindow &window, uiResources::ResourceManager &resourceManager, sf::Event &event, sf::Text &sName)
  {
    static sf::Sprite openFolderButton(resourceManager.GetTexture("open_folder"));
    static sf::RectangleShape boundaryLine(sf::Vector2f(window.getSize().x, 3.f));
    static sf::Sprite searchByYoutubeButton(resourceManager.GetTexture("youtube"));

    static bool initialized = false;
    static float scrollOffset = 0.f;
    static float maxScrollOffset = 0.f;

    static std::vector<GUISong> trackListGUI;

    if (!initialized)
    {
      openFolderButton.setPosition(30.f, window.getSize().y - 100.f);
      openFolderButton.setScale(DEFAULT_BUTTON_SIZE / openFolderButton.getTexture()->getSize().x, DEFAULT_BUTTON_SIZE / openFolderButton.getTexture()->getSize().y);

      searchByYoutubeButton.setPosition(30.f, window.getSize().y - 180.f);
      searchByYoutubeButton.setScale(DEFAULT_BUTTON_SIZE / openFolderButton.getTexture()->getSize().x, DEFAULT_BUTTON_SIZE / openFolderButton.getTexture()->getSize().y);

      boundaryLine.setFillColor(sf::Color::Blue);
      boundaryLine.setPosition(0.f, BOTTOM_LINE * 3.5);

      initialized = true;
    }

    static bool mousePressed = false;

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !mousePressed)
    {
      mousePressed = true;
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      if (openFolderButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
      {

        playlist.getSong(indexOfCurrentTrack).pause();


        currentDirectory = additional::SelectFolder();
        //На момент коммита я так и не смог приделать эту фичу, проблема в слэшах была решена через ф-ии в additional, однако всё равно треки вне проекта не открываются
        //upd 05.06.2024 я все-таки реализовал это но доступно только на линукс см. Readme.md

        trackListGUI.clear();


        playlist.getMusicFiles(currentDirectory);

        for (size_t i = 0; i < playlist.getSize(); ++i)
        {
          Song song = playlist.getSong(i);
          sf::Text songName(song.get_name(), resourceManager.GetFont(), 30);
          trackListGUI.push_back(GUISong(song, songName));
        }

        float yOffset = boundaryLine.getPosition().y + 50.f;
        for (size_t i = 0; i < trackListGUI.size(); ++i)
        {
          trackListGUI[i].songNameSF.setFillColor(sf::Color::Black);
          trackListGUI[i].songNameSF.setPosition(400.f, yOffset + i * 40.f);
        }

        maxScrollOffset = std::max(0.f, yOffset + trackListGUI.size() * 40.f - window.getSize().y + 150.f);
        scrollOffset = 0.f;
      }
      else if (searchByYoutubeButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
      {
        std::string currentTrackName = "your current track name";

        std::string base_url = "https://www.youtube.com/results?search_query=";
        std::string query = playlist.getSong(indexOfCurrentTrack).get_name();

        for (size_t pos = 0; pos < query.length(); ++pos) {
            if (query[pos] == ' ') {
                query[pos] = '+';
            }
        }
        std::string full_url = base_url + query;
        std::string command = "xdg-open \"" + full_url + "\"";

        std::system(command.c_str());
      }
      else
      {
        for (size_t i = 0; i < trackListGUI.size(); ++i)
        {
          if (trackListGUI[i].songNameSF.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
          {
            playlist.getSong(indexOfCurrentTrack).pause();
            indexOfCurrentTrack = i;
            playlist.getSong(indexOfCurrentTrack).playback(playlist.getSong(indexOfCurrentTrack).get_current_time());
            sName.setString(playlist.getSong(indexOfCurrentTrack).get_name());
            
            break;
          }
        }
      }
    }
    else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
      mousePressed = false;
    }

    if (event.type == sf::Event::MouseWheelScrolled)
    {
      scrollOffset += event.mouseWheelScroll.delta * -10.f;
      if (scrollOffset < 0)
      {
        scrollOffset = 0;
      }
      else if (scrollOffset > maxScrollOffset)
      {
        scrollOffset = maxScrollOffset;
      }
    }

    for (size_t i = 0; i < trackListGUI.size(); ++i)
    {
      float textY = boundaryLine.getPosition().y + 50.f - scrollOffset + i * 40.f;
      if (textY > 175.f && textY < window.getSize().y)
      {
        trackListGUI[i].songNameSF.setPosition(400.f, textY);
        window.draw(trackListGUI[i].songNameSF);

        sf::RectangleShape trackBoundary(sf::Vector2f(600.f, 2.f));
        trackBoundary.setFillColor(sf::Color::Black);
        trackBoundary.setPosition(400.f, textY + 35.f);
        window.draw(trackBoundary);
      }
    }

    window.draw(searchByYoutubeButton);
    window.draw(openFolderButton);
    window.draw(boundaryLine);

    return 0;
  }

}
