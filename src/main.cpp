#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
//здесь просто надо срендерить окно плеера
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::RectangleShape button(sf::Vector2f(100.f, 50.f));
    button.setFillColor(sf::Color::Green);
    button.setPosition(50.f, 75.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (button.getGlobalBounds().contains(mousePosF)) {
                        std::cout << "Hello World!" << std::endl;
                    }
                }
            }
        }

        window.clear();
        window.draw(button);
        window.display();
    }

    return 0;

}