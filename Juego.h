#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Androide.h"
#include "Zombi.h"
#include "Menu.h"
#include <list>


class Juego{
private:
    sf::RenderWindow window;
    sf::Texture TexturaMenu, TexturaBotonMenu;
    sf::Sprite SpriteMenu, SpriteBotonMenu;
    sf::Texture TexturaBackground, TexturaBackgroundEfecto;
    sf::Sprite SpriteBackground, SpriteBackgroundEfecto;
    Androide _Protagonista;
    std::list <Zombie> listaZombies;
    float _frame;

public:
    Juego();
    int menu();
    void run();
    void init();
    void update();
    void draw();
    void GenerarZombies();
};

#endif // JUEGO_H_INCLUDED
