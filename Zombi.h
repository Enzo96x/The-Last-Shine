#ifndef ZOMBI_H_INCLUDED
#define ZOMBI_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Personaje.h"

class Zombie: public Personaje , public sf::Drawable{

private:
    sf::Texture ZombieTextura;
    sf::Sprite ZombieSprite;
    int _direccion;
    int _posicion;

public:
    Zombie();
    void Update();
    void draw(sf::RenderTarget& target,sf::RenderStates states) const override;
};


#endif // ZOMBI_H_INCLUDED
