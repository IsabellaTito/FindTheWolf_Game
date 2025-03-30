#include "../ASCII_Engine/TextSprite.hpp"
#include "../ASCII_Engine/Sound.hpp"
#include "FaseMenu.hpp"
#include <string>
#include <iostream>

void FaseMenu::init()
{
	//crio objetos de jogo aqui

	objs.push_back(new ObjetoDeJogo("Fundo",Sprite("rsc/Menu_bckg.txt"),0,0));
	objs.push_back(new ObjetoDeJogo("Titulo",Sprite("rsc/Titulo.txt"),1,14));
	objs.push_back(new ObjetoDeJogo("Lobo_ini",SpriteAnimado("rsc/LoboCapa.txt",3),16,0));
	//objs.push_back(new ObjetoDeJogo("TextGame",TextSprite("The ASCII Rescue Game"),20,68));
	objs.push_back(new ObjetoDeJogo("Text----",TextSprite("-----------------------"),15,38)); //21,67
	objs.push_back(new ObjetoDeJogo("MenuOp1",TextSprite("Start Game"),17,45)); //23,74
	objs.push_back(new ObjetoDeJogo("MenuOp2",TextSprite("Help"),19,48)); //25,77
	objs.push_back(new ObjetoDeJogo("MenuOp3",TextSprite("Sair"),21,48)); //27,77
	
	objs.push_back(new ObjetoDeJogo("SelOpE",TextSprite("---->"),17,37)); //23,66
	pSelE = objs.back();
	objs.push_back(new ObjetoDeJogo("SelOpD",TextSprite("<----"),17,58)); //23,87
	pSelD = objs.back();
	
	op = Fase::OP_1;

}

unsigned FaseMenu::run(SpriteBuffer &screen)
{
	Keyboard::setMode(Keyboard::NONBLOCKING);

	char ent;
	
	//Sound backMusic("rsc/sounds/Techno2.mp3");
	//backMusic.playloop();
	
	system("clear");
	this->draw(screen);
	this->show(screen);
	
	while (true)
	{
		ent=Keyboard::read();
		//logica da fase acontece aqui
		//getline(std::cin,ent);
		if (ent == 'q') break;
		else if (ent == 's') {
			op = Fase::OP_1 + (op - Fase::OP_1  + 1) % 3;
			
			pSelE->moveTo(17 + (op - Fase::OP_1) * 2, 37);
			pSelD->moveTo(17 + (op - Fase::OP_1) * 2, 58);
		}
		else if (ent == 'w') {
			op = Fase::OP_1 + (3 + ((op - Fase::OP_1) - 1)) % 3;
			
			pSelE->moveTo(17 + (op - Fase::OP_1) * 2, 37);
			pSelD->moveTo(17 + (op - Fase::OP_1) * 2, 58);
		}
		else if (ent == 'x')
		{
			//backMusic.stop();
			return op;
		}
			
		
		system("clear");
		this->update();
		this->draw(screen);
		this->show(screen);
		
		system("sleep .2");
	}
	//backMusic.stop();
	return Fase::END_GAME;
}
