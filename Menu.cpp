#include "Menu.h"


Menu::Menu() {
    TexturaMenu.loadFromFile("assets/imagenes/menu.png");
    SpriteMenu.setTexture(TexturaMenu);
    TexturaBotonMenu.loadFromFile("assets/imagenes/botones.png");
    SpriteBotonMenu.setTexture(TexturaBotonMenu);
    musicaMenu.openFromFile("assets/Musica/MusicaMenu.wav");
    musicaplay.openFromFile("assets/Musica/Cancion2.wav");
}

int Menu::abrirMenu(sf::RenderWindow &window){
   musicaMenu.play();
    int cursor=360;
    int ejeY=0;
    int teclaAnimacion;
    float _frame=0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        window.draw(SpriteMenu);


        SpriteBotonMenu.setTextureRect(sf::IntRect(0,0,380,70)); //jugar
        SpriteBotonMenu.setPosition(50, 360);
        window.draw(SpriteBotonMenu);

        SpriteBotonMenu.setTextureRect(sf::IntRect(0,75,380,70));  //salir
        SpriteBotonMenu.setPosition(50, 460);
        window.draw(SpriteBotonMenu);

        SpriteBotonMenu.setTextureRect(sf::IntRect(0,150,380,70));  //creditos
        SpriteBotonMenu.setPosition(50, 560);
        window.draw(SpriteBotonMenu);

        SpriteBotonMenu.setTextureRect(sf::IntRect(385,ejeY,380,70)); //luz
        SpriteBotonMenu.setPosition(50, cursor);
        window.draw(SpriteBotonMenu);



        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&teclaAnimacion!=1) {
            if(cursor==360) {
                cursor=560;
                ejeY=150;
                teclaAnimacion=1;
            } else {
                if(cursor==460) {
                    cursor=360;
                    ejeY=0;
                    teclaAnimacion=1;
                } else {
                    if(cursor==560) {
                        cursor=460;
                        ejeY=75;
                        teclaAnimacion=1;
                    }
                }
            }
        };

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&teclaAnimacion!=2) {
            if(cursor==360) {
                cursor=460;
                ejeY=75;
                teclaAnimacion=2;
            } else {
                if(cursor==460) {
                    cursor=560;
                    ejeY=150;
                    teclaAnimacion=2;
                } else {
                    if(cursor==560) {
                        cursor=360;
                        ejeY=0;
                        teclaAnimacion=2;
                    }
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if(cursor==360) {
                musicaMenu.stop();
                musicaplay.play();
                return 1;
                if(cursor==460) {

                    return 2;
                }
            }
            if(cursor==560) {

                return 3;
            }
        }

        _frame+=0.25;
        if(_frame>=3) {
            _frame=0;
            teclaAnimacion=0;
        }

    window.draw(SpriteBotonMenu);
        window.display();

    }

    }


