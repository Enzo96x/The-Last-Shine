#include "Disparo.h"

Disparo::Disparo() {
    balaTextura.loadFromFile("assets/imagenes/bala.png");
    balaSprite.setTexture(balaTextura);
    balaSprite.setTextureRect(sf::IntRect(0,0,28,18));
}


/*void Disparo::disparar(int x, int y, int direccion) {



}*/


sf::FloatRect Disparo::getBounds() const{
return balaSprite.getGlobalBounds();
}
