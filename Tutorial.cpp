#include "Tutorial.h"

Tutorial::Tutorial() {
TexturaTutorial.loadFromFile("assets/imagenes/tutorial.png");
SpriteTutorial.setTexture(TexturaTutorial);
TexturaBrian2077.loadFromFile("assets/imagenes/Brian2077.png");
SpriteBrian2077.setTexture(TexturaBrian2077);
SpriteBrian2077.setTextureRect(sf::IntRect(0,0, 240,270));
SpriteBrian2077.setPosition(34,495);
fuente.loadFromFile("meiryo.ttf");
textoTutorial.setFont(fuente);
textoTutorial.setPosition(290,530);
sf::Color color(150,215,245);
textoTutorial.setColor(color);
textoTutorial.setCharacterSize(25);

dialogo1="Despierta Androide n°26995 \nTienes una misión que cumplir\nSe te asigno el área 432, zona altamente radioactiva,\nlos mutantes siguen avanzando así que debes erradicarlos.\nContamos contigo.";
dialogo2="Estaras en el centro, desde ahí podrás aniquilar \na todo enemigo que se acerque.\nLos mutantes vendrán por las 4 direcciónes, \nintenta no quedar acorralado.\nPor qué si esto ocurre, te dañará y solo puedes soportar \nhasta 5 golpes de estas criaturas.";
dialogo3="Pulsa las teclas de direcciones para moverte\ny apuntar a tu objetivo\nPulsa D para disparar\nP para pausar\n\nBuena suerte en tu misión.";
dialogoAmostar=dialogo1;

}


void Tutorial::abrirTutorial(sf::RenderWindow &window) {

 while (window.isOpen()) {
    frame+=0.3;
 if(frame>=6) {
    frame=0;
    espera=false;
    }

SpriteBrian2077.setTextureRect(sf::IntRect(int(frame)*240,0,240,270));
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&&espera==false) {
            if(dialogoAmostar==dialogo1){dialogoAmostar=dialogo2;}
            else if(dialogoAmostar==dialogo2){dialogoAmostar=dialogo3;}
            else{return;}
            espera=true;
        }

        window.clear();
        window.draw(SpriteTutorial);
        window.draw(SpriteBrian2077);
        textoTutorial.setString(dialogoAmostar);
        window.draw(textoTutorial);


        window.display();

    }
}

Tutorial::~Tutorial(){
}
