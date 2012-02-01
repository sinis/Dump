#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow wnd(sf::VideoMode(640, 480, 32), "Dump");
    sf::Event event;
    sf::Text text("Initial commit.");
    text.SetOrigin(text.GetLocalBounds().Width/2, text.GetLocalBounds().Height/2);
    text.SetColor(sf::Color::White);

    while (wnd.IsOpen())
    {
        while (wnd.PollEvent(event))
        {
            if (event.Type == sf::Event::Closed ||
                (event.Type == sf::Event::KeyPressed &&
                event.Key.Code == sf::Keyboard::Escape))
                wnd.Close();
        }

        wnd.Clear();
        text.SetPosition(wnd.GetWidth()/2, wnd.GetHeight()/2);
        wnd.Draw(text);
        wnd.Display();
    }

    return 0;
}