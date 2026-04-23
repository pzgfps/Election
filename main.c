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

int main()
{
    char nomeCandidato1[50], nomeCandidato2[50], nomeCandidato3[50], maisVotados[1];
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
    
    porcentagemVotos1 = (qntdVotos1 / qntdVotosTotal) * 100;
    porcentagemVotos2 = (qntdVotos2 / qntdVotosTotal) * 100;
    porcentagemVotos3 = (qntdVotos3 / qntdVotosTotal) * 100;
    
    printf("\nQuantidade total de votos: %.0f", qntdVotosTotal);
    printf("\nQuantidade de votos válidos: %.0f", qntdVotosValidos);
    printf("\n%s: %.2f% votos", nomeCandidato1, porcentagemVotos1);
    printf("\n%s: %.2f% votos", nomeCandidato2, porcentagemVotos2);
    printf("\n%s: %.2f% votos", nomeCandidato3, porcentagemVotos3);
    
    if(porcentagemVotos1 > aprovado) {
        printf("\n%s foi eleito com %.1f% total de votos!", nomeCandidato1, porcentagemVotos1);
    } else if(porcentagemVotos2 > aprovado) {
        printf("\n%s foi eleito com %.1f% total de votos!", nomeCandidato2, porcentagemVotos2);
    } else if (porcentagemVotos3 > aprovado) {
        printf("\n%s foi eleito com %.1f% total de votos!", nomeCandidato3, porcentagemVotos3);
    } else {
        
        printf("\nNão houve eleitos no 1° turno!");
    }
    
    
    
    return 0;
}
