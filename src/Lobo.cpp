#include "Lobo.h"

Lobo::Lobo(std::string name, const Sprite &s, int posL, int posC):Personagem(name,s,posL,posC){
    setAcao("ataque");
    setVira_Lobo(true);
}

Lobo::Lobo(std::string name, const SpriteAnimado &s, int posL, int posC):Personagem(name,s,posL,posC){
    setAcao("ataque"); 
    setVira_Lobo(true);
}

int Lobo::atacar(array<Personagem*,10>&Per){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> var(0,Per.size()-1);

    int atacado,tentativa=9;
    
    do{
        atacado = var(generator);
        tentativa--;
    }while((!Per[atacado]->isalive()||(Per[atacado]->getAcao()=="ataque" && Per[atacado]->getVira_Lobo()==true))&& tentativa>0);
    
    if(tentativa==0){
        return -1;
    }

    return atacado;
}

string Lobo::acao_noturna(){

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> var(0,7);
    int choice;

    choice = var(generator);

    if(choice == 0){
        return "                                         Ca entre nos...                          Nao podemos esperar nada de bom...";
    }
    else if(choice == 1){
        return "Cuidado...                               Se correr o bixo pega...                  Se fica o bixo come...";
    }
    else if(choice == 2){
        return "                                         Prefiro nem comentar...";
    }
    else if(choice==3){
        return "                                         Eu tenho e medo do que pode ter feito...";
    }
    else if(choice==4){
        return "                                         Edward ou Jacob? Fica ai o questionamento";
    }
    else if(choice==5){
        return "Opa, ja e dia?                           Dormi e perdi informacoes                Agora so amanha ~8~";
    }
    else if(choice==6){
        return "                                         Hoje serei apenas silencio...";
    }
    return "                                         Remus Lupin...                           Conhece?";


}