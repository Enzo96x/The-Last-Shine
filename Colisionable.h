#ifndef COLISIONABLE_H_INCLUDED
#define COLISIONABLE_H_INCLUDED
#include <SFML/Graphics.hpp>

class Colisionable{
public:
virtual sf::FloatRect getBounds() const=0;
bool esColision (Colisionable& obj) const;
};


#endif // COLISIONABLE_H_INCLUDED
