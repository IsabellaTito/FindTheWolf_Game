#ifndef FASEGAMEOVER_HPP
#define FASEGAMEOVER_HPP

#include "../ASCII_Engine/SpriteBuffer.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/Fase.hpp"
#include "../ASCII_Engine/input/Keyboard.hpp"

class FaseGameOver : public Fase
{
public:
	FaseGameOver(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseGameOver(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseGameOver(){}
	
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:
	//unsigned op;

};
#endif // FASEGAMEOVER_HPP