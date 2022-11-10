#ifndef TUTORIAL_H_INCLUDED
#define TUTORIAL_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <cstring>

class Tutorial{
private:
    sf::Texture TexturaTutorial, TexturaBrian2077;
    sf::Sprite SpriteTutorial, SpriteBrian2077;
    float frame;
    sf::Font fuente;
    sf::Text textoTutorial;
    std::string dialogo1,dialogo2,dialogo3,dialogoAmostar;
    bool espera=true;
public:
    Tutorial();
    ~Tutorial();
    void abrirTutorial(sf::RenderWindow &window);
};

#endif // TUTORIAL_H_INCLUDED
