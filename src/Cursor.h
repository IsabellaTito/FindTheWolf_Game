#pragma once

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

class Cursor : public ObjetoDeJogo{
    public:
        Cursor(std::string name, const Sprite &s, int posL, int posC): ObjetoDeJogo(name,s,posL,posC), cursor_pos{0}{}

        void setCursor_pos(int p){cursor_pos = p;}
        int getCursor_pos() const {return cursor_pos;}

    private:
        int cursor_pos;
};


