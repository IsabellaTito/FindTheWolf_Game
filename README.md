<h1 align="center" style="font-weight: bold;">Find The Wolf ASCII Game 🐺 </h1>

<p>
Para concluir a disciplina de Programação Orientada a Objetos (POO), do curso de Engenharia da Computação, foi proposto o desenvolvimento de um jogo que aplicasse os principais conceitos da programação orientada a objetos. Este foi o projeto que desenvolvi como trabalho final, inspirado nos jogos de RPG <b>Wolvesville – Werewolf</b> e <b>Cidade Dorme</b>. Durante o desenvolvimento, utilizamos uma Engine elaborada e fornecida pelo professor, o que tornou o processo mais fluido e permitiu criar uma experiência de jogo mais dinâmica e envolvente. Para acessar a Engine basta acessar o link abaixo:
</p>

<p align="center">
     <a href="https://github.com/victorHSS/Cpp-ASCII-Game-Engine.git">🕹️The ASCII Game Engine🕹️</a>
</p>

<h2 id="Descricao"> 📝Descrição do Jogo</h2>

<p>
  No jogo <b>Find The Wolf</b> você será um aldeão que tem a missão de ajudar a salvar a vila do ataque dos lobos. Para alcançar esse objetivo, a cada rodada você deve escolher dois personagens para investigar. Em seguida, deve escolher um dentre os personagens restantes para tirar da vila. Se conseguir mandar embora todos os lobos antes deles acabarem com a vila, você ganha em conjunto com os aldeões. Caso contrário, os lobos ganham. 
  O jogo é composto de um lobo, dois lobos adormecidos, um médico, seis aldeões e um guru. Cada um deles tem uma tarefa diferente:
  
  <b>Aldeão 👨‍🌾:</b> São os moradores da vila e tem o objetivo de se protegerem dos ataques dos lobos, sendo assim inofensivos. Você não deve se preocupar com eles, mas fique atento para não retirá-los da vila.
  
  <b>Lobo 🐺:</b> Um dos aldeões se transforma em lobo durante a noite e ataca o vilarejo, retirando um personagem por noite. Ele ganha quando não tiver mais aldeões para atacar.
  
  <b>Lobo Adormecido 💤:</b> No jogo existem dois lobos adormecidos. Um deles irá se transformar em lobo e começar a atacar a vila depois que seu parceiro for retirado da vila, seja pelo ataque do lobo ou por você, na tentativa de encontrar o lobo. Você <b>não</b> será avisado quando a transformação acontecer, mas poderá notar no decorrer do jogo. Enquanto nenhum deles sair da vila, ambos lutam junto aos aldeões para salvar a vila do lobo. 

  <b>Médico🩺:</b> A cada rodada o médico deve salvar um dos aldeões da vila do ataque dos lobos. O aldeão que ele escolher proteger naquela rodada, não será pego pelo lobo, mesmo que ele tente. Você não será avisado de quem foi salvo, mas poderá notar se alguém saiu da vila além do que você escolheu. 
  
  <b>Guru🔮:</b> O guru dá dicas para que você consiga identificar qual a função de cada personagem no jogo. No entanto, muito cuidado com esse poder, só é possível verificar dois personagens por rodada e depois disso já será preciso escolher qual dentre os aldeões restantes você quer retirar da vila.

 <p align="center">
⚠️<b>ATENÇÃO!!!</b>⚠️<br>
   
  Enquanto o lobo adormecido fizer parte dos aldeões você poderá receber dicas semelhantes as recebidas quando o personagem é apenas um aldeão, mas quando ele se transformar, você verá dicas de lobo. 
   Outra informação importante sobre as dicas do guru é que cada personagem possui um conjunto de frases que dão dicas sobre a sua função ou mantém o mistério. A escolha para as frases aparecerem é aleatória. Dessa forma, em alguns casos, como temos mais de um personagem com a mesma função (como os aldeões) possa ser que durante uma das rodadas as duas dicas sejam iguais, mesmo você selecionando personagens diferentes. Desse modo, tudo depende da sua sorte!! 
</p>
</p>

<h2 id="layout">🕵🏽‍♂️Layout do Jogo</h2>
As telas abaixo são, respectivamente, o menu e a tela do jogo. Para poder movimentar o cursor, tanto para navegar no menu quanto durante o jogo, use as teclas <kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd>. Para selecionar um campo basta apertar <kbd>X</kbd>. Quando estiver no jogo, para receber a dica do guru, seleciona o personagem que deseja, posicionando o cursor em cima dele, e aperte <kbd>X</kbd>. Quando estiver decidido sobre qual aldeão quer retirar da vila, aperte <kbd>E</kbd>. Se estiver no meio de uma partida e desejar sair antes do jogo terminar, basta apertar <kbd>Q</kbd> que voltará ao menu inicial. <br>  

<p align="center">
  <img src="https://github.com/user-attachments/assets/ededc5bb-79b7-4ef5-bf19-2b702dddedb6" alt="Tela de menu do jogo" width=500px/>
  <img src="https://github.com/user-attachments/assets/0ab73384-a59c-4771-bed5-0fefea2273a4" alt="Tela do jogo" width=500px />
</p>

Para ficar mais claro, aqui está um exemplo de uma partida de Find The Wolf. Agora você vai estar mais do que preparado para defender o vilarejo do ataque dos lobos. Espero que goste do jogo.<b> Boa sorte!! </b>

<p align="center">
<img src="https://github.com/user-attachments/assets/8e886837-b267-4eb2-a755-392ad20e31db" width="730"/>
</p>
<p align="center">
<b>
Outros jogos muito interessantes foram criados pelos demais alunos. Ficou curioso???😌 No youtube você pode ver um pouco de cada um dos jogos!!
<p align="center">
    <a href="https://www.youtube.com/watch?v=dIBq-FbOSdk">Gameplay no YouTube ▶️</a>
</p>
</b>
</p>

<h2 id="requisitos"> ✅ Requisitos</h2>

Para conseguir jogar na sua máquina é necessário possuir o compilador para a linguagem C++. Caso ainda não tenha, basta usar o seguinte comando no terminal

```bash
sudo apt install g++
```

O jogo possui trilha sonora e para conseguir escutar é necessário instalar o tocador de músicas `mpg321` no seu terminal. Para isso, basta executar o comando

```bash
  sudo apt install mpg321
```

<h2 id="jogar"> 🎮 Como Jogar</h2>

Em um sistema `Linux` clone o repositório com o comando

```bash
git clone github.com/IsabellaTito/FindTheWolf_Game
```
Adicione a permissão e crie o executável com os comandos

```bash
cd FindTheWolf_Game
chmod +x makeplay
./makeplay
```




