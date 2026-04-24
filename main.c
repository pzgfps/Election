/******************************************************************************

Faça um programa que faça a apuração de uma votação em que concorrem 3 candidatos. 
Ele deverá receber, para cada candidato, o número da urna eletrônica e a quantidade de votos recebidos.
O programa também deverá receber a quantidade total de votos brancos e de votos nulos.
Após receber todas essas informações, o programa deverá informar qual foi a quantidade total de votos, 
a quantidade total de votos válidos (que não foram brancos ou nulos, ou seja, que foram para algum candidato) 
e o porcentual de votos válidos de cada candidato.

Depois disso, se algum candidato ganhou (teve mais que 50% dos votos válidos), o programa deverá informar qual foi. 
Se nenhum tiver ganhado nesse turno (cada um teve no máximo 50% dos votos válidos), 
deverá informar quais são os candidatos que deverão concorrer o segundo turno (os dois mais votados).
Também informe, para conhecimento público, a porcentagem de votos brancos e nulos do total de votos, 
para demonstrar quantos votantes protestaram na seção eleitoral.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    char nomeCandidato1[50], nomeCandidato2[50], nomeCandidato3[50], maisVotado1[50], maisVotado2[50];
    int numeroEleitoral1, numeroEleitoral2, numeroEleitoral3;
    float qntdVotosBrancos, qntdVotosNulos, qntdVotosTotal, qntdVotosValidos, qntdVotos1, qntdVotos2, qntdVotos3;
    float porcentagemVotos1 = 0, porcentagemVotos2 = 0, porcentagemVotos3 = 0, aprovado = 50.0;
    
    printf("Digite o nome do 1° candidato: ");
    scanf("%s", &nomeCandidato1);
    printf("Digite o número eleitoral do 1° candidato: ");
    scanf("%d", &numeroEleitoral1);
    printf("Digite a quantidade de votos do 1° candidato: ");
    scanf("%f", &qntdVotos1);
    
    printf("\nDigite o nome do 2° candidato: ");
    scanf("%s", &nomeCandidato2);
    printf("Digite o número eleitoral do 2° candidato: ");
    scanf("%d", &numeroEleitoral2);
    printf("Digite a quantidade de votos do 2° candidato: ");
    scanf("%f", &qntdVotos2);
    
    printf("\nDigite o nome do 3° candidato: ");
    scanf("%s", &nomeCandidato3);
    printf("Digite o número eleitoral do 3° candidato: ");
    scanf("%d", &numeroEleitoral3);
    printf("Digite a quantidade de votos do 3° candidato: ");
    scanf("%f", &qntdVotos3);
    
    printf("\nDigite a quantidade de votos brancos: ");
    scanf("%f", &qntdVotosBrancos);
    printf("Digite a quantidade de votos nulos: ");
    scanf("%f", &qntdVotosNulos);
    
    qntdVotosTotal = qntdVotos1 + qntdVotos2 + qntdVotos3 + qntdVotosNulos + qntdVotosBrancos;
    qntdVotosValidos = qntdVotos1 + qntdVotos2 + qntdVotos3;
    
    porcentagemVotos1 = (qntdVotos1 / qntdVotosValidos) * 100;
    porcentagemVotos2 = (qntdVotos2 / qntdVotosValidos) * 100;
    porcentagemVotos3 = (qntdVotos3 / qntdVotosValidos) * 100;
    
    printf("\nQuantidade total de votos: %.0f", qntdVotosTotal);
    printf("\nVotos brancos: %.2f%% do total", (qntdVotosBrancos / qntdVotosTotal) * 100);
    printf("\nVotos nulos:   %.2f%% do total", (qntdVotosNulos   / qntdVotosTotal) * 100);
    printf("\nQuantidade de votos válidos: %.0f", qntdVotosValidos);
    printf("\n\n%s: %.2f%% votos", nomeCandidato1, porcentagemVotos1);
    printf("\n%s: %.2f%% votos", nomeCandidato2, porcentagemVotos2);
    printf("\n%s: %.2f%% votos", nomeCandidato3, porcentagemVotos3);
    
    if(porcentagemVotos1 > aprovado) {
        printf("\n\n%s foi eleito com %.2f%% dos votos validos!", nomeCandidato1, porcentagemVotos1);
    } else if(porcentagemVotos2 > aprovado) {
        printf("\n\n%s foi eleito com %.2f%% dos votos validos!", nomeCandidato2, porcentagemVotos2);
    } else if (porcentagemVotos3 > aprovado) {
        printf("\n\n%s foi eleito com %.2f%% dos votos validos!", nomeCandidato3, porcentagemVotos3);
    } else {
        int numMaisVotado1, numMaisVotado2;
        float votosMaisVotado1, votosMaisVotado2;

    if (qntdVotos1 >= qntdVotos2 && qntdVotos1 >= qntdVotos3) {
        strcpy(maisVotado1, nomeCandidato1);
        votosMaisVotado1 = qntdVotos1;
        numMaisVotado1 = numeroEleitoral1;
    } else if (qntdVotos2 >= qntdVotos1 && qntdVotos2 >= qntdVotos3) {
        strcpy(maisVotado1, nomeCandidato2);
        votosMaisVotado1 = qntdVotos2;
        numMaisVotado1 = numeroEleitoral2;
    } else {
        strcpy(maisVotado1, nomeCandidato3);
        votosMaisVotado1 = qntdVotos3;
        numMaisVotado1 = numeroEleitoral3;
    }
    if (numMaisVotado1 == numeroEleitoral1) {
        if (qntdVotos2 >= qntdVotos3) {
            strcpy(maisVotado2, nomeCandidato2);
        } else {
            strcpy(maisVotado2, nomeCandidato3);
        }
    } else if (numMaisVotado1 == numeroEleitoral2) {
        if (qntdVotos1 >= qntdVotos3) {
            strcpy(maisVotado2, nomeCandidato1);
        } else {
            strcpy(maisVotado2, nomeCandidato3);
        }
    } else {
        if (qntdVotos1 >= qntdVotos2) {
            strcpy(maisVotado2, nomeCandidato1);
        } else {
            strcpy(maisVotado2, nomeCandidato2);
        }
    }
    printf("\n\nNenhum candidato atingiu 50%% dos votos validos.\n");
    printf("2° turno entre: %s  e %s\n", maisVotado1, maisVotado2);

    }
    
    return 0;
}
