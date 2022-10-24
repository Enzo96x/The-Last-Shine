#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Androide.h"
#include "Zombi.h"

class Juego {
private:
    sf::RenderWindow window;
    sf::Texture TexturaBackground, TexturaBackgroundEfecto;
    sf::Sprite SpriteBackground, SpriteBackgroundEfecto;
    Androide _Protagonista;
    Zombie zombie;

public:
    Juego();
    void run();
    void init();
    void update();
    void draw();
    void menu();
};

#endif // JUEGO_H_INCLUDED
