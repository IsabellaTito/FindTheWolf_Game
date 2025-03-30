#pragma once

#include "Personagem.h"
#include <string>

using std::string;

class Aldeao : public Personagem{
    public:
        Aldeao(std::string name, const Sprite &s, int posL, int posC);
        Aldeao(std::string name, const SpriteAnimado &s, int posL, int posC);
        string acao_noturna();

};