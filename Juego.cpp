#include "Juego.h"


Juego::Juego() {
    init();
}

void Juego::init() {
    window.create(sf::VideoMode(1000, 800), "The Last Shine");
    window.setFramerateLimit(30);

    TexturaBackground.loadFromFile("assets/imagenes/background1.png");
    SpriteBackground.setTexture(TexturaBackground);
    TexturaBackgroundEfecto.loadFromFile("assets/imagenes/background3.png");
    SpriteBackgroundEfecto.setTexture(TexturaBackgroundEfecto);
    SpriteBackgroundEfecto.setOrigin(635,635);
    SpriteBackgroundEfecto.setPosition(500,400);

    for(int x=0; x<10; x++) {
        ListaZombie[x]=zombie;
    }

    opcionMenu=menu.abrirMenu(window);
    switch(opcionMenu){
case 1:
    run();
break;
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
        Juego::draw();
        Juego::update();
    }


}

void Juego::draw() {

    window.clear();
    window.draw(SpriteBackground);
    window.draw(_Protagonista);

    _frames+=0.2;
    if(_frames>=10) {
        GenerarZombies();
        _frames=0;
    }


    for(int x=0; x<10; x++) {
        if(ListaZombie[x].muerto!=true) {
            window.draw(ListaZombie[x]);
        }
    }

    //SpriteBackgroundEfecto.setRotation(SpriteBackgroundEfecto.getRotation()+0.1);
    //window.draw(SpriteBackgroundEfecto);
    window.display();
}

void Juego::update() {
    _Protagonista.Update();

    for(int x=0; x<10; x++) {
        if(ListaZombie[x].muerto!=true) {
            ListaZombie[x].Update();
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
