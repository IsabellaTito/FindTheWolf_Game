#pragma once

#include "Personagem.h"
#include <string>
#include <array>

using std::string,std::array;

#include <random>
#include <chrono>

class Medico : public Personagem{
    public:
        Medico(std::string name, const Sprite &s, int posL, int posC);

        Medico(std::string name, const SpriteAnimado &s, int posL, int posC);

        string acao_noturna();

        int salvar(array<Personagem*,10>&Per);
};
