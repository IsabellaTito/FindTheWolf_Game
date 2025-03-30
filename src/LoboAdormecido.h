#pragma once

#include "Lobo.h"
#include <string>

using std::string;

class LoboAdormecido : public Lobo{
    public:
    LoboAdormecido(std::string name, const Sprite &s, int posL, int posC);

    LoboAdormecido(std::string name, const SpriteAnimado &s, int posL, int posC);
    string acao_noturna();
    
};

