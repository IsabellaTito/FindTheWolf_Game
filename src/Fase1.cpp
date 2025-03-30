#include "Fase1.h"


void Fase1::init(){

    //Preenche todo o array com ponteiros null
    Personagens.fill(nullptr);
    setCores();
    setPosicao();

    //Sorteio e criação dos personagens
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> var(0,Personagens.size()-1);

    //Objetos de Jogo
    cursor = new Cursor("cursor", Sprite("rsc/cursor.txt"),2,3);
    objs.push_back(cursor);

    for(int i=0; i<Personagens.size();i++){
        int choice;
        do{
            choice = var(generator);
        }
        while(Personagens[choice]!=nullptr);

        if(i==0){
            Personagens[choice]= new Lobo("lobo",SpriteAnimado("rsc/Aldeao"+to_string(choice)+".txt",3,cores[choice]),posicoes[choice].first,posicoes[choice].second);
            ind_lobo = choice;
        }
        else if(i==1){
            Personagens[choice]= new LoboAdormecido("loboA1",SpriteAnimado("rsc/Aldeao"+to_string(choice)+".txt",3,cores[choice]),posicoes[choice].first,posicoes[choice].second);
            ind_la1=choice;
        }
        else if(i==2){
            Personagens[choice]= new LoboAdormecido("loboA2",SpriteAnimado("rsc/Aldeao"+to_string(choice)+".txt",3,cores[choice]),posicoes[choice].first,posicoes[choice].second);
            ind_la2=choice;
        }
        else if(i==3){
            Personagens[choice]= new Medico("medico",SpriteAnimado("rsc/Aldeao"+to_string(choice)+".txt",3,cores[choice]),posicoes[choice].first,posicoes[choice].second);
            ind_medico=choice;
        }
        else{
            Personagens[choice]= new Aldeao("Aldeao"+to_string(choice),SpriteAnimado("rsc/Aldeao"+to_string(choice)+".txt",3,cores[choice]),posicoes[choice].first,posicoes[choice].second);
        }
        objs.push_back(Personagens[choice]);
    }

    Guru = new ObjetoDeJogo("Guru", Sprite("rsc/Guru.txt",COR::AZUL),22,6);
    objs.push_back(Guru);

    Caixa = new ObjetoDeJogo("caixa", Sprite("rsc/caixa.txt",COR::BRANCA),23,14);
    objs.push_back(Caixa);

    Fala = new Texto("fala",TextSprite(""),24,17);
    objs.push_back(Fala);

}

unsigned Fase1::run(SpriteBuffer &screen){

    Keyboard::setMode(Keyboard::NONBLOCKING);

    Sound backMusic("rsc/sound/suspense-adventure-loop-positive-cartoon-music-249645.mp3");
    backMusic.playloop();

    //padrão
    screen.clear();
    draw(screen);
    system("clear");
    show(screen);

    int conte = 0, conte2=0, noite_passada = Personagens.size(),veri,curioso=0;
    char str;
    bool sair = false, apareceu=true, passou_noite = false;

    while(true){ //Para poder chamar a noite e não jogar sozinho

        conte++;
        conte2=0;

        while(true){ //Permite o jogador ter tempo de fazer suas escolhas

            conte2++;

            //leitura da entrada
            str=Keyboard::read();

            if(verificaPerAtivos()<2 && verificaLobos()>0){
                return Fase::GAME_OVER;
            }
            

            /*
            if(noite_passada == verificaPerAtivos() && conte > 2 && conte2 < 5){
                Fala->colocarFrase("Nada aconteceu essa noite!");
            }
            */
            
            //processamento das entradas
            if(str=='d' && cursor->getPosC()<75){
                cursor->moveRight(18);
                cursor->setCursor_pos(cursor->getCursor_pos()+1);
            }
            else if(str=='w' && cursor->getPosL()>2){
                cursor->moveUp(10);
                cursor->setCursor_pos(cursor->getCursor_pos()-5);
            }
            else if(str=='s' && cursor->getPosL()<11){
                cursor->moveDown(10);
                cursor->setCursor_pos(cursor->getCursor_pos()+5);
            }
            else if(str=='a' && cursor->getPosC()>3){
                cursor->moveLeft(18);
                cursor->setCursor_pos(cursor->getCursor_pos()-1);
            }
            else if(str=='x' && curioso<2 && Personagens[cursor->getCursor_pos()]->isalive()){ //saber informação
                Fala->colocarFrase(Personagens[cursor->getCursor_pos()]->acao_noturna());
                conte2=0; //Permitir que a informação fique por pelo menos 50 voltas até aparecer a msg de escolha para retirar
                curioso ++; //Para evitar mais de uma informação por noite 
            }
            else if(str=='e' && Personagens[cursor->getCursor_pos()]->isalive()){ //tirar da vila
                Personagens[cursor->getCursor_pos()]->setVida(false);
                Personagens[cursor->getCursor_pos()]->desativarObj();
                objs.push_back(new ObjetoDeJogo("morto"+to_string(cursor->getCursor_pos()),Sprite("rsc/Morto.txt",cores[cursor->getCursor_pos()]),posicoes[cursor->getCursor_pos()].first,posicoes[cursor->getCursor_pos()].second));
                
                if((cursor->getCursor_pos() == ind_la1 || cursor->getCursor_pos() == ind_la2 || cursor->getCursor_pos() == ind_lobo) && verificaLobos()==0){
                    return Fase::LEVEL_COMPLETE;
                }
                else{
                    Fala->colocarFrase("Vamos para mais um dia...");
                    break;
                }
            }
            /*
            else if (str=='n'){
                //ir para a noite
                Fala->colocarFrase("Vamos para mais uma noite...");
                break;
            }
            */
            else if(str=='q'){
                sair = true;
                break; 
            }

            if(curioso==2 && conte2>35){
                Fala->colocarFrase("Atencao!!                                 Hora de tirar alguem da vila...          ");
            }

            //padrão
            update();
            screen.clear();
            draw(screen);
            system("clear");
            show(screen);

            system("sleep 0.3");

        }

        //noite_passada = verificaPerAtivos();
        
        if(sair){
            return Fase::GAME_OVER;
        }

        Night();

        /*
            Keyboard::setMode(Keyboard::BLOCKING);
            
            cout << "Persongem salvo:" << salvo <<endl;
            cout << "Personagem atacado pelo lobo:" << atacadoL<<endl;
            cout << "Personagem atacado pelo lobo adormecido:" << atacadoLA<<endl;
            cin >> veri;

            Keyboard::setMode(Keyboard::NONBLOCKING);
        */

        curioso = 0; //para permitir apenas uma informação por noite
        //apareceu = true;
    }

    //padrão
    update();
    screen.clear();
    draw(screen);
    system("clear");
    show(screen);

    backMusic.stop();
    return Fase::MENU;
}

