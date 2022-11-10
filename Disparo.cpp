#include "Disparo.h"

Disparo::Disparo() {
    balaTextura.loadFromFile("assets/imagenes/bala.png");
    balaSprite.setTexture(balaTextura);
    balaSprite.setTextureRect(sf::IntRect(0,0,28,18));
    activo=false;
}




void Disparo::draw(sf::RenderTarget& target,sf::RenderStates states)const {

    target.draw(balaSprite, states);
}

void Disparo::setcoordenadas(sf::Vector2i coordenadas, int direccion) {
    _coordenadas={coordenadas.x,coordenadas.y};
    balaSprite.setPosition(coordenadas.x,coordenadas.y);
    _direccion=direccion;
    switch(_direccion) {
    case 1://arriba
        balaSprite.setRotation(-90);
        balaSprite.setPosition(_coordenadas.x+=62,_coordenadas.y+=30);
        break;
    case 2://abajo
        balaSprite.setRotation(90);
        balaSprite.setPosition(_coordenadas.x+=74,_coordenadas.y+=70);
        break;
    case 3://izq
        balaSprite.setRotation(180);
          balaSprite.setPosition(_coordenadas.x+=45,_coordenadas.y+=60);
        break;
    case 4://der
        balaSprite.setRotation(0);
             balaSprite.setPosition(_coordenadas.x+=95,_coordenadas.y+=45);
        break;
    }

}




void Disparo::update() {
    /*switch(_direccion) {
    case 1:
        balaSprite.move(0,-9);
        break;
    case 2:
        balaSprite.move(0,9);
        break;
    case 3:
        balaSprite.move(-9,0);
        break;
    case 4:
        balaSprite.move(9,0);
        break;
    }*/

    switch(_direccion) {
    case 1:
        balaSprite.setPosition(_coordenadas.x+=0,_coordenadas.y-=9);
        break;
    case 2:
        balaSprite.setPosition(_coordenadas.x+=0,_coordenadas.y+=9);
        break;
    case 3:
        balaSprite.setPosition(_coordenadas.x-=9,_coordenadas.y+=0);
        break;
    case 4:
        balaSprite.setPosition(_coordenadas.x+=9,_coordenadas.y+=0);
        break;
    }


    if(_coordenadas.x<=0||_coordenadas.x>=1000){
        activo=false;
    }

    if(_coordenadas.y<=0||_coordenadas.y>=800){
        activo=false;
    }
}

sf::FloatRect Disparo::getBounds() const {
    return balaSprite.getGlobalBounds();
}















