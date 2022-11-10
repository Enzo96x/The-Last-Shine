#include "Zombi.h"
#include<time.h>

Zombie::Zombie() {
    ZombieTextura.loadFromFile("assets/imagenes/zombie.png");
    ZombieSprite.setTexture(ZombieTextura);
    ZombieSprite.setTextureRect(sf::IntRect(0,0,150,150));

}

void Zombie::init() {


    golpeado=false;
    ataco=false;
    srand(time(NULL));
    _direccion=rand()%4+1;
    _posicion=rand()%3+1;
    reiniciarframe=true;


    switch(_direccion) {
    case 1:
        if(_posicion==1) {
            x_coord=275;
            y_coord=-150;
            ZombieSprite.setPosition(x_coord,y_coord);
        };
        if(_posicion==2) {
            x_coord=425;
            y_coord=-150;
            ZombieSprite.setPosition(x_coord,y_coord);
        };
        if(_posicion==3) {
            x_coord=575;
            y_coord=-150;
            ZombieSprite.setPosition(x_coord,y_coord);
        };
        _animacion=1;
        break;
    case 2:
        if(_posicion==1) {
            x_coord=275;
            y_coord=800;
            ZombieSprite.setPosition(x_coord,y_coord);
        };
        if(_posicion==2) {
            x_coord=425;
            y_coord=800;
            ZombieSprite.setPosition(x_coord,y_coord);
        };
        if(_posicion==3) {
            x_coord=575;
            y_coord=800;
            ZombieSprite.setPosition(x_coord,y_coord);
        };
        _animacion=2;
        break;
    case 3:
        if(_posicion==1) {
            x_coord=-150;
            y_coord=200;
            ZombieSprite.setPosition(x_coord,y_coord);
        };
        if(_posicion==2) {
            x_coord=-150;
            y_coord=320;
            ZombieSprite.setPosition(x_coord,y_coord);
        };
        if(_posicion==3) {
            x_coord=-150;
            y_coord=440;
            ZombieSprite.setPosition(x_coord,y_coord);
        };
        _animacion=3;
        break;
    case 4:
        if(_posicion==1) {
            x_coord=1000;
            y_coord=200;
            ZombieSprite.setPosition(x_coord,y_coord);
        };
        if(_posicion==2) {
            x_coord=1000;
            y_coord=320;
            ZombieSprite.setPosition(x_coord,y_coord);
        }
        if(_posicion==3) {
            x_coord=1000;
            y_coord=440;
            ZombieSprite.setPosition(x_coord,y_coord);
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
    if(golpeado==true) {
        _animacion=5;
    }

    switch (_animacion) {
    case 1:
        //arriba
        if(y_coord>=140) {
            if(reiniciarframe==true) {
                _frame=0.2;
                reiniciarframe=false;
            }
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,900,150,150));
            if(_frame==0) {
                ataco=true;
                muerto=true;
            }
        } else {
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,300,150,150));
            ZombieSprite.setPosition(x_coord+=0,y_coord+=1.5);
        }
        break;
    case 2:
        //abajo
        if(y_coord<=500) {
            if(reiniciarframe==true) {
                _frame=0.2;
                reiniciarframe=false;
            }
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,1050,150,150));
            if(_frame==0) {
                ataco=true;
                muerto=true;
            }
        } else {
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,450,150,150));
            ZombieSprite.setPosition(x_coord+=0,y_coord-=1.5);
        }
        break;
    case 3:
        //izquierda
        if(x_coord>=195) {
            if(reiniciarframe==true) {
                _frame=0.2;
                reiniciarframe=false;
            }
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,750,150,150));
            if(_frame==0) {
                ataco=true;
                muerto=true;
            }
        } else {
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,150,150,150));
            ZombieSprite.setPosition(x_coord+=1.5,y_coord+=0);
        }
        break;
    case 4:
        //derecha
        if(x_coord<=645) {
            if(reiniciarframe==true) {
                _frame=0.2;
                reiniciarframe=false;
            }
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,600,150,150));
            if(_frame==0) {
                ataco=true;
                muerto=true;
            }
        } else {
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,0,150,150));
            ZombieSprite.setPosition(x_coord-=1.5,y_coord+=0);
        }
        break;
    case 5:
        if(_direccion==1) {//arriba
            if(reiniciarframe==true) {
                _frame=0.2;
                reiniciarframe=false;
            }
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,1500,150,150));
        }
        if(_direccion==2) {//abajo
            if(reiniciarframe==true) {
                _frame=0.2;
                reiniciarframe=false;
            }
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,1650,150,150));
        }
        if(_direccion==3) {//izquierda
            if(reiniciarframe==true) {
                _frame=0.2;
                reiniciarframe=false;
            }
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,1350,150,150));
        }
        if(_direccion==4) {//derecha
            if(reiniciarframe==true) {
                _frame=0.2;
                reiniciarframe=false;
            }
            ZombieSprite.setTextureRect(sf::IntRect(0+int(_frame)*150,1200,150,150));
        }
        if(_frame==0) {
            muerto=true;
        }
        break;
    }
}






void Zombie::draw(sf::RenderTarget& target,sf::RenderStates states)const {

    target.draw(ZombieSprite, states);
}

sf::FloatRect Zombie::getBounds() const {
    return ZombieSprite.getGlobalBounds();
}
