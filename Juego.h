#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Androide.h"
#include "Zombi.h"
#include "Menu.h"



class Juego{
private:
    sf::RenderWindow window;
    sf::Texture TexturaBackground, TexturaBackgroundEfecto;
    sf::Sprite SpriteBackground, SpriteBackgroundEfecto;
    Androide _Protagonista;
    float _frames;
    Zombie zombie;
    Zombie ListaZombie[10];
    Menu menu;
    int opcionMenu;

public:
    Juego();
    void run();
    void init();
    void update();
    void draw();
    void GenerarZombies();
};

#endif // JUEGO_H_INCLUDED
