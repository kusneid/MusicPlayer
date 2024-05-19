#include "ui/ui.h"
#include "decoding/album.h"

Song current_track;
Album playlist;
int i = 0;

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
  int GUIRenderBase(sf::RenderWindow &window, uiResources::ResourceManager &resourceManager)
  {
    playlist.getMusicFiles("Music"); // забираем названия песен
    for (int j = 0; j < playlist.getSize(); j++)
    {
      std::cout << playlist.getSong(j).get_name() << '\n';
    }


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
      sf::Event event;
      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
        {
          window.close();
        }
      }

      window.clear(sf::Color::Black);
      window.draw(backgroundSprite);

      if (CurrentTrackControlGUI(window, resourceManager, event) != 0)
      {
        throw std::runtime_error("unable to render gui of track control");
        return -1;
      }

      if (PlaylistsGUI(window, resourceManager, event) != 0)
      {
        throw std::runtime_error("unable to render gui of track control");
        return -1;
      }

      window.display();
    }

    return 0;
  }

  int CurrentTrackControlGUI(sf::RenderWindow &window, uiResources::ResourceManager &resourceManager, sf::Event &event)
  {
    static bool initialized = false;
    static float volumeDotCurrentX = 0.0f;
    static bool musicIsPlaying = false;

    static bool mousePressed = false;
    static bool sliderPressed = false;

    static sf::Text sName;
    static sf::Sprite prevButton;
    static sf::Sprite playButton;
    static sf::Sprite nextButton;
    static sf::RectangleShape volumeSlider;
    static sf::CircleShape volumeDot;

    if (!initialized)
    {
      float bottomStart = BOTTOM_LINE;

      std::string songNameFull = "Artist - Song"; // = исполнитель - трек
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
      volumeDot.setFillColor(sf::Color::Red);
      volumeDot.setPosition(volumeSlider.getPosition().x, volumeSlider.getPosition().y - 3.f);

      volumeDotCurrentX = volumeDot.getPosition().x;

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

      float volumeLevel = (newX - sliderStartX) / (sliderEndX - sliderStartX) * 100;
      std::cout << "Volume: " << volumeLevel << std::endl;
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
          current_track.pause();
          i--;
          current_track = playlist.getSong(i);
          current_track.playback();
        }
        else if (playButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
          std::cout << "play" << std::endl;
          current_track = playlist.getSong(i);
          std::cout << current_track.get_status() << '\n';
          if (!current_track.get_status()){
              current_track.playback();
          }
          else{
              current_track.pause();
          }
        }
        else if (nextButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
          std::cout << "next" << std::endl;
          std::cout << current_track.get_status() << '\n';
          current_track.pause();
          i++;
          current_track = playlist.getSong(i);
          current_track.playback();
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

  int PlaylistsGUI(sf::RenderWindow &window, uiResources::ResourceManager &resourceManager, sf::Event &event)
  {
    static sf::Sprite openFolderButton(resourceManager.GetTexture("open_folder"));
    static sf::RectangleShape boundaryLine(sf::Vector2f(window.getSize().x, 3.f));

    static bool initialized = false;
    static float scrollOffset = 0.f;

    static std::vector<std::string> trackList = {"Track 1", "Track 2", "Track 3", "Track 4", "Track 5"};
    // здесь надо будет заполнить треками все

    if (!initialized)
    {
      openFolderButton.setPosition(30.f, window.getSize().y - 100.f);
      openFolderButton.setScale(DEFAULT_BUTTON_SIZE / openFolderButton.getTexture()->getSize().x, DEFAULT_BUTTON_SIZE / openFolderButton.getTexture()->getSize().y);

      boundaryLine.setFillColor(sf::Color::Blue);
      boundaryLine.setPosition(0.f, BOTTOM_LINE * 3.5);

      initialized = true;
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      if (openFolderButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
      {
        // open folder
      }
    }
    if (event.type == sf::Event::MouseWheelScrolled)
    {
      scrollOffset += event.mouseWheelScroll.delta * 30.f;
      if (scrollOffset < 0)
      {
        scrollOffset = 0;
      }
    }

    float yOffset = boundaryLine.getPosition().y + 50.f;
    for (size_t i = 0; i < trackList.size(); ++i)
    {
      sf::Text text(trackList[i], resourceManager.GetFont(), 20);
      text.setPosition(400.f, yOffset + scrollOffset + i * 30.f);
      window.draw(text);

      sf::RectangleShape trackBoundary(sf::Vector2f(600.f, 1.f));
      trackBoundary.setFillColor(sf::Color::White);
      trackBoundary.setPosition(400.f, yOffset + scrollOffset + i * 30.f + 25.f);
      window.draw(trackBoundary);
    }

    window.draw(openFolderButton);

    window.draw(boundaryLine);

    return 0;
  }
}