?#include <iostream>
#include <iomanip>
#define LIN 15
#define COL 40

using namespace std;


// Definindo constantes
const int NUM_FILEIRAS = 15;
const int POLTRONAS_POR_FILEIRA = 40;
const int PRECO_FILEIRAS[NUM_FILEIRAS] = {50, 50, 50, 50, 50, 30, 30, 30, 30, 30, 15, 15, 15, 15, 15};


// Matriz para representar o teatro
char teatro[NUM_FILEIRAS][POLTRONAS_POR_FILEIRA];


// Vari�veis globais para controle de ocupa��o e faturamento
int lugaresOcupados = 0;
float faturamentoTotal = 0.0;


// Fun��o para inicializar o teatro com lugares vazios
void inicializarTeatro() {
    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            teatro[i][j] = '.';
        }
    }
}


// Fun��o para reservar uma poltrona
void reservarPoltrona() {
    int fileira, poltrona;
    cout << "Digite a fileira (1-" << NUM_FILEIRAS << "): ";
    cin >> fileira;
    cout << "Digite a poltrona (1-" << POLTRONAS_POR_FILEIRA << "): ";
    cin >> poltrona;


    // Verifica se a entrada do usu�rio � v�lida
    if (fileira < 1 || fileira > NUM_FILEIRAS || poltrona < 1 || poltrona > POLTRONAS_POR_FILEIRA) {
        cout << "Entrada inv�lida. Tente novamente." << endl;
        return;
    }


    // Verifica se a poltrona est� ocupada
    if (teatro[fileira - 1][poltrona - 1] == '#') {
        cout << "Esta poltrona j� est� ocupada." << endl;
    } else {
        // Reserva a poltrona e atualiza o faturamento
        teatro[fileira - 1][poltrona - 1] = '#';
        lugaresOcupados++;
        faturamentoTotal += PRECO_FILEIRAS[fileira - 1];
        cout << "Sua poltrona foi Reservada." << endl;
    }
}


// Fun��o para exibir o mapa de ocupa��o
void mostrarMapaOcupacao() {
    cout << "Mapa de ocupa��o do teatro:" << endl;
    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            cout << teatro[i][j];
        }
        cout << endl;
    }
}


// Fun��o para exibir o faturamento
void mostrarFaturamento() {
    cout << "Quantidade de lugares ocupados: " << lugaresOcupados << endl;
    cout << "Valor da bilheteria: R$ " << fixed << setprecision(2) << faturamentoTotal << endl;
}


int main() {
    inicializarTeatro();
    int opcao;
    do {
        cout << "\nSelecione uma op��o:\n";
        cout << "0. Finalizar\n";
        cout << "1. Reservar poltrona\n";
        cout << "2. Mapa de ocupa��o\n";
        cout << "3. Faturamento\n";
        cout << "Op��o: ";
        cin >> opcao;
        
//SwitchCase 
        switch (opcao) {
            case 0:
                cout << "Finalizando o programa.\n";
                break;
            case 1:
                reservarPoltrona();
                break;
            case 2:
                mostrarMapaOcupacao();
                break;
            case 3:
                mostrarFaturamento();
                break;
            default:
                cout << "Op��o inv�lida. Tente novamente." << endl;
        }
    } while (opcao != 0);


    return 0;
}