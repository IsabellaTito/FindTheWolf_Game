#pragma once

//randomização
#include <random>
#include <chrono>

//Dicionário e array
#include <map>
#include <array>

#include <iostream>
#include <string>

#include "../ASCII_Engine/Fase.hpp"
#include "../ASCII_Engine/input/Keyboard.hpp"
#include "../ASCII_Engine/Sound.hpp"
#include "Personagem.h"
#include "Aldeao.h"
#include "Lobo.h"
#include "LoboAdormecido.h"
#include "Medico.h"
#include "Cursor.h"
#include "Texto.hpp"

using std::string, std::to_string, std::array, std::iostream, std::map, std::pair, std::cout, std::cin, std::endl;

class Fase1 : public Fase{
    public:

        Fase1(string name, const Sprite &bkg) : Fase(name,bkg){}
        Fase1(string name, const SpriteAnimado &bkg) : Fase(name,bkg){}
        virtual ~Fase1(){}

        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);

        int verificaPerAtivos();

        int verificaLobos();

        void Night();

        void setPosicao(){
            posicoes[0] = {4,7};
            posicoes[1] = {4,23};
            posicoes[2] = {3,41};
            posicoes[3] = {4,58};
            posicoes[4] = {4,78};
            posicoes[5] = {14,7};
            posicoes[6] = {13,23};
            posicoes[7] = {14,41};
            posicoes[8] = {13,58};
            posicoes[9] = {14,78};
        }

        void setCores(){
            cores[0] = COR::VERDE;
            cores[1] = COR::VERMELHA;
            cores[2] = COR::AMARELA;
            cores[3] = COR::ROSA;
            cores[4] = COR::CINZA;
            cores[5] = COR::CIANO;
            cores[6] = COR::ROSA;
            cores[7] = COR::MAGENTA;
            cores[8] = COR::BRANCA;
            cores[9] = COR::AMARELA; 
        }

    
    private:
        
        map<int,pair<int,int>>posicoes;
        map<int,const char*>cores;  
        array<Personagem*,10>Personagens;
        int ind_lobo,ind_la1,ind_la2,ind_medico;
        ObjetoDeJogo *Guru;
        Cursor *cursor;
        int salvo, atacadoL, atacadoLA;
        Texto *Fala;
        ObjetoDeJogo *Caixa;

};
