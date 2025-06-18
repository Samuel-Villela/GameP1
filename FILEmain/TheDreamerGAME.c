#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define MAX_SLOTS 5

typedef struct JOGADOR_ {
    char nome[21];
    int ultimoMinigame;
    int pontuacao;
    // Atributos do BattleGame
    int ataque;
    int vida;
    int defesa;
} JOGADOR;

void Minigame_Penaltis(char *nome, int *escolhaMenu, JOGADOR *p);
void Minigame_ShowDoMilhao(char *nome, int *escolhaMenu, JOGADOR *p);
void Minigame_BattleGame(char *nome, int *escolhaMenu, JOGADOR *p);

void printfDL(char *texto, int delay_ms);
char lerOpcaoOuEsc(int *escolhaMenu, const char *opcoesValidas); //Funcao de ler opcoes ou esc, usada nos minigames para retornar ao menu
void mostrarMenu(char *nome, int *escolhaMenu, JOGADOR p);
void salvarJogo(JOGADOR *p);
void carregarJogo(JOGADOR *p);


int main() {
    int i, sorteados[3], count = 0, sorteio;
    char *nome = (char *)malloc(21 * sizeof(char));
    int escolhaMenu;
    JOGADOR p;

    printf("Escolha um nome:  ");
    fgets(nome, 21, stdin);
    nome[strcspn(nome, "\n")] = 0;

    strncpy(p.nome, nome, 20); //Passando o nome para o struct
    p.nome[20] = '\0';  // Garante terminação

    mostrarMenu(nome, &escolhaMenu, p);

    if (escolhaMenu == 1) { //Inicio do jogo(so inicia caso o jogador selecione "Iniciar")
        srand(time(NULL));

        while (count < 3) {
            int repetido = 0;
            sorteio = 1 + rand() % 5;

            for (i = 0; i < count; i++) {
                if (sorteio == sorteados[i]) {
                    repetido = 1;
                    break;
                }
            }

            if (repetido) continue;

            sorteados[count++] = sorteio;

            if (sorteio == 1) {
                printfDL("\nJogo 1 escolhido: Penaltis\n", 50);
                Minigame_Penaltis(nome, &escolhaMenu, &p);
            } else if (sorteio == 2) {
                printfDL("\nJogo 2 escolhido: Show do Milhao\n", 50);
                Minigame_ShowDoMilhao(nome, &escolhaMenu, &p);
            } else if (sorteio == 3) {
                printfDL("\nJogo 3 escolhido: Matematica Discreta\n", 50);
                Minigame_BattleGame(nome, &escolhaMenu, &p);
            } else if (sorteio == 4) {
                printfDL("\nJogo 4 escolhido:\n", 50);
            } else if (sorteio == 5) {
                printfDL("\nJogo 5 escolhido:\n", 50);
            }
        }
        free(nome);
        return 0;
    }
}

void mostrarMenu(char *nome, int *escolhaMenu, JOGADOR p) {
    *escolhaMenu = 0;

    while (*escolhaMenu == 0) 
    {
        printf("  _______ _            _____                                     \n");
        printf(" |__   __| |          |  __ \\                                    \n");
        printf("    | |  | |__   ___  | |  | |_ __ ___  __ _ _ __ ___   ___ _ __ \n");
        printf("    | |  | '_ \\ / _ \\ | |  | | '__/ _ \\/ _` | '_ ` _ \\ / _ \\ '__|\n");
        printf("    | |  | | | |  __/ | |__| | | |  __/ (_| | | | | | |  __/ |   \n");
        printf("    |_|  |_| |_|\\___| |_____/|_|  \\___|\\__,_|_| |_| |_|\\___|_|   \n");
        printf("                                                                 \n");



        printfDL("Bem-vindo ao mundo dos sonhos!\n", 50);
        printfDL("Escolha sua proxima aventura:\n\n", 50);

        printfDL("  1) Iniciar jornada\n", 50);
        printfDL("  2) Salvar jogo\n", 50);
        printfDL("  3) Carregar jogo\n", 50);
        printfDL("  4) Ranks\n", 50);
        printfDL("  5) Trocar nome do personagem\n", 50);
        printfDL("  6) Sair do jogo\n\n", 50);

        printf("Digite o numero da opcao desejada:\n");
        scanf(" %d", escolhaMenu);

        if(*escolhaMenu < 0 || *escolhaMenu > 6)
        {
            printf("\nOpcao invalida!\n");
            printf("Digite o numero da opcao desejada:\n");
            scanf(" %d",escolhaMenu);
            *escolhaMenu=0;
        }
        if (*escolhaMenu == 2) {
            printfDL("Deseja salvar o jogo\n",50);
            printf(" 1) Sim\n");
            printf(" 2) Voltar\n");
            scanf(" %d",escolhaMenu);

            if(*escolhaMenu == 1){
                // salvar jogo
                salvarJogo(&p);  //FALTA definir o struct como variavel e chamar p[h]
            }
            else{
                printf("\n\n\n\n");
            }
            *escolhaMenu = 0;
        }
        if (*escolhaMenu == 3){
            printfDL("Deseja carregar o jogo\n",50);
            printf(" 1) Sim\n");
            printf(" 2) Voltar\n");
            scanf(" %d",escolhaMenu);

            if(*escolhaMenu == 1){
                // carregar jogo
                carregarJogo(&p);  //FALTA definir o struct como variavel e chamar p[h]
                printfDL("Carregamento concluido!",50);
            }
            else{
                printf("\n\n\n\n");
            }
         *escolhaMenu = 0;
        }
        if (*escolhaMenu == 5) {  // trocar nome
            printf("Novo nome: ");
            scanf(" %20s", nome);
            printf("\n\n\n\n");
            *escolhaMenu = 0;
        }
    }
}

