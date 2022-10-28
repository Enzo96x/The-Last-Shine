#ifndef ANDROIDE_H_INCLUDED
#define ANDROIDE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Colisionable.h"


class Androide : public Personaje , public Colisionable, public sf::Drawable{
private:
    sf::Texture AndroideTextura;
    sf::Sprite AndroideSprite;
    int teclaAnimacion;

public:
    Androide();
    void Update();
    void draw(sf::RenderTarget& target,sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
};



#endif // ANDROIDE_H_INCLUDED
