#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Androide.h"
#include "Zombi.h"
#include "Menu.h"
#include "Disparo.h"
#include "Tutorial.h"



class Juego {
private:
    sf::RenderWindow window;
    sf::Texture TexturaBackground, TexturaBackgroundEfecto;
    sf::Sprite SpriteBackground, SpriteBackgroundEfecto;
    sf::Texture VidaTextura;
    sf::Sprite VidaSprite;
    sf::Texture PausaTextura, TexturaGameover;
    sf::Sprite PausaSprite, SpriteGameOver;
    sf::Texture TexturaBotonGameOver;
    sf::Sprite SpriteBotonGameOver;
    sf::Color transparencia;


    Androide _Protagonista;
    float tiempog;
    Zombie zombie;
    Zombie ListaZombie[10];
    Disparo bala;
    Disparo ListaBala[10];
    Menu menu;
    Tutorial tutorial;
    int opcionMenu;
    int y_coorVida;

public:
    Juego();
    void run();
    void init();
    void update();
    void draw();
    void GenerarZombies();
    void GenerarDisparo(sf::Vector2i coordenadas, int direccion);
    void AbrirMenu();
    void pausa();
    bool GameOver();
};

#endif // JUEGO_H_INCLUDED
