#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Menu {
private:
    sf::Music musicaMenu;
    sf::Music musicaplay;
    sf::Texture TexturaMenu, TexturaBotonMenu;
    sf::Sprite SpriteMenu, SpriteBotonMenu;
public:
    Menu();
    int abrirMenu(sf::RenderWindow &window);
};

#endif // MENU_H_INCLUDED
