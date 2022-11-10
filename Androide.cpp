#include "Androide.h"

Androide::Androide() {
    AndroideTextura.loadFromFile("assets/imagenes/androide.png");
    AndroideSprite.setTexture(AndroideTextura);
    Androide::init();
    rojo.r=255;
}

void  Androide::init() {
    x_coord=440, y_coord=340;
    AndroideSprite.setTextureRect(sf::IntRect(0,0,120,120));
    AndroideSprite.setPosition(x_coord,y_coord);
    tiempoEspera=0;
    _animacion=2;
    _posicion=2;
    estadoGolpeado=0;
    golpeado=false;
    colordefault=AndroideSprite.getColor();
}



void Androide::Update() {
    if(golpeado==true) {
        AndroideSprite.setColor(rojo);
        estadoGolpeado++;
    }

    if(estadoGolpeado>=5) {
        golpeado=false;
        estadoGolpeado=0;
        AndroideSprite.setColor(colordefault);
    }



    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&espera==false) {
        if(y_coord==220) {
            AndroideSprite.setPosition(x_coord+=0,y_coord+=0);
            _animacion=1;
            _posicion=1;
            espera=true;
        } else {
            AndroideSprite.setPosition(x_coord+=0,y_coord-=120);
            _animacion=1;
            _posicion=1;
            espera=true;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&espera==false) {
        if(y_coord==460) {
            AndroideSprite.setPosition(x_coord+=0,y_coord+=0);
            _animacion=2;
            _posicion=2;
            espera=true;
        } else {
            AndroideSprite.setPosition(x_coord+=0,y_coord+=120);
            _animacion=2;
            _posicion=2;
            espera=true;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&espera==false) {
        if(x_coord==290) {
            AndroideSprite.setPosition(x_coord+=0,y_coord+=0);
            _animacion=3;
            _posicion=3;
            espera=true;
        } else {
            AndroideSprite.setPosition(x_coord-=150,y_coord+=0);
            _animacion=3;
            _posicion=3;
            espera=true;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&espera==false) {
        if(x_coord==590) {
            AndroideSprite.setPosition(x_coord+=0,y_coord+=0);
            _animacion=4;
            _posicion=4;
            espera=true;
        } else {
            AndroideSprite.setPosition(x_coord+=150,y_coord+=0);
            _animacion=4;
            _posicion=4;
            espera=true;
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&espera==false) {
        disparar=true;
        espera=true;
        _animacion=5;
    }


    _frame+=0.2;
    if(_frame>=4) {
        _frame=0;
    }

    tiempoEspera+=0.2;
    if(tiempoEspera>=2) {
        espera=false;
        tiempoEspera=0;
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

        if(_posicion==1) {
            AndroideSprite.setTextureRect(sf::IntRect(int(_frame)*136+544,272,120,120));
        }
        if(_posicion==2) {
            AndroideSprite.setTextureRect(sf::IntRect(int(_frame)*136+544,408,120,120));
        }
        if(_posicion==3) {
            AndroideSprite.setTextureRect(sf::IntRect(int(_frame)*136+544,0,120,120));
        }
        if(_posicion==4) {
            AndroideSprite.setTextureRect(sf::IntRect(int(_frame)*136+544,136,120,120));
        }

        break;
    }
}


void Androide::draw(sf::RenderTarget& target,sf::RenderStates states)const {

    target.draw(AndroideSprite, states);
}

sf::Vector2i Androide::getposition() {
    sf::Vector2i coordenadas= {x_coord,y_coord};
    return coordenadas;
}

int Androide::getDireccion() {
    return _posicion;
}

sf::FloatRect Androide::getBounds() const {
    return AndroideSprite.getGlobalBounds();
}


