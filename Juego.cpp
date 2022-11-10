#include "Juego.h"


Juego::Juego() {
    window.create(sf::VideoMode(1000, 800), "The Last Shine");
    window.setFramerateLimit(30);

    TexturaBackground.loadFromFile("assets/imagenes/background1.png");
    SpriteBackground.setTexture(TexturaBackground);
    TexturaBackgroundEfecto.loadFromFile("assets/imagenes/background3.png");
    SpriteBackgroundEfecto.setTexture(TexturaBackgroundEfecto);
    SpriteBackgroundEfecto.setOrigin(635,635);
    SpriteBackgroundEfecto.setPosition(500,400);


    VidaTextura.loadFromFile("assets/imagenes/vidas.png");
    VidaSprite.setTexture(VidaTextura);
    VidaSprite.setPosition(0,0);

    PausaTextura.loadFromFile("assets/imagenes/pausa.png");
    PausaSprite.setTexture(PausaTextura);

    TexturaGameover.loadFromFile("assets/imagenes/menugameover.png");
    SpriteGameOver.setTexture( TexturaGameover);
    TexturaBotonGameOver.loadFromFile("assets/imagenes/botonesgameover.png");
    SpriteBotonGameOver.setTexture(TexturaBotonGameOver);

    init();
}



void Juego::init() {
    y_coorVida=0;
    VidaSprite.setTextureRect(sf::IntRect(0,y_coorVida,275,76));
    transparencia.r=200;
    transparencia.b=200;
    transparencia.a=0;

    _Protagonista.init();
    for(int x=0; x<10; x++) {
        ListaZombie[x]=zombie;
        ListaBala[x]=bala;
    }

}

void Juego::run() {

    //game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            Juego::pausa();
        }

        if(y_coorVida==375) {
            if(GameOver()==false) {
                window.close();
                return;
            }
        };


        Juego::draw();
        Juego::update();
    }


}

void Juego::draw() {

    window.clear();
    window.draw(SpriteBackground);


    window.draw(_Protagonista);


    for(int x=0; x<10; x++) {
        if(ListaZombie[x].muerto!=true) {
            window.draw(ListaZombie[x]);
        }
    }

    for(int x=0; x<10; x++) {
        if(ListaBala[x].activo==true) {
            window.draw(ListaBala[x]);
        }
    }


    SpriteBackgroundEfecto.setColor(transparencia);
    SpriteBackgroundEfecto.setRotation(SpriteBackgroundEfecto.getRotation()+0.1);
    window.draw(SpriteBackgroundEfecto);
    window.draw(VidaSprite);
    window.display();
}

void Juego::update() {
    tiempog+=0.2;

    _Protagonista.Update();
    if(_Protagonista.disparar==true) {
        GenerarDisparo(_Protagonista.getposition(),_Protagonista.getDireccion());
        _Protagonista.disparar=false;
    }
    for(int x=0; x<10; x++) {
        if(ListaBala[x].activo==true) {
            ListaBala[x].update();
        }
    }


    if(tiempog>=10) {
        GenerarZombies();
        tiempog=0;
        //transparencia.a+=5;
    }


    for(int x=0; x<10; x++) {
        if(ListaZombie[x].muerto!=true) {
            ListaZombie[x].Update();

            if(ListaZombie[x].ataco==true) {
                VidaSprite.setTextureRect(sf::IntRect(0,y_coorVida+=75,275,76));
                _Protagonista.golpeado=true;
            }


            for(int y=0; y<10; y++) {
                if(ListaZombie[x].esColision(ListaBala[y])) {
                    ListaZombie[x].golpeado=true;
                    ListaBala[y].activo=false;
                }
            }
        }
    }

}


void Juego::GenerarZombies() {
    for(int x=0; x<10; x++) {
        if(ListaZombie[x].muerto==true) {
            ListaZombie[x].init();
            ListaZombie[x].muerto=false;
            return;
        }
    }
    return;
}

void Juego::GenerarDisparo(sf::Vector2i coordenadas, int direccion) {
    for(int x=0; x<10; x++) {
        if(ListaBala[x].activo==false) {
            ListaBala[x].activo=true;
            ListaBala[x].setcoordenadas(coordenadas, direccion);
            return;
        }

    }
    return;
}

void Juego::pausa() {
        int cont=0;
        bool esperar=true;

    while (window.isOpen()) {
        cont++;
        if(cont>=6) {cont=0;esperar=false;}
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(PausaSprite);
        window.display();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)&&esperar==false) {
            return;
        }

    }

}

bool Juego::GameOver() {
    int cursor=380;
    int ejeY=0;
    bool espera=false;
    float cont=0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        window.draw(SpriteGameOver);


        SpriteBotonGameOver.setTextureRect(sf::IntRect(0,0,380,70));
        SpriteBotonGameOver.setPosition(300, 380);
        window.draw(SpriteBotonGameOver);

        SpriteBotonGameOver.setTextureRect(sf::IntRect(0,75,380,70));
        SpriteBotonGameOver.setPosition(300, 480);
        window.draw(SpriteBotonGameOver);

        SpriteBotonGameOver.setTextureRect(sf::IntRect(385,ejeY,380,70));
        SpriteBotonGameOver.setPosition(300, cursor);
        window.draw(SpriteBotonGameOver);



        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&espera==false) {
            if(cursor==380) {
                cursor=480;
                ejeY=75;
            } else {
                if(cursor==480) {
                    cursor=380;
                    ejeY=0;
                }
            }
            espera=true;
        };

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&espera==false) {
            if(cursor==380) {
                cursor=480;
                ejeY=75;

            } else {
                if(cursor==480) {
                    cursor=380;
                    ejeY=0;
                }
            }
            espera=true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if(cursor==380) {
                Juego::init();
                return true;
            }
            if(cursor==480) {
                return false;
            }
        }

        cont+=0.25;
        if(cont>=3) {
            cont=0;
            espera=false;
        }

        window.draw(SpriteBotonGameOver);
        window.display();

    }
return true;
}


void Juego::AbrirMenu() {
    opcionMenu=menu.abrirMenu(window);

    switch(opcionMenu) {
    case 1:
        tutorial.abrirTutorial(window);
        Juego::run();
        break;
    case 2:

        return;
    case 3:
        return;
    }
}