char lerOpcaoOuEsc(int *escolhaMenu, const char *opcoesValidas) {
    char tecla;
    while (1) {
        tecla = _getch();

        if (tecla == 27) {
            printfDL("\n[ESC detectado] Voltando ao menu...\n", 30);
            *escolhaMenu = 0;
            return 0;
        }

        tecla = toupper(tecla);
        if (strchr(opcoesValidas, tecla)) {
            return tecla;
        }
    }
}

void salvarJogo(JOGADOR *p)
{
    int slot;
    int algumSaveExiste = 0;
    char filename[30];

    // Verifica se existe ao menos um save
    for (int i = 1; i <= MAX_SLOTS; i++) {
        sprintf(filename, "saveTheDreamer_%d.dat", i);
        FILE *f = fopen(filename, "rb");
        if (f != NULL) {
            fclose(f);
            algumSaveExiste = 1;
            break;
        }
    }

    int decisaoSave = 1;

    if (algumSaveExiste) {
        printf("Ja existe pelo menos um arquivo de save. O que voce deseja fazer?\n");
        printf(" 1) Criar novo save\n");
        printf(" 2) Substituir um save existente\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &decisaoSave);

        if (decisaoSave != 1 && decisaoSave != 2) {
            printf("Opcao invalida. Jogo NAO foi salvo.\n");
            return;
        }
    }

    if (decisaoSave == 1) {
        printf("\nEscolha o slot para salvar (1-%d):\n", MAX_SLOTS);
    } else {
        printf("\nEscolha o slot para substituir (1-%d):\n", MAX_SLOTS);
    }

    for (int i = 1; i <= MAX_SLOTS; i++) {
        printf("  %d) Slot %d\n", i, i);
    }

    printf("Escolha: ");
    scanf("%d", &slot);

    if (slot < 1 || slot > MAX_SLOTS) {
        printf("\nSlot invalido. Cancelando salvamento.\n");
        return;
    }

    sprintf(filename, "saveTheDreamer_%d.dat", slot);
    FILE *save = fopen(filename, "wb");
    if (save) {
        fwrite(p, sizeof(JOGADOR), 1, save);
        fclose(save);
        printf("\nJogo salvo com sucesso no slot %d!\n", slot);
    } else {
        printf("\nErro ao salvar o jogo no slot %d.\n", slot);
    }
}

void carregarJogo(JOGADOR *p)
{
    int slot;
    printf("\nEscolha o slot para carregar (1-%d):\n", MAX_SLOTS);
    for (int i = 1; i <= MAX_SLOTS; i++) {
        printf("  %d) Slot %d\n", i, i);
    }
    printf("Escolha: ");
    scanf("%d", &slot);

    if (slot < 1 || slot > MAX_SLOTS) {
        printf("\nSlot invalido. Cancelando carregamento.\n\n");
        return;
    }

    char filename[30];
    sprintf(filename, "saveTheDreamer_%d.dat", slot);

    FILE *save = fopen(filename, "rb");
    if (save) {
        fread(p, sizeof(JOGADOR), 1, save);
        fclose(save);
        printf("\nJogo carregado com sucesso do slot %d!\n", slot);
        printf("Nome: %s | Pontuacao: %d | Vida: %d | Ataque: %d | Defesa: %d\n",
               p->nome, p->pontuacao, p->vida, p->ataque, p->defesa);
        printf("\n");
    } 
    else {
        printf("\nSlot %d vazio ou erro ao carregar.\n", slot);
    }
}

void Minigame_Penaltis(char *nome, int *escolhaMenu, JOGADOR *p) {
    int ladoGoleiro = 0, i = 0, gols_feitos = 0, gols_desperdicados = 0;
    char Pulo_Goleiro;

    printf("\n---- HORA DOS PENALTIS ----\n");

    for (i = 0; i < 5; i++) {
        printf("  ----------------------------------------------------- \n"
               " |O Placar esta %d gols feitos e %d gols desperdicados |\n"
               "  -----------------------------------------------------\n", gols_feitos, gols_desperdicados);
        printf("                    ____   \n"
               " o__        o__     |   |\\  \n"
               "/|          /\\      |   |X\\ \n"
               "/ > o        <\\     |   |XX\\\n");

        int chute_Player = '\0';
        while (chute_Player != 'E' && chute_Player != 'D' && chute_Player != 'M') {
            printf("\n Escolha um lado para chutar no gol:  \n");
            printf("lado Esquerdo [E], Lado Direito [D], Meio do Gol [M]:   ");

            chute_Player = lerOpcaoOuEsc(escolhaMenu, "EDM");
            printf("\n\n\n");
        }

        if (chute_Player == 0) {
            mostrarMenu(nome, escolhaMenu, *p);
            return;
        }

        ladoGoleiro = rand() % 3;
        if (ladoGoleiro == 0) Pulo_Goleiro = 'E';
        else if (ladoGoleiro == 1) Pulo_Goleiro = 'D';
        else Pulo_Goleiro = 'M';

        if (Pulo_Goleiro == chute_Player) {
            printf("\nO GOLEIRO AGARROU SEU CHUTE!!!\n");
            gols_desperdicados++;
        } else {
            printf("\nQUE GOLACOOO!!!! %s Converte o Penalti\n", nome);
            gols_feitos++;
        }
    }

    if (gols_feitos >= 3) {
        printf("\n%s converteu a maior parte de seus penaltis, esta permitido ir para o proximo Desafio\n", nome);
    } else {
        printf("\n%s nao converteu a maior parte de seus penaltis e FALHOU NO DESAFIO DOS PENALTIS\n", nome);
    }
}

void Minigame_ShowDoMilhao(char *nome, int *escolhaMenu, JOGADOR *p) {
    int i, j, pontuacao = 0;
    char r;
    char *perguntas[] = {
        "Qual dessas palavras nao tem relacao com sustentacao?\nA) Base B) Alicerce\nC) Fundamento D) Ruina",

        "D. Pedro I do Brasil foi um:\nA) Explorador B) Presidente \nC) Almirante D) Imperador",

        "O po-de-mico quando entra em contato com a pele provoca qual tipo de reacao?\nA) Tristeza B) Frio \nC) Dor D) Cosegas",

        "Qual e o principal orgao do sistema nervoso central?\nA) Coracao B) Estomago\nC) Pulmao D) Cerebro",

        "Qual foi o pais responsavel pela Revolucao Industrial no seculo XVIII?\nA) Franca B) Alemanha\nC) Inglaterra D) Estados Unidos",

        "Quem escreveu Dom Casmurro?\nA) Jose de Alencar B) Machado de Assis\nC) Clarice Lispector D) Graciliano Ramos",

        "Qual e a capital do estado de Pernambuco?\nA) Fortaleza B) Joao Pessoa\nC) Salvador D) Recife",

        "Quantos lados tem um octogono?\nA) 6 B) 7\nC) 8 D) 9",

        "Em que unidade e medida a corrente eletrica?\nA) Volt B) Ohm\nC) Watt D) Ampere",

        "Qual elemento quimico tem o simbolo Na?\nA) Nitrogenio B) Sodio\nC) Niobio D) Niquel",

        "Em que continente fica o pais do Egito?\nA) Asia B) Europa\nC) America D) Africa",

        "O que e fotossintese?\nA) Processo de digestao das plantas B) Processo de perda de folhas\nC) Processo de respiracao vegetal D) Processo de producao de alimento pelas plantas",

        "Que animal e simbolo da sabedoria na mitologia grega?\nA) Leao B) Coruja\nC) Serpente D) Cavalo",

        "Quem pintou o teto da Capela Sistina, no Vaticano?\nA) Leonardo da Vinci B) Rafael\nC) Michelangelo D) Donatello",

        "Qual e o nome da particula responsavel pela forca forte dentro do nucleo atomico?\nA) Eletron B) Gluon\nC) Proton D) Foton",

        "Em que ano aconteceu a Proclamacao da Republica no Brasil?\nA) 1822 B) 1888\nC) 1889 D) 1891",

        "Quem foi o filosofo que afirmou 'So sei que nada sei'?\nA) Plato B) Socrates\nC) Aristoteles D) Epicuro",

        "O que representa a formula E=m(c*c)?\nA) Energia = massa x velocidade B) Energia = carga eletrica ao quadrado\nC) Energia = massa x gravidade D) Energia = massa x velocidade da luz ao quadrado"
    };
    char *respostas[] = {
        "D",
        "D",
        "C",
        "D",
        "C",
        "B",
        "D",
        "C",
        "D",
        "B",
        "D",
        "D",
        "B",
        "C",
        "B",
        "C",
        "B",
        "D"
    };

    int usadas[18] = {0};

    for (j = 0; j < 10; j++) {
        do {
            i = rand() % 18;
        } while (usadas[i]);

        usadas[i] = 1;

        printf("%s \n", perguntas[i]);
        printf("Escolha uma alternativa (A-D ou ESC para sair): ");
        r = lerOpcaoOuEsc(escolhaMenu, "ABCD");

        if (r == 0) {
            mostrarMenu(nome, escolhaMenu, *p);
            return;
        }

        if (r == respostas[i][0]) {
            printfDL("\nCerta resposta!\n\n",50);
            pontuacao += 10;
        } else {
            printf("\nErrado! Resposta correta e: %c \n\n", respostas[i][0]);
        }
    }
    printf("\n%s sua pontuacao foi %d\n", nome, pontuacao);
}

void printfDL(char *texto, int delay_ms) {
    while (*texto) {
        printf("%c", *texto);
        fflush(stdout);
        Sleep(delay_ms);
        texto++;
    }
}
void Minigame_BattleGame(char *nome, int *escolhaMenu, JOGADOR *p)
{
    typedef struct MOB_
    {
        int vida;
        int ataque;
        int defesa;
    }MOB;

    MOB m[10];
    char acao_personagem;
    int fugir=0, ataque_especial_mob=0;
    int i,z; //z e o aleatorio
    int quant_batalhas=0;

    srand(time(NULL));

    printf("Apresentacao do minigame\n");

    //Informacoes sobre personagem e MOB antes da batalha. Precisa ser definido para cada MOB
    i=1;
    p->vida=10; p->ataque=2; p->defesa=2; //Por enquanto os status do personagem sao definidos manualmente, dps trocar pra aleatorio
    m[i].vida=5+quant_batalhas; m[i].ataque=2+quant_batalhas; m[i].defesa=2+quant_batalhas;

    while(p->vida>=0 && m[i].vida>=0 && fugir==0)  //Batalha entre personagem e mob
    {
        //Menu batalhas
        //printf("imagem da batalha");

        printf("Atacar = A\n");
        printf("Defender = D\n");
        printf("Fugir = F\n");

        printf("\nEscolha sua acao: ");

        acao_personagem = lerOpcaoOuEsc(escolhaMenu, "ADF");
       
        if(escolhaMenu == 0){
            mostrarMenu(nome, escolhaMenu, *p);
            return;
        } //Parte do personagem
        else if(acao_personagem == 'A'){
            m[i].vida = m[i].vida - p->ataque;
            printf("Voce atacou o MOB\n");
        }
        else if(acao_personagem == 'D'){
            p->vida = p->vida - (m[i].ataque - p->defesa);
            printf("Voce se defendeu\n");
        }
        else if(acao_personagem == 'F'){
            fugir=1;
            printf("Seu personagem fugiu\n");
        }
        printf("\n");
        //Parte do personagem
        z=1+rand()%3;

        if(ataque_especial_mob==1){  //Ataque especial
            p->vida = p->vida - m[i].ataque;  //Ataque com o buff
            m[i].ataque = m[i].ataque/2;
            ataque_especial_mob=0;
        }
        else if(z==1){ //Ataque
            p->vida = p->vida - m[i].ataque;
            printf("O MOB te atacou\n");
        }
        else if(z==2){ //Defesa
            m[i].vida = m[i].vida - (p->ataque - m[1].defesa);
            printf("O monstro se defendeu\n");
        }
        else if(z==3){//Ataque especial
            ataque_especial_mob=1;
            m[i].ataque = m[i].ataque*2;
            printf("O MOB esta carregando um golpe especial!\n");
        }
        printf("Sua vida atual e: %d \n",p->vida);
        printf("A vida atual do MOB e: %d \n",m[i].vida);
    }
    if(p->vida <= 0){
        printf("Voce perdeu!\n");
        // add uma opcao se quer voltar pro menu ou tentar novamente
        mostrarMenu(nome, escolhaMenu, *p);
        return;
    }
    else{
        printf("Voce venceu!\n");
        quant_batalhas++;
    }
    printf("Continuacao da historia");
}
