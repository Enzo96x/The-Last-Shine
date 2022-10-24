#include "Juego.h"


Juego::Juego() {
    init();
}

void Juego::init() {
    window.create(sf::VideoMode(1000, 800), "The Last Shine");
    window.setFramerateLimit(30);
    TexturaBackground.loadFromFile("assets/imagenes/backgroundprueba.png");
    SpriteBackground.setTexture(TexturaBackground);
    TexturaBackgroundEfecto.loadFromFile("assets/imagenes/background3.png");
    //SpriteBackgroundEfecto.setTexture(TexturaBackgroundEfecto);
    //SpriteBackgroundEfecto.setOrigin(635,635);
    //SpriteBackgroundEfecto.setPosition(500,400);

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
    window.draw(zombie);
    SpriteBackgroundEfecto.setRotation(SpriteBackgroundEfecto.getRotation()+0.1);
    window.draw(SpriteBackgroundEfecto);
    window.display();
}


void Juego::update() {
    _Protagonista.Update();
    zombie.Update();
}
