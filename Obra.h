#ifndef OBRA_H_
#define OBRA_H_

typedef struct  Obra{
    char Tela[20][80];
} Obra;

void InicializaObra(Obra *Quadro);
void ImprimiObra(Obra Quadro);
int NumeroAleatório(int Limite);
void AsteriscoSimples(Obra *Quadro, int Quantidade);
int* CalculaPos(Obra *Quadro, int *posicao);

#endif