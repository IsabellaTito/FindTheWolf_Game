#include "Aldeao.h"

Aldeao::Aldeao(std::string name, const Sprite &s, int posL, int posC):Personagem(name,s,posL,posC){
    setAcao("sobreviver");
}
Aldeao::Aldeao(std::string name, const SpriteAnimado &s, int posL, int posC):Personagem(name,s,posL,posC){
    setAcao("sobreviver");
}

string Aldeao::acao_noturna(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> var(0,5);
    int choice;

    choice = var(generator);

    if(choice == 0){
        return "                                         Iiiih coitado...                         Nao machuca nem uma mosca";
    }
    else if(choice == 1){
        return "                                         Me disseram que...                       Esta sempre de guarda tentando sobreviver";
    }
    else if(choice == 2){
        return "                                         Nao pode fazer muito, apenas esperar     que a salvacao caia do ceu";
    }
    else if(choice==3){
        return "                                         Pobre coitado...";
    }
    else if(choice==4){
        return "Opa, ja e dia?                           Dormi e perdi informacoes                Agora so amanha ~8~";
    }
    return "                                         Soube que...                             Luta ate o ultimo homem!";
}