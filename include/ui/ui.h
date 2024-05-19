#pragma once 

#include <filesystem>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include <variant>

#define INITIAL_WINDOW_RESOLUTION_Y 720
#define INITIAL_WINDOW_RESOLUTION_X 1280 

#define DEFAULT_BUTTON_SIZE 65.f

#define BOTTOM_LINE 50.f

namespace uiResources
{
  class ResourceManager{
  private:
    std::map<std::string, sf::Texture> textures;
    sf::Font font;
  public:
    ResourceManager();
    int LoadFromDirectory(const std::string& directory);
    int LoadFonts();
    sf::Texture& GetTexture(const std::string& name);
    sf::Font& GetFont();
};
} // namespace uiResources

namespace gui{
  int GUIRenderBase(sf::RenderWindow& window, uiResources::ResourceManager& resourceManager);
  int CurrentTrackControlGUI(sf::RenderWindow& window, uiResources::ResourceManager& resourceManager, sf::Event& event);
  int PlaylistsGUI(sf::RenderWindow& window, uiResources::ResourceManager& resourceManager,sf::Event& event);
  int UpdatePlaylist(sf::RenderWindow& window);
} // namespace gui