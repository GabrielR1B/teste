#include "Game.hpp"
#include <iostream>
#include <algorithm>

/**
 * @brief Construtor que inicializa o jogo com um número especificado de linhas e colunas.
 * @param rows Número de linhas no tabuleiro.
 * @param cols Número de colunas no tabuleiro.
 */
Game::Game(int rows, int cols) : rows(rows), cols(cols) {
    board.resize(rows, std::vector<char>(cols, ' '));
}

/**
 * @brief Destrutor virtual.
 */
Game::~Game() {}

/**
 * @brief Imprime o estado atual do tabuleiro.
 */
void Game::printBoard() const {
    std::cout << "  ";
    for (int col = 1; col <= cols; ++col) {
        std::cout << " " << col << "  ";
    }
    std::cout << "\n";

    for (const auto& row : board) {
        std::cout << "| ";
        for (char cell : row) {
            std::cout << cell << " | ";
        }
        std::cout << "\n";
    }
    std::cout << std::string(cols * 4 + 2, '-') << '\n';
}

/**
 * @brief Verifica se o tabuleiro está cheio.
 * @return Verdadeiro se o tabuleiro estiver cheio, falso caso contrário.
 */
bool Game::isBoardFull() const {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

/**
 * @brief Reseta o tabuleiro para o estado inicial.
 */
void Game::resetBoard() {
    for (auto& row : board) {
        std::fill(row.begin(), row.end(), ' ');
    }
}
