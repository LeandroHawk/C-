#include <iostream>
#include <queue>

int main() {
    std::queue<std::string> senhasGeradas;
    std::queue<std::string> senhasAtendidas;

    while (true) {
        std::cout << "Selecione uma opção:\n";
        std::cout << "0. Sair\n";
        std::cout << "1. Gerar senha\n";
        std::cout << "2. Realizar atendimento\n";

        int opcao;
        std::cin >> opcao;

        if (opcao == 0) {
            break;
        } else if (opcao == 1) {
            // Gerar senha
            std::string senha = "Senha" + std::to_string(senhasGeradas.size() + 1);
            senhasGeradas.push(senha);
            std::cout << "Senha gerada: " << senha << "\n";
        } else if (opcao == 2) {
            // Realizar atendimento
            if (!senhasGeradas.empty()) {
                std::string senhaAtendida = senhasGeradas.front();
                senhasGeradas.pop();
                senhasAtendidas.push(senhaAtendida);
                std::cout << "Atendimento realizado para a senha: " << senhaAtendida << "\n";
            } else {
                std::cout << "Nenhuma senha aguardando atendimento.\n";
            }
        } else {
            std::cout << "Opção inválida. Tente novamente.\n";
        }
    }

    std::cout << "Total de senhas atendidas: " << senhasAtendidas.size() << "\n";

    return 0;
}
