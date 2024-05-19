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
      playlist.getMusicFiles("Music"); //забираем названия песен
      for (int j = 0; j < playlist.getSize(); j++){
          std::cout << playlist.getSong(j).get_name() << '\n';
      }
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

      window.clear(sf::Color::Yellow);

      if (CurrentTrackControlGUI(window, resourceManager, event) != 0)
      {
        throw std::runtime_error("unable to render gui of track control");
      }

      window.display();
    }

    return 0;
  }

  int CurrentTrackControlGUI(sf::RenderWindow &window, uiResources::ResourceManager &resourceManager, sf::Event &event)
  {
    sf::Vector2f currentWindowSize{INITIAL_WINDOW_RESOLUTION_X, INITIAL_WINDOW_RESOLUTION_Y};
    sf::Vector2f scaleFactor(1.f, 1.f);

    if (event.type == sf::Event::Resized)
    {
      currentWindowSize = sf::Vector2f(event.size.width, event.size.height);
      scaleFactor.x = currentWindowSize.x / INITIAL_WINDOW_RESOLUTION_X;
      scaleFactor.y = currentWindowSize.y / INITIAL_WINDOW_RESOLUTION_Y;
    }

    float bottomStart = 50.f * scaleFactor.y;

    std::string songNameFull = "Artist - Song"; // = исполнитель - трек
    sf::Text sName{songNameFull, resourceManager.GetFont(), 40 * static_cast<unsigned int>(scaleFactor.x)};
    sName.setFillColor(sf::Color::Black);
    sName.setPosition(40.f, bottomStart);

    float buttonS = 65.f * scaleFactor.x;

    sf::Vector2f buttonSize(buttonS, buttonS);
    sf::Vector2f volumeSize(200.f, 15.f);

    float buttonSpacing = 30.f;
    float startX = 480.f * scaleFactor.x;

    // std::variant<sf::Texture>(resourceManager.GetTexture("play"),resourceManager.GetTexture("pause"));

    sf::Sprite prevButton(resourceManager.GetTexture("prev"));
    prevButton.setPosition(startX, bottomStart);
    prevButton.setScale(buttonSize.x / prevButton.getTexture()->getSize().x * scaleFactor.x, buttonSize.y / prevButton.getTexture()->getSize().y * scaleFactor.y);

    sf::Sprite playButton(resourceManager.GetTexture("play"));
    playButton.setPosition(startX + (buttonSize.x + buttonSpacing) * scaleFactor.x, bottomStart);
    playButton.setScale(buttonSize.x / playButton.getTexture()->getSize().x * scaleFactor.x, buttonSize.y / playButton.getTexture()->getSize().y * scaleFactor.y);

    sf::Sprite nextButton(resourceManager.GetTexture("next"));
    nextButton.setPosition(startX + 2 * (buttonSize.x + buttonSpacing) * scaleFactor.x, bottomStart);
    nextButton.setScale(buttonSize.x / nextButton.getTexture()->getSize().x, buttonSize.y / nextButton.getTexture()->getSize().y * scaleFactor.y);


      // тут пока хз как реализовывать!!!!!!!!
    sf::RectangleShape volumeSlider(volumeSize);
    volumeSlider.setFillColor(sf::Color::Black);
    volumeSlider.setPosition(startX + 6 * (buttonSize.x + buttonSpacing) * scaleFactor.x, bottomStart + (buttonSize.y - volumeSize.y) * scaleFactor.y / 2);

    sf::CircleShape volumeDot(10.f * scaleFactor.x);
    volumeDot.setFillColor(sf::Color::Red);
    volumeDot.setPosition(volumeSlider.getPosition().x,volumeSlider.getPosition().y - 3.f);//!!!!!scalefactor


    static bool sliderPressed = false;
    static bool mousePressed = false;

    
    static float volumeDotCurrentX = volumeDot.getPosition().x;
    if (sliderPressed && mousePressed)
    {
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      float newX = static_cast<float>(mousePos.x);
      float sliderStartX = volumeDot.getPosition().x;//???????zato 
      float sliderEndX = sliderStartX + volumeSlider.getSize().x - 2*volumeDot.getRadius();

      if (newX < sliderStartX)
      {
        newX = sliderStartX;
      }
      else if (newX > sliderEndX)
      {
        newX = sliderEndX;
      }

      volumeDotCurrentX = newX;
      
      
      float volumeLevel = (newX - sliderStartX) / volumeSlider.getSize().x*10/9     *100;
      std::cout <<volumeLevel;
    }
    
    volumeDot.setPosition(volumeDotCurrentX,volumeDot.getPosition().y);
    
    
    
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
    // window.draw(pauseButton);
    window.draw(nextButton);
    window.draw(prevButton);

    window.draw(volumeSlider);
    window.draw(volumeDot);

    return 0;
  }
}