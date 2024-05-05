#include <iostream>
#include <locale.h>

using namespace std;

// Definição da estrutura do nó para a lista encadeada
struct No {
    int dado;          // Valor do nó
    struct No *prox;   // Ponteiro para o próximo nó
};

// Definição da estrutura da pilha
struct Pilha {
    No *topo;   // Ponteiro para o topo da pilha
};

// Função para inicializar a pilha
Pilha* init() {
    Pilha *p = new Pilha;
    p->topo = NULL;
    return p;
}

// Função para verificar se a pilha está vazia
int isEmpty(Pilha *p) {
    return (p->topo == NULL);
}

// Função para contar o número de elementos na pilha
int count(Pilha *p) {
    int i = 0;
    No *no;
    no = p->topo;
    while (no != NULL) {
        i++;
        no = no->prox;
    }
    return i;
}

// Função para imprimir os elementos da pilha
void print(Pilha *p) {
    No *no;
    no = p->topo;
    cout << "Qtde de elementos: " << count(p) << endl;
    while (no != NULL) {
        cout << no->dado << endl;
        no = no->prox;
    }
    cout << "--------------------" << endl;
}

// Função para liberar a memória ocupada pela pilha
void freePilha(Pilha *p) {
    No *no;
    no = p->topo;
    while (no != NULL) {
        No *aux = no->prox;
        delete no;
        no = aux;
    }
    delete p;
}

// Função para inserir um elemento na pilha
void push(Pilha *p, int v) {
    No *no = new No;
    no->dado = v;
    no->prox = p->topo;
    p->topo = no;
}

// Função para remover e retornar o elemento do topo da pilha
int pop(Pilha *p) {
    int v;
    int podeDesempilhar = (p->topo != NULL);
    if (podeDesempilhar) {
        No *no = p->topo;
        v = no->dado;
        p->topo = no->prox;
        delete no;
    }
    else {
        v = -1;
    }
    return v;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");
    Pilha *pilhaPar = init();    // Pilha para números pares
    Pilha *pilhaImpar = init();  // Pilha para números ímpares

    // Solicitação e validação dos 30 números inteiros em ordem crescente
    int previousNumber = 0;
    cout << "Digite 30 números inteiros em ordem crescente:\n";
    for (int i = 0; i < 30; i++) {
        int currentNumber;
        cout << "Número " << i + 1 << ": ";
        cin >> currentNumber;

        // Verifica se o número é maior do que o anterior
        if (currentNumber <= previousNumber) {
            cout << "Erro: O número deve ser maior do que o anterior." << endl;
            i--;  // Decrementa o índice para tentar novamente
            continue;  // Volta ao início do loop para corrigir o valor inserido
        }

        previousNumber = currentNumber;  // Atualiza o número anterior

        // Empilha o número na pilha apropriada (par ou ímpar)
        if (currentNumber % 2 == 0) {
            push(pilhaPar, currentNumber);
        } else {
            push(pilhaImpar, currentNumber);
        }
    }

    // Desempilha e exibe os valores em ordem decrescente
    cout << "\nNúmeros pares em ordem decrescente:\n";
    while (!isEmpty(pilhaPar)) {
        cout << pop(pilhaPar) << " ";
    }

    cout << "\nNúmeros ímpares em ordem decrescente:\n";
    while (!isEmpty(pilhaImpar)) {
        cout << pop(pilhaImpar) << " ";
    }

    cout << endl;

    // Libera a memória ocupada pelas pilhas
    freePilha(pilhaPar);
    freePilha(pilhaImpar);

    return 0;
}

