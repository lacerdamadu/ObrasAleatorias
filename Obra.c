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
    else if(Limite == 3){
        return rand() % 3;
    }
    else{//Gera numero aleatorio de figuras
        return rand() % 100;
    }
}
int VerificaCheia(Obra *Quadro){
    int contador = 0;
    for(int i=0; i<20; i++){
        for(int j=0; j<80; j++){
            if(Quadro->Tela[i][j] == ' '){
                contador++;
            }
        }
    }
    if(contador != 0){
        return 0;
    }
    else{
        return 1;
    }
}
int* CalculaPosSimples(Obra *Quadro, int *posicao){
    posicao[0] = NumeroAleatorio(19);
    posicao[1] = NumeroAleatorio(79);
    if((Quadro->Tela[(posicao[0])][(posicao[1])]) == ' '){
        return posicao;
    }
    else{
        if(VerificaCheia(Quadro)){
            posicao[0] = -1;
            return posicao;
        }
        else{
            return CalculaPosSimples(Quadro, posicao);
        }
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
        if(posicao[0] == -1){
            return;
        }
        else{
        Quadro->Tela[(posicao[0])][(posicao[1])] = '*';
        }
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
        if(VerificaCheia(Quadro)){
            posicao[0] = -1;
            return posicao;
        }
        else{
            return CalculaPosSoma(Quadro, posicao);
        }
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
            if(posicao2[0] == -1){
                return;
            }
            else{
                Quadro->Tela[(posicao2[0])][(posicao2[1])] = '*';
                Quadro->Tela[(posicao2[2])][(posicao2[3])] = '*';
                Quadro->Tela[(posicao2[4])][(posicao2[5])] = '*';
                Quadro->Tela[(posicao2[6])][(posicao2[7])] = '*';
                Quadro->Tela[(posicao2[8])][(posicao2[9])] = '*';
            }
        }
    }
}
int* CalculaPosX(Obra *Quadro, int *posicao){
    //Asterisco central coordenadas
    posicao[0] = NumeroAleatorio(19);
    posicao[1] = NumeroAleatorio(79);
    //Outros asteriscos
    posicao[2] = posicao[0] - 1;
    posicao[3] = posicao[1] - 1;
    posicao[4] = posicao[0] - 1;
    posicao[5] = posicao[1] + 1;
    posicao[6] = posicao[0] + 1;
    posicao[7] = posicao[1] - 1;
    posicao[8] = posicao[0] + 1;
    posicao[9] = posicao[1] + 1;

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
        if(VerificaCheia(Quadro)){
            posicao[0] = -1;
            return posicao;
        }
        else{
            return CalculaPosX(Quadro, posicao);
        }
    }
}
void SimboloX(Obra *Quadro, int Quantidade){
    int pos3[10];
    int *posicao3;
    posicao3 = pos3;
    if(Quantidade <= 0){//Se o usuário digitar um número menor ou igual a zero, será gerado um número de figuras aleatório entre 1 e 100
        Quantidade = NumeroAleatorio(100);
    }
    else{
        for(int i=0; i<Quantidade; i++){
            CalculaPosX(Quadro, posicao3);
            if(posicao3[0] == -1){
                return;
            }
            else{
                Quadro->Tela[(posicao3[0])][(posicao3[1])] = '*';
                Quadro->Tela[(posicao3[2])][(posicao3[3])] = '*';
                Quadro->Tela[(posicao3[4])][(posicao3[5])] = '*';
                Quadro->Tela[(posicao3[6])][(posicao3[7])] = '*';
                Quadro->Tela[(posicao3[8])][(posicao3[9])] = '*';
            }
        }
    }
}

