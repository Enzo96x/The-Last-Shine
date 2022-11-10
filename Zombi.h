#ifndef ZOMBI_H_INCLUDED
#define ZOMBI_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Colisionable.h"

class Zombie: public Personaje , public Colisionable, public sf::Drawable{

private:
    sf::Texture ZombieTextura;
    sf::Sprite ZombieSprite;
    int _direccion;
    bool reiniciarframe;

public:
    Zombie();
    bool muerto=true;
    bool golpeado;
    bool ataco;
    void init();
    void Update();
    void draw(sf::RenderTarget& target,sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
};


#endif // ZOMBI_H_INCLUDED
