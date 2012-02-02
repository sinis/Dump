// Dump
// Główna klasa gry. Zawiera pętlę komunikatów.

#ifndef _DUMP_H_
#define _DUMP_H_

#include <SFML/Graphics.hpp>

class Dump
{
    Dump();
    ~Dump();
public:
    static Dump *Create();
    static void Destroy();

    int Run();

private:
    static Dump *_instance;
    sf::RenderWindow *_window;
};

#endif // _DUMP_H_
