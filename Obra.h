#ifndef OBRA_H_
#define OBRA_H_
#define VERMELHO "\x1b[31m"
#define RESET "\x1b[0m"
#define LARANJA_GATO    "\x1b[38;5;208m"  
#define MARROM_GATO     "\x1b[38;5;130m"   
#define CREME_GATO      "\x1b[38;5;223m"   
#define PRETO_GATO      "\x1b[38;5;232m"   
#define BRANCO_GATO     "\x1b[38;5;255m"   
#define CINZA_GATO      "\x1b[38;5;245m" 
#define FUNDO_BRANCO    "\x1b[47m"  
#define AMARELO_OLHO    "\x1b[38;5;220m"   
#define VERDE_OLHO      "\x1b[38;5;46m"    
#define AZUL_OLHO       "\x1b[38;5;33m"   

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
void ImprimiColorido(Obra Quadro);

#endif