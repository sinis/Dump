// Screen
// Abstrakcyjna klasa bazowa dla każdego ekranu gry.

#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SFML/Graphics.hpp>
#include "dump.h"

class Screen
{
public:
    Screen() { _window = Dump::GetWindow(); }
    virtual ~Screen() {}

    virtual int Handle(const sf::Event &event) = 0; // Obsługa komunikatów
    virtual void Draw() = 0; // Odrysowanie
    virtual void Update() = 0; // Aktualizacja ekranu (głównie zmiana rozmiaru okna).

private:
    sf::RenderWindow *_window;
};

#endif // _SCREEN_H_
