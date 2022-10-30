#include "Androide.h"

Androide::Androide() {
    AndroideTextura.loadFromFile("assets/imagenes/androide22.png");
    AndroideSprite.setTexture(AndroideTextura);
    x_coord=440, y_coord=340;
    AndroideSprite.setPosition(x_coord,y_coord);
    AndroideSprite.setTextureRect(sf::IntRect(0,0,120,120));
}




void Androide::Update() {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&teclaAnimacion!=1) {
            AndroideSprite.setPosition(x_coord+=0,y_coord-=120);
            _animacion=1;
            teclaAnimacion=1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&teclaAnimacion!=2) {
            AndroideSprite.setPosition(x_coord+=0,y_coord+=120);
            _animacion=2;
            teclaAnimacion=2;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&teclaAnimacion!=3) {
            AndroideSprite.setPosition(x_coord-=150,y_coord+=0);
            _animacion=3;
            teclaAnimacion=3;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&teclaAnimacion!=4) {
            AndroideSprite.setPosition(x_coord+=150,y_coord+=0);
            _animacion=4;
            teclaAnimacion=4;
        }

            /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&teclaAnimacion!=5) {
            _disparo=true;
            bala.disparar(x_coord, y_coord,_animacion);
            teclaAnimacion=5;
        }*/


    _frame+=0.2;
    if(_frame>=4) {
        _frame=0;
        teclaAnimacion=0;
    }


    switch (_animacion) {
    case 1:
        AndroideSprite.setTextureRect(sf::IntRect(int(_frame)*136,272,120,120));
        break;
    case 2:
        AndroideSprite.setTextureRect(sf::IntRect(int(_frame)*136,408,120,120));
        break;
    case 3:
        AndroideSprite.setTextureRect(sf::IntRect(int(_frame)*136,0,120,120));
        break;
    case 4:
        AndroideSprite.setTextureRect(sf::IntRect(int(_frame)*136,136,120,120));
        break;
    case 5:
        break;
    }
}


void Androide::draw(sf::RenderTarget& target,sf::RenderStates states)const {

    target.draw(AndroideSprite, states);
}

sf::FloatRect Androide::getBounds() const{
return AndroideSprite.getGlobalBounds();
}