void Aleatorio(Obra *Quadro, int Quantidade){
    if (Quantidade <= 0) {
        Quantidade = NumeroAleatorio(100); // Se for aleatório, define uma quantidade
    }
    int totaldefiguras = 0;
    while (totaldefiguras < Quantidade) {
        int opcao = rand() % 3;
        int restante = Quantidade - totaldefiguras;
        int NumFigurasAtual;
        if (restante > 1) {
            NumFigurasAtual = (rand() % restante) + 1;
        } else {
            NumFigurasAtual = 1;
        }
        switch (opcao) {
            case 0:
                AsteriscoSimples(Quadro, NumFigurasAtual);
                break;
            case 1:
                SimboloSoma(Quadro, NumFigurasAtual);
                break;
            case 2:
                SimboloX(Quadro, NumFigurasAtual);
                break;
        }
        totaldefiguras += NumFigurasAtual;
    }
}
int* CalculaPosGatinho(Obra *Quadro, int *posicao){
    //Coordenadas "."
    posicao[0] = NumeroAleatorio(19);
    posicao[1] = NumeroAleatorio(79);
    //Coordenadas "*"
    posicao[2] = posicao[0]; //Direita
    posicao[3] = posicao[1] + 1;
    posicao[4] = posicao[0]; //Esquerda
    posicao[5] = posicao[1] -1 ;
    //Coordenada "="
    posicao[6] = posicao[0]; //Direita
    posicao[7] = posicao[1] + 2;
    posicao[8] = posicao[0]; //Esquerda
    posicao[9] = posicao[1] - 2;
    //Coordenada "()"
    posicao[10] = posicao[0]; //Direita
    posicao[11] = posicao[1] + 3;
    posicao[12] = posicao[0]; //Esquerda
    posicao[13] = posicao[1] - 3;
    //Coordenada "_"
    posicao[14] = posicao[0] - 1; //Central
    posicao[15] = posicao[1];
    posicao[16] = posicao[0] - 1; //Direita
    posicao[17] = posicao[1] + 1;
    posicao[18] = posicao[0] - 1; //Esquerda
    posicao[19] = posicao[1] - 1;
    //Coordenada "/\"
    posicao[20] = posicao[0] - 1; //Direita 1
    posicao[21] = posicao[1] + 2;
    posicao[22] = posicao[0] - 1; //Direita 2
    posicao[23] = posicao[1] + 3;
    posicao[24] = posicao[0] - 1; //Esquerda 1
    posicao[25] = posicao[1] - 2;
    posicao[26] = posicao[0] - 1; //Esquerda 2
    posicao[27] = posicao[1] - 3;
    

    int contador = 0, linha = 0, coluna = 1;
    for(int i=0; i<14; i++){
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
        if(VerificaCheia(Quadro)){
            posicao[0] = -1;
            return posicao;
        }
        else{
            return CalculaPosGatinho(Quadro, posicao);
        }
    }

}
void Gatinho(Obra *Quadro, int Quantidade){
    int pos[28];
    int *posicao;
    posicao = pos;
    if(Quantidade <= 0){//Se o usuário digitar um número menor ou igual a zero, será gerado um número de figuras aleatório entre 1 e 100
        Quantidade = NumeroAleatorio(100);
    }
    else{
        for(int i=0; i<Quantidade; i++){
            CalculaPosGatinho(Quadro, posicao);
            if(posicao[0] == -1){
                return;
            }
            else{
                Quadro->Tela[(posicao[0])][(posicao[1])] = '.';
                Quadro->Tela[(posicao[2])][(posicao[3])] = '*';
                Quadro->Tela[(posicao[4])][(posicao[5])] = '*';
                Quadro->Tela[(posicao[6])][(posicao[7])] = '=';
                Quadro->Tela[(posicao[8])][(posicao[9])] = '=';
                Quadro->Tela[(posicao[10])][(posicao[11])] = ')';
                Quadro->Tela[(posicao[12])][(posicao[13])] = '(';
                Quadro->Tela[(posicao[14])][(posicao[15])] = '_';
                Quadro->Tela[(posicao[16])][(posicao[17])] = '_';
                Quadro->Tela[(posicao[18])][(posicao[19])] = '_';
                Quadro->Tela[(posicao[20])][(posicao[21])] = '/';
                Quadro->Tela[(posicao[22])][(posicao[23])] = '\\';
                Quadro->Tela[(posicao[24])][(posicao[25])] = '\\';
                Quadro->Tela[(posicao[26])][(posicao[27])] = '/';
            }
        }
    }
}
int* CalculaPosCoracao(Obra *Quadro, int *posicao){
    //Simbolo "<"
    posicao[0] = NumeroAleatorio(19);
    posicao[1] = NumeroAleatorio(79);
    //Simbolo "3"
    posicao[2] = posicao[0];
    posicao[3] = posicao[1] + 1;

    int contador = 0, linha = 0, coluna = 1;
    for(int i=0; i<2; i++){
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
        if(VerificaCheia(Quadro)){
            posicao[0] = -1;
            return posicao;
        }
        else{
            return CalculaPosCoracao(Quadro, posicao);
        }
    }
}
void Coracao(Obra *Quadro, int Quantidade){
    int pos[4];
    int *posicao;
    posicao = pos;
    if(Quantidade <= 0){//Se o usuário digitar um número menor ou igual a zero, será gerado um número de figuras aleatório entre 1 e 100
        Quantidade = NumeroAleatorio(100);
    }
    for(int i=0; i<Quantidade; i++){
        CalculaPosCoracao(Quadro, posicao);
        if(posicao[0] == -1){
            return;
        }
        else{
        Quadro->Tela[(posicao[0])][(posicao[1])] = '<';
        Quadro->Tela[(posicao[2])][(posicao[3])] = '3';
        }
    }
}

