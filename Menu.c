#include <stdio.h>
#include "Menu.h"

void Central(Obra *Quadro){
    InicializaObra(Quadro);
    int escolha, quantidade;
    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n"
            "=================================\n"
            "Escolha o tipo de figura basica a ser usada para criar a obra:\n"
            "1 - asterisco simples.\n"
            "2 - simbolo de soma com asteriscos.\n"
            "3 - letra X com asteriscos.\n"
            "4 - figuras aleatorias\n"
            "5 - figura surpresa\n");
    printf("Digite o tipo de figura basica desejada:");
    scanf("%d", &escolha);
    printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio):");
    scanf("%d", &quantidade);

    if(quantidade > 100){//Se o usuário digitar um número maior do que 100, será considerado o número 100.
        quantidade = 100;
    }
    
    switch (escolha){
        case 1:
            AsteriscoSimples(Quadro, quantidade);
            ImprimiObra(*Quadro);
            break;
        case 2:
            SimboloSoma(Quadro, quantidade);
            ImprimiObra(*Quadro);
            break;
        case 3:
            SimboloX(Quadro, quantidade);
            ImprimiObra(*Quadro);
            break;
        case 4:
            Aleatorio(Quadro, quantidade);
            ImprimiObra(*Quadro);
            break;
        case 5:
            int quant1 = 0, quant2 = 0;
            if(quantidade % 2 != 0){
                quant1 = quantidade / 2;
                quant2 = quant1 + 1;
            }
            else{
                quant1 = quantidade / 2;
                quant2 = quant1;
            }
            Gatinho(Quadro, quant1);
            Coracao(Quadro, quant2);
            ImprimiObra(*Quadro);
            break;
        default:
            break;
    }
    char c;
    printf("\n");
    scanf("%c", &c);
    printf("Deseja realizar um novo quadro com estes mesmos valores?(S/N):");
    scanf("%c", &c);
    if(c == 'S'){
        InicializaObra(Quadro);
        switch (escolha){
            case 1:
                AsteriscoSimples(Quadro, quantidade);
                ImprimiObra(*Quadro);
                break;
            case 2:
                SimboloSoma(Quadro, quantidade);
                ImprimiObra(*Quadro);
                break;
            case 3:
                SimboloX(Quadro, quantidade);
                ImprimiObra(*Quadro);
                break;
            case 4:
                Aleatorio(Quadro, quantidade);
                ImprimiObra(*Quadro);
                break;
            case 5:
                int quant1 = 0, quant2 = 0;
                if(quantidade % 2 != 0){
                    quant1 = quantidade / 2;
                    quant2 = quant1 + 1;
                }
                else{
                    quant1 = quantidade / 2;
                    quant2 = quant1;
                }
                Gatinho(Quadro, quant1);
                Coracao(Quadro, quant2);
                ImprimiObra(*Quadro);
                break;
            default:
                break;
        }
    }
    
}