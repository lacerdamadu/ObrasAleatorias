#ifndef OBRA_H_
#define OBRA_H_

typedef struct  Obra{
    char Tela[20][80];
} Obra;

void InicializaObra(Obra *Quadro);
void ImprimiObra(Obra Quadro);
int NumeroAleatório(int Limite);

//Funções utilizadas na criação da opção 1
void AsteriscoSimples(Obra *Quadro, int Quantidade);
int* CalculaPosSimples(Obra *Quadro, int *posicao);

//Funções utilizadas na criação da opção 2
void SimboloSoma(Obra *Quadro, int Quantidade);
int* CalculaPosSoma(Obra *Quadro, int *posicao);

#endif