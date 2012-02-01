// Button
// Klasa przycisku dla menu.

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SFML/Graphics.hpp>

class Button
{
public:

    enum State {
        None,
        MouseOver,
        Clicked
    };

    Button(int id = 0, const std::string &text = "", const sf::Color &color = sf::Color::White);
    ~Button();

    void SetId(int id) { _id = id; }
    int GetId() const { return _id; }
    void SetText(const std::string &text) { _text->SetString(text); }
    void SetColor(const sf::Color &color) { _text->SetColor(color); }
    void SetPosition(float x, float y) { _text->SetPosition(x, y); }

    State HandleMouse();
    void Draw(sf::RenderWindow &window) { window.Draw(*_text); };

private:
    int _id;
    sf::Text *_text;
};

#endif // _BUTTON_H_