#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef Funcoes_h
#define Funcoes_h

#define MAX_ITENS 5

typedef struct Cliente {
    char nome[50];
    int qtdItens;
} Cliente;

typedef struct Item {
    char nome[30];
    struct Item* prox;
} Item;

Cliente clientesAtendidos[100];
int totalAtendidos = 0;
int totalDesistentes = 0;
int maxFila = 0;
int movimento[15][2]; 

int clienteDesistiu() {
    return rand() % 100 < 10;
}

int clienteChegou(int hora) {
    if (hora < 17) return rand() % 100 < 30;
    else return rand() % 100 < 70;
}

Item* adicionarItem(Item* lista, char* nome) {
    Item* novo = (Item*)malloc(sizeof(Item));
    strcpy(novo->nome, nome);
    novo->prox = lista;
    return novo;
}

void liberarLista(Item* lista) {
    while (lista) {
        Item* tmp = lista;
        lista = lista->prox;
        free(tmp);
    }
}

void gerarRelatorioDoDia() {
    FILE* arq = fopen("relatorio_do_dia.txt", "w");
    if (!arq) {
        printf("Erro ao criar relatório!\n");
        return;
    }

    fprintf(arq, "=== RELATORIO DO DIA - SUPERMERCADO GULINHA 😋 ===\n");
    fprintf(arq, "Clientes atendidos: %d\n", totalAtendidos);
    fprintf(arq, "Clientes que desistiram: %d\n", totalDesistentes);
    fprintf(arq, "Maior tamanho da fila: %d\n\n", maxFila);

    fprintf(arq, "Movimento por hora:\n");
    for (int i = 0; i < 15; i++) {
        fprintf(arq, "Hora %02d:00 - Atendidos: %d, Desistentes: %d\n", i + 8, movimento[i][0], movimento[i][1]);
    }

    fprintf(arq, "\nLista de clientes atendidos:\n");
    for (int i = 0; i < totalAtendidos; i++) {
        fprintf(arq, "- %s: %d itens\n", clientesAtendidos[i].nome, clientesAtendidos[i].qtdItens);
    }

    fclose(arq);
    printf("\nRelatório do dia salvo em 'relatorio_do_dia.txt'\n");
}
#endif