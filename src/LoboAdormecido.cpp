#include "LoboAdormecido.h"

LoboAdormecido::LoboAdormecido(std::string name, const Sprite &s, int posL, int posC):Lobo(name,s,posL,posC){
    setVira_Lobo(false);
}

LoboAdormecido::LoboAdormecido(std::string name, const SpriteAnimado &s, int posL, int posC):Lobo(name,s,posL,posC){
    setVira_Lobo(false);
}

string LoboAdormecido::acao_noturna(){

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> var(0,7);
    int choice;

    choice = var(generator);

    if(getVira_Lobo()){
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
            return "                                         Edward ou Jacob? Fica ai o misterio";
        }
        else if(choice==5){
            return "Opa, ja e dia?                           Dormi e perdi informacoes                Agora so amanha ~8~";
        }
        else if(choice==6){
            return "                                         Hoje serei apenas silencio...";
        }
        return "Remus Lupin...                           Conhece?";
    }
    
    if(choice==0){
        return "                                         Dizem as mas linguas que...              Existe uma luta entre o bem e o mal...";
    }
    else if(choice==1){
        return "Sao sorrateiros, muita atencao!!         Quando voce menos esperar...                          ~ja foi~";
    }
    else if(choice == 2){
        return "A vinganca pode transformar qualquer     mocinho em vilao...";
    }
    else if(choice == 3){
        return "                                         A ignorancia e uma dadiva...             Prefiro nao falar nada...";
    }
    else if(choice == 4){
        return "                                         Lobo em pele de cordeiro...              So precisa acordar";
    }
    else if(choice == 5){
        return "Tira casaco, coloca casaco               Tira casaco, coloca casaco               Tira casaco, coloca casaco";
    }
    else if(choice == 6){
        return "                                         Hoje eu sou apenas misterio...";
    }
    return "Opa, ja e dia?                           Dormi e perdi informacoes                Agora so amanha ~8~";
        
}