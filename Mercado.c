#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> 
#include "Stack.h"
#include "Queue.h"
#include "Funcoes.h"

int main() {
    srand(time(NULL));
    
    Queue fila = construct_queue();
    int hora = 8;
    int clienteID = 1;

    while (hora <= 22) {
        int idxHora = hora - 8;
        printf("\nHora atual: %02d:00\n", hora);

        if (clienteChegou(hora)) {
            Enqueue(&fila, clienteID);
            printf("Cliente_%d entrou na fila.\n", clienteID++);
        }

        if (fila.size > maxFila)
            maxFila = fila.size;

        if (fila.size > 0 && clienteDesistiu()) {
            int desistente = Dequeue(&fila);
            printf("Cliente_%d desistiu da fila.\n", desistente);
            totalDesistentes++;
            movimento[idxHora][1]++;
        }

        if (fila.size > 0) {
            int atendido = Dequeue(&fila);
            Cliente c;
            sprintf(c.nome, "Cliente_%d", atendido);
            c.qtdItens = rand() % MAX_ITENS + 1;
            clientesAtendidos[totalAtendidos++] = c;
            movimento[idxHora][0]++;

            printf("Atendendo %s com %d itens...\n", c.nome, c.qtdItens);

            Stack carrinho = construct_stack();
            Item* lista = NULL;

            for (int i = 0; i < c.qtdItens; i++) {
                Push(&carrinho, i + 1);
                char nomeItem[30];
                sprintf(nomeItem, "Item_%d", i + 1);
                lista = adicionarItem(lista, nomeItem);
                printf(" %s Adicionado ao carrinho.\n", nomeItem);
            }

            printf("Passando itens no caixa:\n");
            while (carrinho.size > 0) {
                int item = Pop(&carrinho);
                printf(" - Item_%d\n", item);
            }

            liberarLista(lista);
            Destruct(&carrinho);
            printf("Compra finalizada para %s.\n", c.nome);
        }

        printf("Pessoas na fila: %d\n", fila.size);
        sleep(1);
        hora++;
    }

    gerarRelatorioDoDia();
    Destruct_(&fila);
    printf("\nFim da simulação.\n");
    return 0;
}