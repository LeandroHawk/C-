#include <iostream>
#include <queue>
#include <list>
#include <vector>

struct Guiche {
    int id;
    std::queue<int> senhasAtendidas;
};

std::queue<int> senhasGeradas;
std::list<Guiche> guiches;
int proxSenha = 1;

void gerarSenha() {
    senhasGeradas.push(proxSenha++);
    std::cout << "Senha gerada: " << proxSenha - 1 << "\n";
}

void abrirGuiche() {
    int id;
    std::cout << "Digite o id do guichê: ";
    std::cin >> id;
    Guiche guiche;
    guiche.id = id;
    guiches.push_back(guiche);
    std::cout << "Guichê " << id << " aberto.\n";
}

void realizarAtendimento() {
    if (senhasGeradas.empty()) {
        std::cout << "Não há senhas a serem atendidas.\n";
        return;
    }

    int id;
    std::cout << "Digite o Número do guichê de Atendimento: ";
    std::cin >> id;

    for (auto& guiche : guiches) {
        if (guiche.id == id) {
            int senha = senhasGeradas.front();
            senhasGeradas.pop();
            guiche.senhasAtendidas.push(senha);
            std::cout << "Guichê " << id << " está atendendo a senha " << senha << "\n";
            return;
        }
    }

    std::cout << "Guichê " << id << " não encontrado.\n";
}

void listarSenhasAtendidas() {
    int id;
    std::cout << "Digite o id do guichê: ";
    std::cin >> id;

    for (const auto& guiche : guiches) {
        if (guiche.id == id) {
            std::cout << "Senhas atendidas pelo guichê " << id << ": ";
            std::queue<int> tempQueue = guiche.senhasAtendidas;
            while (!tempQueue.empty()) {
                std::cout << tempQueue.front() << " ";
                tempQueue.pop();
            }
            std::cout << "\n";
            return;
        }
    }

    std::cout << "Guichê " << id << " não encontrado.\n";
}

void mostrarStatus() {
    std::cout << "Senhas aguardando atendimento: " << senhasGeradas.size() << "\n";
    std::cout << "Guichês abertos: " << guiches.size() << "\n";
}

int main() {
    int opcao;
    do {
        mostrarStatus();
        std::cout << "Selecione uma opção:\n";
        std::cout << "0. Sair\n";
        std::cout << "1. Gerar senha\n";
        std::cout << "2. Abrir guichê\n";
        std::cout << "3. Realizar atendimento\n";
        std::cout << "4. Listar senhas atendidas\n";
        std::cout << "Opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                gerarSenha();
                break;
            case 2:
                abrirGuiche();
                break;
            case 3:
                realizarAtendimento();
                break;
            case 4:
                listarSenhasAtendidas();
                break;
            case 0:
                if (!senhasGeradas.empty()) {
                    std::cout << "Ainda há senhas a serem atendidas.\n";
                    opcao = -1; // força o loop a continuar
                }
                break;
            default:
                std::cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    int totalSenhasAtendidas = 0;
    for (const auto& guiche : guiches) {
        totalSenhasAtendidas += guiche.senhasAtendidas.size();
    }

    std::cout << "Total de senhas atendidas: " << totalSenhasAtendidas << "\n";
    return 0;
}
