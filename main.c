#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Queue.h"
#include "Stack.h"

typedef struct Cliente {
    char nome[50];
    int qtdItens;
} Cliente;

typedef struct Item {
    char nome[30];
    struct Item* prox;
} Item;

int entrarFila (int hora) {
    if (hora < 17)  {
        return rand() % 100 < 30;
    } else {
        return rand() % 100 < 70;
    }
}

int desistirFila () {
    return rand() % 100 < 10;
}

int main() { 
    int max_clientes = 100;
    Cliente clientesAtendidos[max_clientes];
    int totalAtendidos = 0;
    int totalDesistentes = 0;
    int maxFila = 0;
    int movimentoPorHora[15][2];

    Queue fila = construct_queue();
    int hora = 8;
    int clienteID = 1;
}