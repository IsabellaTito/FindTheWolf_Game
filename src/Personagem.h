#pragma once

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/TextContainer.hpp"

#include <string>
#include <random>
#include <chrono>

using std::string;

class Personagem : public ObjetoDeJogo{
    public:
        Personagem(std::string name, const Sprite &s, int posL, int posC):ObjetoDeJogo(name,s,posL,posC),vida{true},cura{false},virou_lobo{false}{}

        Personagem(std::string name, const SpriteAnimado &s, int posL, int posC):ObjetoDeJogo(name,s,posL,posC),vida{true},cura{false},virou_lobo{false}{}
        
        ~Personagem(){}

        virtual string acao_noturna(){return "";}

        void setAcao(string ac){acao=ac;}
        string getAcao()const{return acao;}

        void setVida(bool v){vida=v;}
        bool isalive()const{return vida;}

        void setCura(bool C){cura=C;}
        bool getCura()const{return cura;}

        bool getVira_Lobo()const{return virou_lobo;}
        void setVira_Lobo(bool l){virou_lobo=l;}

        //void carregarFalas(string path){falasTC.addFromFile(path);}
        
    protected:

        bool vida;
        string acao;
        bool cura;
        bool virou_lobo;
        //TextContainer falasTC;

};