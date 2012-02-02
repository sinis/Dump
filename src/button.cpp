#include "button.h"

Button::Button(int id, const std::string &text, const sf::Color &color):
    _id(id),
    _text(new sf::Text(text))
{
    _text->SetColor(color);
}

Button::~Button()
{
    delete _text;
}

Button::State Button::HandleMouse()
{
    // Tutaj button sprawdza stan kursora.
    // Jeœli kursor jest nad buttonem - pogrub _text. (State::MouseOver)
    // Jeœli dodatkowo naciœniêty jest LPM - State::Clicked.

    sf::Vector2i pos = sf::Mouse::GetPosition();
    if (_text->GetGlobalBounds().Contains((float)pos.x, (float)pos.y))
    {
        _text->SetStyle(sf::Text::Bold);

        if (sf::Mouse::IsButtonPressed(sf::Mouse::Left))
            return Clicked;
        else
            return MouseOver;
    }
    _text->SetStyle(sf::Text::Regular);
    return None;
}
