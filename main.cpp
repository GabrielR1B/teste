#include "ConnectFour.hpp"
#include <iostream>
#include <string>

/**
 * @brief Função para verificar se a string contém apenas dígitos.
 * @param str A string a ser verificada.
 * @return Verdadeiro se a string contém apenas dígitos, falso caso contrário.
 */
bool isNumber(const std::string& str) {
    for (char c : str) {
        if (c < '0' || c > '9') { // Verifica se o caractere não está entre '0' e '9'
            return false;
        }
    }
    return !str.empty(); // Retorna falso se a string estiver vazia
}

/**
 * @brief Função para validar a entrada numérica dentro de um intervalo.
 * @param input A entrada como string.
 * @param min O valor mínimo do intervalo.
 * @param max O valor máximo do intervalo.
 * @return Verdadeiro se a entrada está dentro do intervalo, falso caso contrário.
 */
bool isValidInput(const std::string& input, int min, int max) {
    if (!isNumber(input)) {
        return false;
    }
    int value = std::stoi(input);
    return value >= min && value <= max;
}

/**
 * @brief Função para obter a escolha do tamanho do tabuleiro pelo usuário.
 * @return O tamanho escolhido do tabuleiro.
 */
int getBoardSizeChoice() {
    std::string choice;
    std::cout << "Escolha o tamanho do Tabuleiro:\n";
    std::cout << "1. 6x6\n";
    std::cout << "2. 6x7\n";
    std::cout << "3. 6x8\n";
    std::cout << "Digite o número da opção desejada: ";
    std::getline(std::cin, choice);

    while (!isValidInput(choice, 1, 3)) {
        std::cout << "ERRO: Entrada inválida. Digite um número de 1 a 3.\n";
        std::cout << "Escolha o tamanho do grid:\n";
        std::cout << "1. 6x6\n";
        std::cout << "2. 6x7\n";
        std::cout << "3. 6x8\n";
        std::cout << "Digite o número da opção desejada: ";
        std::getline(std::cin, choice);
    }

    return std::stoi(choice);
}

/**
 * @brief Função principal que executa o jogo Connect Four.
 * @return Código de status da aplicação.
 */
int main() {
    int choice = getBoardSizeChoice();
    int rows, cols;

    switch (choice) {
        case 1:
            rows = 6;
            cols = 6;
            break;
        case 2:
            rows = 6;
            cols = 7;
            break;
        case 3:
            rows = 6;
            cols = 8;
            break;
        default:
            std::cerr << "ERRO: Escolha de tamanho inválida.\n";
            return 1;
    }

    ConnectFour game(rows, cols);

    std::string currentPlayer = "João";
    char currentPiece = 'X';

    while (true) {
        game.printBoard(currentPiece);

        std::cout << "Turno de " << currentPlayer << " (" << currentPiece << "): ";
        std::string input;
        std::getline(std::cin, input);

        if (!isValidInput(input, 1, cols) || !game.makeMove(std::stoi(input), currentPiece)) {
            std::cout << "ERRO: Jogada inválida ou coluna cheia\n";
            continue;
        }

        if (game.checkWin(currentPiece)) {
            game.printBoard(currentPiece);
            std::cout << "Parabéns " << currentPlayer << "! Você venceu!\n";
            break;
        }

        if (game.isBoardFull()) {
            game.printBoard(currentPiece);
            std::cout << "O jogo terminou em empate!\n";
            break;
        }

        currentPlayer = (currentPlayer == "João") ? "Maria" : "João";
        currentPiece = (currentPiece == 'X') ? 'O' : 'X';
    }

    return 0;
}
