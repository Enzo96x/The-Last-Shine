#include "Juego.h"


Juego::Juego() {
    init();
    menu();
}

void Juego::init() {
    window.create(sf::VideoMode(1000, 800), "The Last Shine");
    window.setFramerateLimit(30);

    TexturaMenu.loadFromFile("assets/imagenes/menu.png");
    SpriteMenu.setTexture(TexturaMenu);
    TexturaBotonMenu.loadFromFile("assets/imagenes/botones.png");
    SpriteBotonMenu.setTexture(TexturaBotonMenu);

    TexturaBackground.loadFromFile("assets/imagenes/background1.png");
    SpriteBackground.setTexture(TexturaBackground);
    TexturaBackgroundEfecto.loadFromFile("assets/imagenes/background3.png");
    SpriteBackgroundEfecto.setTexture(TexturaBackgroundEfecto);
    SpriteBackgroundEfecto.setOrigin(635,635);
    SpriteBackgroundEfecto.setPosition(500,400);

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

int Juego::menu() {
    int x=50, y=360;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        window.draw(SpriteMenu);

        SpriteBotonMenu.setTextureRect(sf::IntRect(0,0,380,70));
        SpriteBotonMenu.setPosition(x, y);
        window.draw(SpriteBotonMenu);

        SpriteBotonMenu.setTextureRect(sf::IntRect(0,75,380,70));
        SpriteBotonMenu.setPosition(x, y+=100);
        window.draw(SpriteBotonMenu);

        SpriteBotonMenu.setTextureRect(sf::IntRect(0,150,380,70));
        SpriteBotonMenu.setPosition(x, y+=100);
        window.draw(SpriteBotonMenu);

        SpriteBotonMenu.setTextureRect(sf::IntRect(385,0,380,70));
        SpriteBotonMenu.setPosition(x, y-=200);
        window.draw(SpriteBotonMenu);

        /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if(y=360) {
                SpriteBotonMenu.setTextureRect(sf::IntRect(385,150,380,70));
                SpriteBotonMenu.setPosition(x, y+=200);
            };
            if(y=460) {
                SpriteBotonMenu.setTextureRect(sf::IntRect(385,0,380,70));
                SpriteBotonMenu.setPosition(x, y-=100);
            };
            if(y=560) {
                SpriteBotonMenu.setTextureRect(sf::IntRect(385,75,380,70));
                SpriteBotonMenu.setPosition(x, y-=100);
            };
            window.draw(SpriteBotonMenu);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if(y=360) {
                SpriteBotonMenu.setTextureRect(sf::IntRect(385,150,380,70));
                SpriteBotonMenu.setPosition(x, y-=200);
            };
            if(y=460) {
                SpriteBotonMenu.setTextureRect(sf::IntRect(385,150,380,70));
                SpriteBotonMenu.setPosition(x, y-=200);
            };
            if(y=560) {
                SpriteBotonMenu.setTextureRect(sf::IntRect(385,150,380,70));
                SpriteBotonMenu.setPosition(x, y-=200);
            };
            window.draw(SpriteBotonMenu);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

        }*/

        window.display();

    }

}

