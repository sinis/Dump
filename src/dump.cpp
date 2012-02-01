// Implementacja klasy Dump.

#include "dump.h"

// Singleton
Dump *Dump::_instance = 0;

Dump *Dump::Create()
{
    if (!_instance)
        _instance = new Dump;
    return _instance;
}

void Dump::Destroy()
{
    if (_instance)
    {
        delete _instance;
        _instance = 0;
    }
}

// Konstruktor i destruktor
Dump::Dump():
_window(new sf::RenderWindow)
{
}

Dump::~Dump()
{
    delete _window;
}

// Pêtla komunikatów
int Dump::Run()
{
    sf::Event event;

    // TODO:
    // Dane dla sf::Window::Create() powinny byæ ³adowane z ustawieñ.
    _window->Create(sf::VideoMode(640, 480, 32), "Dump");

    while (_window->IsOpen())
    {
        while (_window->PollEvent(event))
        {
            if (event.Type == sf::Event::Closed)
                _window->Close();
            else if (event.Type == sf::Event::KeyPressed &&
                event.Key.Code == sf::Keyboard::Escape)
                _window->Close();
        }

        _window->Clear();
        // TODO:
        // Tutaj przekazanie komunikatu aktualnemu ekranowi i odrysowanie
        // tego ekranu.
        _window->Display();
    }

    return 0;
}