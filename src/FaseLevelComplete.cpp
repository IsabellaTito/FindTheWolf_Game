#include "../ASCII_Engine/TextSprite.hpp"
#include "../ASCII_Engine/Sound.hpp"
#include "FaseLevelComplete.hpp"
#include <string>
#include <iostream>

void FaseLevelComplete::init()
{
	//crio objetos de jogo aqui
	
	objs.push_back(new ObjetoDeJogo("contorno",Sprite("rsc/Menu_bckg.txt"),0,0));
	objs.push_back(new ObjetoDeJogo("Noite",SpriteAnimado("rsc/noite.txt",3,COR::AZUL),5,3));
	//objs.push_back(new ObjetoDeJogo("Text----",TextSprite("-----------------------"),21,67));
	objs.push_back(new ObjetoDeJogo("lobinho",SpriteAnimado("rsc/lobinho.txt",3),25,42));
    objs.push_back(new ObjetoDeJogo("uivo",Sprite("rsc/uivo.txt"),15,53));
    objs.push_back(new ObjetoDeJogo("mensagem",Sprite("rsc/LevelComplete.txt"),1,1));

}

unsigned FaseLevelComplete::run(SpriteBuffer &screen)
{
	Keyboard::setMode(Keyboard::NONBLOCKING);

	char ent;
	
	//Sound backMusic("rsc/sounds/Cave.mp3");
	//backMusic.playloop();
	
	system("clear");
	this->draw(screen);
	this->show(screen);

	ObjetoDeJogo* obj;
	auto it = objs.begin();

	std::advance(it,3);
	obj = *it;
    obj->desativarObj();

	std::advance(it,1);
	obj = *it;
    obj->desativarObj();

    int conte=0;

	
	while (true)
	{ conte++;
		ent=Keyboard::read();
	
		if (ent == 'q') break;
		else if (ent == 'x')
		{
			//backMusic.stop();
			return Fase::MENU;
		}

        if(conte==27){
			auto it = objs.begin();
			std::advance(it,2);

			obj = *it;

            obj->desativarObj();

			std::advance(it,1);

			obj = *it;

			obj->ativarObj();

            conte++;
        }
        else if(conte==33){
			auto it = objs.begin();
			std::advance(it,0);
			obj = *it;
            obj->desativarObj();

			std::advance(it,1);
			obj = *it;
            obj->desativarObj();
			
			std::advance(it,2);
			obj = *it;
            obj->desativarObj();

			std::advance(it,1);
			obj = *it;
            obj->ativarObj();
        }			
		
		this->update();
		this->draw(screen);
		system("clear");
		this->show(screen);
		
		system("sleep .2");
	}
	
	//backMusic.stop();
	return Fase::END_GAME;
}