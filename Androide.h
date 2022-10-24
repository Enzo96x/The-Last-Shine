#ifndef ANDROIDE_H_INCLUDED
#define ANDROIDE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Personaje.h"

class Androide : public Personaje , public sf::Drawable{
private:
    sf::Texture AndroideTextura;
    sf::Sprite AndroideSprite;
    int teclaAnimacion;

public:
    Androide();
    void Update();
    void draw(sf::RenderTarget& target,sf::RenderStates states) const override;
};



#endif // ANDROIDE_H_INCLUDED
