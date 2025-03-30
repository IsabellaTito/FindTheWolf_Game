#pragma once

#include "Personagem.h"
#include <string>
#include <array>

using std::string, std::array;

#include <random>
#include <chrono>


class Lobo : public Personagem{
    public:
        Lobo(std::string name, const Sprite &s, int posL, int posC);

        Lobo(std::string name, const SpriteAnimado &s, int posL, int posC);

        string acao_noturna();

        int atacar(array<Personagem*,10>&Per);

};