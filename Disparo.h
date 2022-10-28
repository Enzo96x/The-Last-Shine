#ifndef DISPARO_H_INCLUDED
#define DISPARO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Disparo : public Colisionable, public sf::Drawable {

private:
    sf::Texture balaTextura;
    sf::Sprite balaSprite;

public:
    Disparo();
    //void disparar(int x, int y, int direccion);
    sf::FloatRect getBounds() const override;

};

#endif // DISPARO_H_INCLUDED
