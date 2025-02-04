#include <SFML/Graphics.hpp>

int score = 0;

int main()
{
    // Make Circle
    sf::RenderWindow window(sf::VideoMode({320, 280}), "SaClicker");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::White);

    // Make Text
    sf::Font font;
    if (!font.loadFromFile("fonts/vcr.ttf")) {
        // error should popup
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Click: " + std::to_string(score));
    text.setCharacterSize(16);

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
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        score += 1;
                        text.setString("Score: " + std::to_string(score));
                    }
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.draw(text);
        window.display();
    }
}