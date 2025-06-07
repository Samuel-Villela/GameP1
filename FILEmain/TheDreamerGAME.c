#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#include <windows.h> // biblioteca do sleep 

void printfDL(char*texto, int delay_ms);
void Limpar_tela(); // não precisa de parametro, só estou chamando pra exucutar tal função

int main()
{
    int i,a,Nrepetir=-1;
    char nome[21];
    char escolhaMenu[11];

    strcpy(escolhaMenu,"repetir");


    printf("Escolha um nome: ");
    scanf("%s",nome);

    while(strcmp(escolhaMenu,"repetir")==0)

    {
     // Menu do jogo.
     printfDL("\n -- Menu do Jogo --\n", 50);
     printf("Digite uma das opcoes:\n");
     printfDL(" -- Trocar Nome \n",50);
     printfDL(" -- inicio\n", 50);
     printfDL(" -- sair\n", 50);


     // Vai ver oq o cara quer fazer no menu
     scanf("%s",escolhaMenu);  //tenho que trocar por FGETS AAAAAAA

     // Se o cara so quiser fazer acoes que nao saiam do menu tem que botar aqui e dps dar o valor de 'repetir' pro escolhaMenu.
     if(strcmp(escolhaMenu,"trocarnome")==0 || strcmp(escolhaMenu,"trocarNome")==0){
        printf("\nNovo nome: ");
        scanf("%s",nome);
        strcpy(escolhaMenu,"repetir");
     }
    }

    if(strcmp(escolhaMenu,"inicio")==0 || strcmp(escolhaMenu,"Inicio")==0){
    // Aqui inicia o jogo.
    srand(time(NULL));
    // Escolha de 3 minijogos, sem se repetirem.
    for(i=0;i<3;i++)
    {
    a=1+rand()%5;

    if(a==Nrepetir){
        a=0;
        i--;
        continue;
    }
    if(a==1){
        printfDL("\n jogo 1 Escolhido\n",50);
    }
    if(a==2){
        printfDL("jogo 2\n",50);
    }
    if(a==3){
        printfDL("jogo 3\n",50);
    }
    if(a==4){
        printfDL("jogo 4\n",50);
    }
    if(a==5){
        printfDL("jogo 5\n",50);
    }
    Nrepetir=a;
    a=0;
    }
    }
    
    return 0;  
}

void printfDL(char*texto, int delay_ms){
    while(*texto){
        printf("%c",*texto); //printar o primeiro caracter do texto na tela
        fflush(stdout); //força o printf amandar na tela cada letra
        Sleep(delay_ms); // recebe o delay em milisegundo
        texto++; // pula para o proximo ponteiro
    } 
}

void Limpar_tela(){
    #ifdef _WIN32;
        system("cls"); // para windons
    #else
        system("clear"); // pra linux
    #endif;
}