int Fase1::verificaPerAtivos(){
    int conte=0;

    for(int i=0;i<Personagens.size();i++){
        if(Personagens[i]->isalive()){
            conte++;
        }
    }
    return conte;
}

int Fase1::verificaLobos(){
    int conte=0;
    for(int i=0;i<Personagens.size();i++){
        if(Personagens[i]->isalive() && Personagens[i]->getVira_Lobo()){
            conte++;
        }
    }
    return conte;
}

void Fase1::Night(){

    Lobo *auxL=dynamic_cast<Lobo*>(Personagens[ind_lobo]);
    Medico *auxM=dynamic_cast<Medico*>(Personagens[ind_medico]);
    LoboAdormecido *auxLA1=dynamic_cast<LoboAdormecido*>(Personagens[ind_la1]);
    LoboAdormecido *auxLA2=dynamic_cast<LoboAdormecido*>(Personagens[ind_la2]);

    //Por segurança, caso algum dos dois não chame a função atacar
    //e não faça as verificações de retirada errado
    atacadoLA = -1;
    atacadoL = -1;
    salvo = -1;

    bool virou_LA1{false}, virou_LA2{false};


    //Médico escolhe quem vai salvar, se médico não tiver saido

    if(auxM && auxM->isalive()){
        salvo=auxM->salvar(Personagens);
        Personagens[salvo]->setCura(true);
    }

    //O lobo escolhe quem vai atacar, se não tiver saido
    if(auxL->isalive()){
        atacadoL = auxL->atacar(Personagens);
    }

    //verifica se algum dos lobos adormecidos viraram lobo, e caso sim, já sorteiam quem atacar
    if(auxLA1->isalive() && !auxLA2->isalive()){
        virou_LA1 = auxLA1->getVira_Lobo();
        if(virou_LA1){
            atacadoLA = auxLA1->atacar(Personagens);
        }
    }

    if(auxLA2->isalive() && !auxLA1->isalive()){
        virou_LA2 = auxLA2->getVira_Lobo();
        if(virou_LA2){
            atacadoLA = auxLA2->atacar(Personagens);
        }
    }
   
    //-----------VERIFICAÇÕES PARA RETIRADA DE PERSONAGENS:----------------
            
    if(atacadoL>=0 && atacadoLA>=0){ //se tanto o lobo quanto o lobo adormecido atacaram
        if(atacadoL == atacadoLA){ //verifica se eles atacaram o mesmo aldeão

            if((salvo>=0 && !Personagens[atacadoL]->getCura()) || (salvo==-1)){ // se alguém foi salvo, mas não foi o atacado ou se ngm foi salvo (salvo=-1)
                Personagens[atacadoL]->desativarObj(); //a sprit do aldeao atacado para de aparecer
                objs.push_back(new ObjetoDeJogo("morto"+to_string(atacadoL),Sprite("rsc/Morto.txt",cores[atacadoL]),posicoes[atacadoL].first,posicoes[atacadoL].second)); //Coloca no lugar da sprit desativada uma lapide
                Personagens[atacadoL]->setVida(false); //Aqui, o personagem não é mais acessado, não permitindo executar nenhuma função
            }
        
        }
        else{ //o atacado pelo lobo não ser o mesmo atacado pelo lobo adormecido

            if((salvo>=0 && !Personagens[atacadoL]->getCura()) || (salvo==-1)){ //verifica o atacado pelo lobo
                Personagens[atacadoL]->desativarObj(); 
                objs.push_back(new ObjetoDeJogo("morto"+to_string(atacadoL),Sprite("rsc/Morto.txt",cores[atacadoL]),posicoes[atacadoL].first,posicoes[atacadoL].second)); 
                Personagens[atacadoL]->setVida(false); 
            }

            if((salvo>=0 && !Personagens[atacadoLA]->getCura()) || (salvo==-1)){ //verifica o atacado pelo lobo adormecido
                Personagens[atacadoLA]->desativarObj(); 
                objs.push_back(new ObjetoDeJogo("morto"+to_string(atacadoLA),Sprite("rsc/Morto.txt",cores[atacadoLA]),posicoes[atacadoLA].first,posicoes[atacadoLA].second)); 
                Personagens[atacadoLA]->setVida(false); 
            }
        }
    }
    else if(atacadoL>=0){ //Se apenas o lobo tiver atacado. Ou pelo lobo adormecido não esta ativo ou por já ter saido da cidade

        //Essas duas verificações se os lobo adormecidos já viraram lobo, talvez não fosse necessário, pois caso eles tivessem virado
        //eles já estariam atacando e o primeiro if de todos seria acessado. Mas por segurança, vou manter

        if(atacadoL==ind_la1 && !virou_LA2){ //Verifica se o lobo atacou o lobo adormecido 1 e se o lobo adormecido 2 já virou lobo
            if((salvo>=0 && !Personagens[atacadoL]->getCura()) || (salvo==-1)){ 
                Personagens[atacadoL]->desativarObj(); 
                objs.push_back(new ObjetoDeJogo("morto"+to_string(atacadoL),Sprite("rsc/Morto.txt",cores[atacadoL]),posicoes[atacadoL].first,posicoes[atacadoL].second)); 
                Personagens[atacadoL]->setVida(false);
                auxLA2-> setVira_Lobo(true); //ativa o modo lobo do lobo adormecido 2, devido a saida do lobo adormecido 1
            }
        }
        else if(atacadoL==ind_la2 && !virou_LA1){ //Verifica se o lobo atacou o lobo adormecido 2 e se o lobo adormecido 1 já virou lobo
            if((salvo>=0 && Personagens[atacadoL]->getCura()) || (salvo==-1)){ 
                Personagens[atacadoL]->desativarObj(); 
                objs.push_back(new ObjetoDeJogo("morto"+to_string(atacadoL),Sprite("rsc/Morto.txt",cores[atacadoL]),posicoes[atacadoL].first,posicoes[atacadoL].second)); 
                Personagens[atacadoL]->setVida(false);
                auxLA1-> setVira_Lobo(true); //ativa o modo lobo do lobo adormecido 1, devido a saida do lobo adormecido 2
            }
        }
        else{//Se o ataque ocorreu em qualquer outro personagem que não os lobos adormecidos
            if((salvo>=0 && !Personagens[atacadoL]->getCura()) || (salvo==-1)){ 
                Personagens[atacadoL]->desativarObj(); 
                objs.push_back(new ObjetoDeJogo("morto"+to_string(atacadoL),Sprite("rsc/Morto.txt",cores[atacadoL]),posicoes[atacadoL].first,posicoes[atacadoL].second)); 
                Personagens[atacadoL]->setVida(false);
            }
        }

    }
    else if(atacadoLA>=0){ //Se apenas o lobo adormecido tiver atacado. Nesse caso, o lobo teria sido tirado da cidade
        
        if((salvo>=0 && !Personagens[atacadoLA]->getCura()) || (salvo==-1)){ 
            Personagens[atacadoLA]->desativarObj(); 
            objs.push_back(new ObjetoDeJogo("morto"+to_string(atacadoLA),Sprite("rsc/Morto.txt",cores[atacadoLA]),posicoes[atacadoLA].first,posicoes[atacadoLA].second)); 
            Personagens[atacadoLA]->setVida(false); 
        }

    }
    
    //Depois de tudo feito, podemos setar a cura do personagem novamente para falso
    if(salvo>-1){
        Personagens[salvo]->setCura(false);
    }
}


