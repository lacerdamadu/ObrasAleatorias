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
    if(Limite == 18){//Gera numero aleatorio para a linha na tabela
        return rand() % 18;
    }
    else if(Limite == 78){//Gera numero aleatorio para a coluna na tabela
        return rand() % 78;
    }
    else{//Gera numero aleatorio de figuras
        return rand() % 100;
    }
}
int* CalculaPos(Obra *Quadro, int *posicao){
    posicao[0] = NumeroAleatorio(18);
    posicao[1] = NumeroAleatorio(78);
    if((Quadro->Tela[(posicao[0])][(posicao[1])]) == ' '){
        return posicao;
    }
    else{
        return CalculaPos(Quadro, posicao);
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
        CalculaPos(Quadro, posicao);
        Quadro->Tela[(posicao[0])][(posicao[1])] = '*';
    }
}