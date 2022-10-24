#include "Zombi.h"
#include<time.h>


Zombie::Zombie() {
    ZombieTextura.loadFromFile("assets/imagenes/zombie.png");
    ZombieSprite.setTexture(ZombieTextura);
    ZombieSprite.setTextureRect(sf::IntRect(0,0,150,150));

    srand(time(NULL));
    _direccion=rand()%4+1;
    _posicion=rand()%3+1;



    switch(_direccion) {
    case 1:
        if(_posicion==1) {
            ZombieSprite.setPosition(275,-150);
        };
        if(_posicion==2) {
            ZombieSprite.setPosition(425,-150);
        };
        if(_posicion==3) {
            ZombieSprite.setPosition(575,-150);
        };
        _animacion=1;
        break;
    case 2:
        if(_posicion==1) {
            ZombieSprite.setPosition(275,800);
        };
        if(_posicion==2) {
            ZombieSprite.setPosition(425,800);
        };
        if(_posicion==3) {
            ZombieSprite.setPosition(575,800);
        };
        _animacion=2;
        break;
    case 3:
        if(_posicion==1) {
            ZombieSprite.setPosition(-150,200);
        };
        if(_posicion==2) {
            ZombieSprite.setPosition(-150,320);
        };
        if(_posicion==3) {
            ZombieSprite.setPosition(-150,440);
        };
        _animacion=3;
        break;
    case 4:
        if(_posicion==1) {
            ZombieSprite.setPosition(1000,200);
        };
        if(_posicion==2) {
            ZombieSprite.setPosition(1000,320);
        };
        if(_posicion==3) {
            ZombieSprite.setPosition(1000,440);
        };
        _animacion=4;
        break;
    }



}




void Zombie::Update() {

    _frame+=0.2;
    if(_frame>=6) {
        _frame=0;
    }

    switch (_animacion) {
    case 1:
        //arriba
        ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,300,150,150));
        ZombieSprite.move(0,1.5);
        break;
    case 2:
        //abajo
        ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,450,150,150));
        ZombieSprite.move(0,-1.5);
        break;
    case 3:
        //izquierda
        ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,150,150,150));
        ZombieSprite.move(1.5,0);
        break;
    case 4:
        //derecha
        ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,0,150,150));
        ZombieSprite.move(-1.5,0);
        break;
    case 5:
        break;
    }
}


void Zombie::draw(sf::RenderTarget& target,sf::RenderStates states)const {

    target.draw(ZombieSprite, states);
}

