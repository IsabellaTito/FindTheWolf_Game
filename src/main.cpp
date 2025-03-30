#include <iostream>
#include <string>

#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteBuffer.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/input/Keyboard.hpp"
#include "Cursor.h"
#include "Fase1.h"
#include "Game.hpp"

using std::cout, std::endl, std::string, std::cin;

int main()
{

	Game::run();


	//SpriteBuffer screen(96,31);

	//Fase1 f1("fase_jogo",Sprite("rsc/cenario.txt"));

	//f1.init();
	//f1.run(screen);

	/*
	SpriteBuffer screen(64,44);

	//Sprite Guru("rsc/Guru.txt",COR::AZUL), cenario("rsc/cenario.txt");

	Sprite cenario("rsc/cenario.txt");

	Guru guru("Guru", Sprite("rsc/Guru.txt",COR::AZUL),1,5);

	Cursor cursor("cursor", Sprite("rsc/cursor.txt"),1,5);

	SpriteAnimado ald1("rsc/Aldeao1.txt",3,COR::VERDE), ald2("rsc/Aldeao2.txt",3,COR::VERMELHA), ald3("rsc/Aldeao3.txt",3,COR::MAGENTA);
	SpriteAnimado ald4("rsc/Aldeao4.txt",3,COR::VERDE), ald5("rsc/Aldeao5.txt",3,COR::VERMELHA), ald6("rsc/Aldeao6.txt",3,COR::MAGENTA);
	SpriteAnimado ald7("rsc/Aldeao7.txt",3,COR::VERDE), ald8("rsc/Aldeao8.txt",3,COR::VERMELHA), ald9("rsc/Aldeao9.txt",3,COR::MAGENTA);

	Keyboard::setMode(Keyboard::NONBLOCKING);

	while(true){
		char str=Keyboard::read();

		if(str=='d' && cursor.getPosC()<43){
			cursor.moveRight(19);
		}
		else if(str=='w' && cursor.getPosL()>2){
			cursor.moveUp(10);
		}
		else if(str=='s' && cursor.getPosL()<21){
			cursor.moveDown(10);
		}
		else if(str=='a' && cursor.getPosC()>5){
			cursor.moveLeft(19);
		}
		else if (str=='q'){
			break;
		}

		screen.clear();

		cenario.draw(screen,0,0);

		cursor.draw(screen, cursor.getPosL(), cursor.getPosC());

		ald1.draw(screen,3,8);

		ald2.draw(screen,13,45);

		ald3.draw(screen,3,26);

		ald4.draw(screen,22,26);

		ald5.draw(screen,13,8);

		ald6.draw(screen,23,44);

		ald7.draw(screen,23,7);

		ald8.draw(screen,12,26);

		ald9.draw(screen,2,46);

		guru.draw(screen,33,50);

		ald1.update();
		ald2.update();
		ald3.update();
		ald4.update();
		ald5.update();
		ald6.update();
		ald7.update();
		ald8.update();
		ald9.update();

		system("clear");

		cout << screen;

		system("sleep 0.3");
	}
	*/

	
	return 0;
}