#ifndef OBRA_H_
#define OBRA_H_

typedef struct  Obra{
    char Tela[20][80];
} Obra;

void InicializaObra(Obra *Quadro);
void ImprimiObra(Obra Quadro);
int NumeroAleatorio(int Limite);
int VerificaCheia(Obra *Quadro);

//Funções utilizadas na criação da opção 1
void AsteriscoSimples(Obra *Quadro, int Quantidade);
int* CalculaPosSimples(Obra *Quadro, int *posicao);

//Funções utilizadas na criação da opção 2
void SimboloSoma(Obra *Quadro, int Quantidade);
int* CalculaPosSoma(Obra *Quadro, int *posicao);

//Funções utilizadas na criação da opção 3
void SimboloX(Obra *Quadro, int Quantidade);
int* CalculaPosX(Obra *Quadro, int *posicao);

//Funções utilizadas na criação da opção 4
void Aleatorio(Obra *Quadro, int Quantidade);

//Funções utilizadas na criação da opção 5
void Gatinho(Obra *Quadro, int Quantidade);
void Coracao(Obra *Quadro, int Quantidade);
int* CalculaPosCoracao(Obra *Quadro, int *posicao);
int* CalculaPosGatinho(Obra *Quadro, int *posicao);
#endif