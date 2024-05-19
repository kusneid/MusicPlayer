#include "SFML/Graphics.hpp"
#include "ui/ui.h"

int main()
{
    system("chcp 65001");

    sf::RenderWindow window(sf::VideoMode(INITIAL_WINDOW_RESOLUTION_X, INITIAL_WINDOW_RESOLUTION_Y), "Music Player", sf::Style::Titlebar | sf::Style::Close);

        
    
    uiResources::ResourceManager resourceManager;

    return gui::GUIRenderBase(window, resourceManager);
}

//по возможности сюда больше ниче не добавлять