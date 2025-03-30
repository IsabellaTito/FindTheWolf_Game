#ifndef FASEMENU_HPP
#define FASEMENU_HPP

#include "../ASCII_Engine/SpriteBuffer.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/Fase.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/input/Keyboard.hpp"

class FaseMenu : public Fase
{
public:
	FaseMenu(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseMenu(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseMenu(){}
	
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
	
private:
	ObjetoDeJogo *pSelE,*pSelD;
	unsigned op;
};

#endif // FASEMENU_HPP
