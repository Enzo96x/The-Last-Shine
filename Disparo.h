#ifndef DISPARO_H_INCLUDED
#define DISPARO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Disparo : public Colisionable, public sf::Drawable {

private:
    sf::Texture balaTextura;
    sf::Sprite balaSprite;
    int _direccion;
    sf::Vector2i _coordenadas;
public:
    Disparo();
    bool activo;
    void draw(sf::RenderTarget& target,sf::RenderStates states) const override;
    void setcoordenadas(sf::Vector2i coordenadas, int direccion);
    void update();
    sf::FloatRect getBounds() const override;

};

#endif // DISPARO_H_INCLUDED
