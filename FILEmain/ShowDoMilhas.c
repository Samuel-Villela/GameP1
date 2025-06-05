#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    int i,j;
    char r; // Repostas do usuario das perguntas
    char *perguntas[] = 
    {
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

        "O que representa a formula E=mc²?\nA) Energia = massa x velocidade B) Energia = carga eletrica ao quadrado\nC) Energia = massa x gravidade D) Energia = massa x velocidade da luz ao quadrado"
    };
    char *respostas[] = 
    {
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

    int
    usadas[18] = {0}; // Vetor para evitar repetição

    srand(time(NULL));

    for(j=0;j<10;j++)
    {
        i=rand()%18;

        while(!usadas[i]) // Evitar repetição
        {
            printf("%s \n",perguntas[i]);
            printf("Escolha uma alternativa:");
            scanf(" %c",&r);

            if(r == respostas[i][0]){
                printf("Certa reposta!\n");
            }
             else{
                printf("Errado! Reposta correta e: %c \n",respostas[i]);
            }
            usadas[i]=1;
        }
    }

    return 0;
}