#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h> // isso daqui serve para a gente trocar de maiusculo para minusculo rápido

void Minigame_Penaltis(char *nome);
int main()
{
    int i,a,Nrepetir=-1;
    char *nome;
    char escolhaMenu[11];
    nome=(char*) malloc(21*sizeof(char));// alterei para alocação odinamica do nome, serve para quando usarmos funções não perder dados
    strcpy(escolhaMenu,"repetir"); 


    printf("Escolha um nome:  ");
    fgets(nome,21,stdin); // alterei para que possa ser utilizado nome composto tambem
    nome[strcspn(nome, "\n")] = 0; // Remove o '\n' da string composta, ajuda a evitar erros ao usar o \n depois

    while(strcmp(escolhaMenu,"repetir")==0)

    {
     // Menu do jogo.
     printf("\n--- Menu do Jogo ---\n");
     printf("Digite uma das opcoes:\n");
     printf("- trocarNome\n");
     printf("- inicio\n");
     printf("- sair\n");


     // Vai ver oq o cara quer fazer no menu
     scanf("%s",escolhaMenu);  //tenho que trocar por FGETS AAAAAAA

     // Se o cara so quiser fazer acoes que nao saiam do menu tem que botar aqui e dps dar o valor de 'repetir' pro escolhaMenu.
     if(strcmp(escolhaMenu,"trocarnome")==0 || strcmp(escolhaMenu,"trocarNome")==0){
        printf("Novo nome: ");
        scanf("%20s",nome); // isso vai impedir do usuário estourar a memoria
        strcpy(escolhaMenu,"repetir");
     }
    }

    if(strcmp(escolhaMenu,"inicio")==0 || strcmp(escolhaMenu,"Inicio")==0){
    // Aqui inicia o jogo.
    srand(time(NULL));
    // Escolha de 3 minijogos, sem se repetirem.
    for(i=0;i<5;i++)
    {
    a=1+rand()%5;

    if(a==Nrepetir){
        a=0;
        i--;
        continue;
    }
    if(a==1){
        printf("jogo 1");
    }
    if(a==2){
        printf("jogo 2");
         Minigame_Penaltis(nome);
    }
    if(a==3){
        printf("jogo 3");
    }
    if(a==4){
        printf("jogo 4 escolhido");
        Minigame_Penaltis(nome);
    }
    if(a==5){
        printf("jogo 5");
    }
    Nrepetir=a;
    a=0;
    }
    }
    free(nome);    
    return 0; 

}

void Minigame_Penaltis(char*nome){
    int ladoGoleiro=0, i=0, gols_feitos =0, gols_desperdiçados =0;
    char Pulo_Goleiro;

    printf("\n---- HORA DOS PENALTIS ----\n");

    for(i=0; i<5; i++){

        printf("  ----------------------------------------------------- \n"
               " |O Placar esta %d gols feitos e %d gols desperdiçados |\n"
               "  -----------------------------------------------------\n",gols_feitos,gols_desperdiçados);
        printf("                    ____   \n"
       " o__        o__     |   |\\  \n"
       "/|          /\\      |   |X\\ \n" 
       "/ > o        <\\     |   |XX\\\n");

        int chute_Player = '\0';
        while (chute_Player!= 'E'&& chute_Player !='D' && chute_Player!= 'M') {
            printf("\n Escolha um lado para chutar no gol:  \n");
            printf("lado Esquerdo [E], Lado Direito [D], Meio do Gol [M]:   ");
            scanf(" %c",&chute_Player);
            chute_Player = toupper(chute_Player);
        }
        
        

        ladoGoleiro = rand() % 3;
        if (ladoGoleiro ==0){
            Pulo_Goleiro = 'E';
        }
        else if (ladoGoleiro ==1){
            Pulo_Goleiro = 'D';
        }
        else if(ladoGoleiro ==2){
            Pulo_Goleiro = 'M';
        }

        if (Pulo_Goleiro == chute_Player){
            printf("\nO GOLEIRO AGARROU SEU CHUTE!!!\n");   
            gols_desperdiçados = gols_desperdiçados +1;
        }
        else{
            printf ("\nQUE GOLAÇOOO!!!! %s Converte o Penalti\n",nome);
            gols_feitos = gols_feitos +1;
        }

        

    }
    if( gols_feitos >= 3){
     printf("\n%s converteu a maior parte de seus penaltis, está permitido ir para o proximo Desafio\n",nome);
    }   
    else{
        printf ("\n %s não converteu a maior parte de seus penaltis e FALHOU NO DESAFIO DOS PENALTIS\n",nome);
    }



}
