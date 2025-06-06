#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h> // isso daqui serve para a gente trocar de maiusculo para minusculo rápido

void Minigame_Penaltis(char*nome);
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Minigame_Penaltis(char *nome);

int main()
{
    int i,a,Nrepetir=-1;
    char *nome;
    char escolhaMenu[11];
    nome=(char*) malloc(21*sizeof(char));// alterei para alocaçã odinamica do nome, serve para quando usarmos funções não perder dados
    strcpy(escolhaMenu,"repetir"); 


    printf("Escolha um nome:  ");
    scanf("%s",nome);


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
    
    return 0; 
    free(nome);
}

void Minigame_Penaltis(char*nome){
    int chute_Player, ladoGoleiro=0, i=0, gols_feitos =0;
    char Pulo_Goleiro;

    printf("\n---- HORA DOS PENALTIS!!!");

    for(i=0; i<5; i++){
        printf("\n Escolha um lado para chutar no gol:  \n");
        printf("lado Esquerdo [E], Lado Direito [D], Meio do Gol [M]:   ");
        scanf(" %c",&chute_Player);
        chute_Player = toupper(chute_Player);  // converte pra todo letra minuscula para maiúscula

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
            int dado_player = 1 + rand()%20;
            int dado_Goleiro = 1+ rand()%20;
            if(dado_Goleiro>dado_player){
                printf("\nO GOLEIRO AGARROU SEU CHUTE!!!\n");   
            }
            else{
                printf (" \nAmbos escolheram o mesmo lado, MAS O CHUTE FOI FORTE DEMAIS!!! GOLAÇO!!!\n");
            }
        }
        else{
            printf ("QUE GOLAÇOOO!!!! %s Converte o Penalti\n",nome);
            gols_feitos = gols_feitos +1;
        }
        

    }
    if( gols_feitos >= 3){
     printf("%s converteu a maior parte de seus penaltis, está permitido ir para o proximo Desafio\n",nome);
    }   
    else{
        printf ("%s não converteu a maior parte de seus penaltis, FALHOU NO DESAFIO DOS PENALTIS\n",nome);
    }



}
