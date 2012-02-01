// Screen
// Abstrakcyjna klasa bazowa dla ka¿dego ekranu gry.

#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SFML/Graphics.hpp>

class Screen
{
public:
    Screen(sf::RenderWindow *window) { _window = window; }
    virtual ~Screen() {}

    virtual int Handle(const sf::Event &event) = 0;
    virtual void Draw();

private:
    sf::RenderWindow *_window;
};

#endif // _SCREEN_H_