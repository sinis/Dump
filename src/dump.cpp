// Implementacja klasy Dump.

#include "dump.h"
#include "settings.h"

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
    _window(new sf::RenderWindow),
    _title("Dump"),
    _version("v0.1")
{
    Settings *s = Settings::Create();
    s->Load();
    if (!s->AreLoaded())
        s->SetToDefaults();
    _window->Create(sf::VideoMode(s->GetScreenWidth(), s->GetScreenHeight(), 32), (_title + ' ') + _version);
    // TODO:
    // Obsługa fullscreena.
}

Dump::~Dump()
{
    delete _window;
}

// Pętla komunikatów
int Dump::Run()
{
    sf::Event event;

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
