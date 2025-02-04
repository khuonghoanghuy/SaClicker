#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({320, 280}), "SaClicker");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::White);

    // Config Window
    window.setPosition({100, 100});
    window.setSize({320, 280});
    sf::Vector2u size =  window.getSize();
    auto [width, height] = size;
    bool focus = window.hasFocus();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}