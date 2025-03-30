#include "Medico.h"

Medico::Medico(std::string name, const Sprite &s, int posL, int posC):Personagem(name,s,posL,posC){
    setAcao("salvar"); 
    //carregarFalas("../rsc/FalasMedico.txt");
}

Medico::Medico(std::string name, const SpriteAnimado &s, int posL, int posC):Personagem(name,s,posL,posC){
    setAcao("salvar");
    //carregarFalas("../rsc/FalasMedico.txt");
}

int Medico::salvar(array<Personagem*,10>&Per){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> var(0,Per.size()-1);
    int salvo,tentativa=9;

    do{
        salvo = var(generator);
        tentativa--;
    }while(!Per[salvo]->isalive() && tentativa>0);

    if(tentativa==0){
        return -1;
    }
    
    return salvo;
}

string Medico::acao_noturna(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> var(0,7);
    int choice;

    choice = var(generator);

    if(choice==0){
        return "                                         Ca entre nos...                          Uma luta constante contra o mal!";
    }
    else if(choice==1){
        return "                                         Um anjo em forma de pessoa";
    }
    else if(choice==2){
        return "                                         Iiiih coitado...                         Nao machuca nem uma mosca";
    }
    else if(choice==3){
        return "                                         Sem ele estava todo mundo perdido ";
    }
    else if(choice==4){
        return "                                         Dizem por ai que ele tem                  a salvacao para tudo";
    }
    else if(choice==5){
        return "                                         Hoje eu sou apenas misterio...";
    }
    else if(choice==6){
        return "                                         Soube que...                             Luta ate o ultimo homem!";
    }
    return "Opa, ja e dia?                           Dormi e perdi informacoes                Agora so amanha ~8~";

}