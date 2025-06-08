#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct PERSONAGEM_
{
    int vida;
    int ataque;
    int defesa;
}PERSONAGEM;
typedef struct MOB_
{
    int vida;
    int ataque;
    int defesa;
}MOB;
int main()
{
    PERSONAGEM p;
    MOB m[10]; // cria uma array preenchda de mobs
    char acao_personagem;
    int fugir=0;  
    int i,z; //z e o aleatorio
    int ataque_especial_mob=0;

    srand(time(NULL));

    printf("Apresentacao do minigame\n");


    //Informacoes sobre personagem e MOB antes da batalha. Precisa ser definido para cada MOB
    i=1;
    p.vida=10; p.ataque=2; p.defesa=2;
    m[i].vida=5; m[i].ataque=2; m[i].defesa=2;

    while(p.vida>=0 && m[i].vida>=0 && fugir==0)  //Batalha entre personagem e mob
    {
        //Menu batalhas
        //printf("imagem da batalha");

        printf("Atacar = A\n");
        printf("Defender = D\n");
        printf("Fugir = F\n");

        printf("\nEscolha sua acao:");

        scanf(" %c",&acao_personagem);
       
        //Parte do personagem
        if(acao_personagem == 'A'){
            m[i].vida = m[i].vida - p.ataque;
            printf("Voce atacou o MOB\n");
        }
        else if(acao_personagem == 'D'){
            p.vida = p.vida - (m[i].ataque - p.defesa);
            printf("Voce se defendeu\n");
        }
        else if(acao_personagem == 'F'){
            fugir=1;
            printf("Seu personagem fugiu\n");
        }
        //Parte do personagem
        z=1+rand()%3;

        if(ataque_especial_mob==1){  //Ataque especial
            p.vida = p.vida - m[i].ataque;  //Ataque com o buff
            m[i].ataque = m[i].ataque/2;
            ataque_especial_mob=0;
        }
        else if(z==1){ //Ataque
            p.vida = p.vida - m[i].ataque;
            printf("O MOB te atacou\n");
        }
        else if(z==2){ //Defesa
            m[i].vida = m[i].vida - (p.ataque - m[1].defesa);
            printf("O monstro se defendeu\n");
        }
        else if(z==3){//Ataque especial
            ataque_especial_mob=1;
            m[i].ataque = m[i].ataque*2;
            printf("O MOB esta carregando um golpe especial!\n");
        }
        printf("Sua vida atual e: %d \n",p.vida);
        printf("A vida atual do MOB e: %d \n",m[i].vida);
    }
    if(p.vida<=0){
        printf("Voce perdeu!\n");
        return 0;
    }
    else{
        printf("Voce venceu!\n");
    }

    printf("Continuacao da historia");
}