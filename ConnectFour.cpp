#include "ConnectFour.hpp"
#include <iostream>

/**
 * @brief Construtor que inicializa o jogo de Connect Four com um número especificado de linhas e colunas.
 * @param rows Número de linhas no tabuleiro.
 * @param cols Número de colunas no tabuleiro.
 */
ConnectFour::ConnectFour(int rows, int cols) : rows(rows), cols(cols), board(rows, std::vector<char>(cols, ' ')) {}

/**
 * @brief Imprime o estado atual do tabuleiro.
 * @param currentPiece A peça ('X' ou 'O') a ser impressa.
 */
void ConnectFour::printBoard(char currentPiece) const {
    std::cout << "Tabuleiro:\n";
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << (cell == ' ' ? '.' : cell) << ' ';
        }
        std::cout << '\n';
    }
}

/**
 * @brief Faz uma jogada, colocando uma peça na coluna especificada.
 * @param col A coluna onde a peça será colocada.
 * @param piece A peça ('X' ou 'O') a ser colocada.
 * @return Verdadeiro se a jogada for válida, falso caso contrário.
 */
bool ConnectFour::makeMove(int col, char piece) {
    if (col < 1 || col > cols) {
        return false;
    }
    col--; // Ajustar para índice 0
    for (int row = rows - 1; row >= 0; row--) {
        if (board[row][col] == ' ') {
            board[row][col] = piece;
            return true;
        }
    }
    return false;
}

/**
 * @brief Verifica se o jogador com a peça especificada ganhou.
 * @param piece A peça ('X' ou 'O') do jogador a ser verificado.
 * @return Verdadeiro se o jogador ganhou, falso caso contrário.
 */
bool ConnectFour::checkWin(char piece) const {
    // Verificar todas as direções para cada célula do tabuleiro
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (board[row][col] == piece) {
                if (checkDirection(row, col, 1, 0, piece) || // Vertical
                    checkDirection(row, col, 0, 1, piece) || // Horizontal
                    checkDirection(row, col, 1, 1, piece) || // Diagonal crescente
                    checkDirection(row, col, 1, -1, piece)) { // Diagonal decrescente
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * @brief Verifica se há quatro peças consecutivas em linha na direção especificada.
 * @param startRow Linha inicial.
 * @param startCol Coluna inicial.
 * @param deltaRow Incremento de linha para a direção.
 * @param deltaCol Incremento de coluna para a direção.
 * @param piece A peça ('X' ou 'O') a ser verificada.
 * @return Verdadeiro se há quatro peças consecutivas, falso caso contrário.
 */
bool ConnectFour::checkDirection(int startRow, int startCol, int deltaRow, int deltaCol, char piece) const {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int row = startRow + i * deltaRow;
        int col = startCol + i * deltaCol;
        if (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == piece) {
            count++;
        } else {
            break;
        }
    }
    return count == 4;
}

/**
 * @brief Verifica se o tabuleiro está cheio.
 * @return Verdadeiro se o tabuleiro estiver cheio, falso caso contrário.
 */
bool ConnectFour::isBoardFull() const {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}
