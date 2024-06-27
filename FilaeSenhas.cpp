#include <iostream> // Biblioteca para entrada e saída padrão
#include <queue> // Biblioteca para a estrutura de dados de fila (queue) ila em inglês ("queue" = fila), que o obedece o príncipio FIFO (First in First Out)

int main() {
    // Declaração das filas para senhas geradas e atendidas
    std::queue<std::string> senhasGeradas;
    std::queue<std::string> senhasAtendidas;

    // Loop principal do programa
    while (true) {
        // Exibe o menu de opções
        std::cout << "Selecione uma opção:\n";
        std::cout << "0. Sair\n";
        std::cout << "1. Gerar senha\n";
        std::cout << "2. Realizar atendimento\n";

        int opcao; // Variável para armazenar a opção do usuário
        std::cin >> opcao; // Lê a opção do usuário

        // Verifica a opção escolhida
        if (opcao == 0) {
            // Se a opção for 0, sai do loop e encerra o programa
            break;
        } else if (opcao == 1) {
            // Se a opção for 1, gera uma nova senha
            std::string senha = "Senha" + std::to_string(senhasGeradas.size() + 1); // Cria a senha com base no tamanho da fila
            senhasGeradas.push(senha); // Adiciona a senha gerada na fila de senhas geradas
            std::cout << "Senha gerada: " << senha << "\n"; // Exibe a senha gerada
        } else if (opcao == 2) {
            // Se a opção for 2, realiza o atendimento de uma senha
            if (!senhasGeradas.empty()) {
                // Se houver senhas aguardando atendimento
                std::string senhaAtendida = senhasGeradas.front(); // Obtém a senha da frente da fila
                senhasGeradas.pop(); // Remove a senha da fila de senhas geradas
                senhasAtendidas.push(senhaAtendida); // Adiciona a senha na fila de senhas atendidas
                std::cout << "Atendimento realizado para a senha: " << senhaAtendida << "\n"; // Exibe a senha atendida
            } else {
                // Se não houver senhas aguardando atendimento
                std::cout << "Nenhuma senha aguardando atendimento.\n"; // Informa que não há senhas para atender
            }
        } else {
            // Se a opção for inválida
            std::cout << "Opção inválida. Tente novamente.\n"; // Informa que a opção é inválida
        }
    }

    // Após sair do loop, exibe o total de senhas atendidas
    std::cout << "Total de senhas atendidas: " << senhasAtendidas.size() << "\n";

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}


    std::cout << "Total de senhas atendidas: " << senhasAtendidas.size() << "\n";

    return 0;
}
