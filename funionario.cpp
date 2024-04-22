#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

struct Funcionario {
    int prontuario;
    string nome;
    double salario;
    Funcionario* prox;
};

Funcionario* init() {
    return nullptr;
}

bool isEmpty(Funcionario* lista) {
    return lista == nullptr;
}

Funcionario* insert(Funcionario* lista, int prontuario, string nome, double salario) {
    Funcionario* novo = new Funcionario();
    novo->prontuario = prontuario;
    novo->nome = nome;
    novo->salario = salario;
    novo->prox = lista;
    return novo;
}

void print(Funcionario* lista) {
    Funcionario* aux = lista;
    double totalSalarios = 0.0;
    while (aux != nullptr) {
        cout << "Prontuário: " << aux->prontuario << ", Nome: " << aux->nome << ", Salário: " << aux->salario << endl;
        totalSalarios += aux->salario;
        aux = aux->prox;
    }
    cout << "Total dos salários: " << totalSalarios << endl;
}

Funcionario* find(Funcionario* lista, int prontuario) {
    Funcionario* aux = lista;
    while (aux != nullptr && aux->prontuario != prontuario) {
        aux = aux->prox;
    }
    return aux;
}

Funcionario* remove(Funcionario* lista, int prontuario) {
    Funcionario* aux = lista;
    Funcionario* ant = nullptr;

    while (aux != nullptr && aux->prontuario != prontuario) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == nullptr) { // não encontrado
        return lista;
    }

    if (ant == nullptr) { // era o primeiro
        lista = aux->prox;
    } else { // estava no meio
        ant->prox = aux->prox;
    }
    delete aux;
    return lista;
}

void freeLista(Funcionario* lista) {
    Funcionario* aux;
    while (lista != nullptr) {
        aux = lista;
        lista = lista->prox;
        delete aux;
    }
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    Funcionario* lista = init();

    int opcao;
    do {
        cout << "Menu:\n"
  		     << "Funcionário\n"
             << "0. Sair\n"
             << "1. Incluir\n"
             << "2. Excluir\n"
             << "3. Pesquisar\n"
             << "4. Listar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Encerrando o programa...\n";
                break;
            case 1: {
                int prontuario;
                string nome;
                double salario;
                cout << "Digite o prontuário do funcionário (Ideal 7 Números): ";
                cin >> prontuario;
                if (find(lista, prontuario) != nullptr) {
                    cout << "Já existe um funcionário com este prontuário.\n";
                    break;
                }
                cout << "Digite o nome do funcionário: ";
                cin >> nome;
                cout << "Digite o salário do funcionário: ";
                cin >> salario;
                lista = insert(lista, prontuario, nome, salario);
                cout << "Funcionário incluído com sucesso.\n";
                break;
            }
            case 2: {
                int prontuario;
                cout << "Digite o prontuário do funcionário a ser excluído: ";
                cin >> prontuario;
                lista = remove(lista, prontuario);
                cout << "Funcionário excluído com sucesso.\n";
                break;
            }
            case 3: {
                int prontuario;
                cout << "Digite o prontuário do funcionário a ser pesquisado: ";
                cin >> prontuario;
                Funcionario* encontrado = find(lista, prontuario);
                if (encontrado != nullptr) {
                    cout << "Prontuário: " << encontrado->prontuario << ", Nome: " << encontrado->nome << ", Salário: " << encontrado->salario << endl;
                } else {
                    cout << "Funcionário não encontrado.\n";
                }
                break;
            }
            case 4:
                if (isEmpty(lista)) {
                    cout << "Lista de funcionários vazia.\n";
                } else {
                    cout << "Lista de funcionários:\n";
                    print(lista);
                }
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 0);

    freeLista(lista);

    return 0;
}

