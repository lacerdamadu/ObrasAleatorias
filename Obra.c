#include "Obra.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InicializaObra(Obra *Quadro){
    srand(time(NULL));
    for(int i=0; i<20; i++){// Preenchendo a matriz com espaços para evitar lixo de memória
        for(int j=0; j<80; j++){
            Quadro->Tela[i][j] = ' ';
        }
    }
    for(int i=0;i<20;i++){//Criando a borda do quadro
        Quadro->Tela[i][0] = '|';
        Quadro->Tela[i][79] = '|';
    }
    for(int i=0;i<80;i++){//Criando a borda do quadro
        Quadro->Tela[0][i] = '-';
        Quadro->Tela[19][i] = '-';
    }
}

void ImprimiObra(Obra Quadro){
    for(int i=0; i<20; i++){
        for(int j=0; j<80; j++){
            printf("%c", Quadro.Tela[i][j]);
        }
        printf("\n");
    }
}
int NumeroAleatorio(int Limite){
    if(Limite == 19){//Gera numero aleatorio para a linha na tabela
        return rand() % 19;
    }
    else if(Limite == 79){//Gera numero aleatorio para a coluna na tabela
        return rand() % 79;
    }
    else{//Gera numero aleatorio de figuras
        return rand() % 100;
    }
}
int* CalculaPosSimples(Obra *Quadro, int *posicao){
    posicao[0] = NumeroAleatorio(19);
    posicao[1] = NumeroAleatorio(79);
    if((Quadro->Tela[(posicao[0])][(posicao[1])]) == ' '){
        return posicao;
    }
    else{
        return CalculaPosSimples(Quadro, posicao);
    }
}
void AsteriscoSimples(Obra *Quadro, int Quantidade){
    int pos[2];
    int *posicao;
    posicao = pos;
    if(Quantidade <= 0){//Se o usuário digitar um número menor ou igual a zero, será gerado um número de figuras aleatório entre 1 e 100
        Quantidade = NumeroAleatorio(100);
    }
    for(int i=0; i<Quantidade; i++){
        CalculaPosSimples(Quadro, posicao);
        Quadro->Tela[(posicao[0])][(posicao[1])] = '*';
    }
}
int* CalculaPosSoma(Obra *Quadro, int *posicao){
    //Asterisco central coordenadas
    posicao[0] = NumeroAleatorio(19);
    posicao[1] = NumeroAleatorio(79);
    //Outros asteriscos
    posicao[2] = posicao[0];
    posicao[4] = posicao[0]; // Asterisco esq/dir coordenada linha
    posicao[3] = posicao[1] - 1; // Asterisco esquerda coordenada coluna
    posicao[5] = posicao[1] + 1; // Asterisco direita coordenada coluna

    posicao[7] = posicao[1];
    posicao[9] = posicao[1]; //Asterisco cima/baixo coordenada coluna
    posicao[6] = posicao[0] - 1; //Asterisco em cima coordenada linha
    posicao[8] = posicao[0] + 1; //Asterisco em baixo coordenada linha

    int contador = 0, linha = 0, coluna = 1;
    for(int i=0; i<5; i++){
        if(Quadro->Tela[(posicao[linha])][(posicao[coluna])] != ' '){
            contador ++;
        }
        linha += 2;
        coluna += 2;
    }
    if(contador == 0){
        return posicao;
    }
    else{
        return CalculaPosSoma(Quadro, posicao);
    }
}

void SimboloSoma(Obra *Quadro, int Quantidade){
    int pos2[10];
    int *posicao2;
    posicao2 = pos2;
    if(Quantidade <= 0){//Se o usuário digitar um número menor ou igual a zero, será gerado um número de figuras aleatório entre 1 e 100
        Quantidade = NumeroAleatorio(100);
    }
    else{
        for(int i=0; i<Quantidade; i++){
            CalculaPosSoma(Quadro, posicao2);
            Quadro->Tela[(posicao2[0])][(posicao2[1])] = '*';
            Quadro->Tela[(posicao2[2])][(posicao2[3])] = '*';
            Quadro->Tela[(posicao2[4])][(posicao2[5])] = '*';
            Quadro->Tela[(posicao2[6])][(posicao2[7])] = '*';
            Quadro->Tela[(posicao2[8])][(posicao2[9])] = '*';
        }
    }
}
