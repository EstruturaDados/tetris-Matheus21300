#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//STRUCT DA PEÇA 
typedef struct {
    char nome;  // 'I', 'O', 'T', 'L'
    int id;     // número único de criação
} Peca;

//CONFIGURAÇÃO DA FILA 
#define TAM 10   // tamanho máximo da fila

Peca fila[TAM];
int inicio = 0;     // posição inicial da fila
int fim = 0;        // posição final (próxima posição livre)
int qtd = 0;        // quantidade de peças na fila

int proximoID = 0;  // contador global que garante IDs únicos

//GERA UMA PEÇA ALEATÓRIA 
Peca gerarPeca() {
    char tipos[4] = {'I', 'O', 'T', 'L'};
    Peca p;
    p.nome = tipos[rand() % 4];
    p.id = proximoID++;
    return p;
}

//ENQUEUE: INSERE PEÇA
void inserirPeca() {
    if (qtd == TAM) {
        printf("A fila está cheia! Não é possível inserir.\n");
        return;
    }

    fila[fim] = gerarPeca();    // gera peça e coloca na fila
    fim = (fim + 1) % TAM;      // avança circularmente
    qtd++;

    printf("Peça inserida!\n");
}

//DEQUEUE: REMOVE PEÇA
void jogarPeca() {
    if (qtd == 0) {
        printf("A fila está vazia! Nao ha peca para jogar.\n");
        return;
    }

    Peca removida = fila[inicio];
    inicio = (inicio + 1) % TAM; // avança circularmente
    qtd--;

    printf("Peça jogada: [%c %d]\n", removida.nome, removida.id);
}

// MOSTRA TODA A FILA
void mostrarFila() {
    printf("\nConfira a seguir seu estado:\n\n");
    printf("Fila de peças\n");

    if (qtd == 0) {
        printf("(vazia)\n");
        return;
    }

    int i = inicio;
    for (int c = 0; c < qtd; c++) {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
        i = (i + 1) % TAM;
    }

    printf("\n\nItens: %d/%d\n", qtd, TAM);
}

//MENU PRINCIPAL
int main() {
    srand(time(NULL));

    
    for (int i = 0; i < 5; i++)  // inicia a fila com 5 peças
        inserirPeca();

    int opc;

    do {
        mostrarFila();

        printf("\nOpções de ação:\n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                jogarPeca();
                break;
            case 2:
                inserirPeca();
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opc != 0);

    return 0;
}
