#ifndef CONNECTFOUR_HPP
#define CONNECTFOUR_HPP

#include <vector>

/**
 * @class ConnectFour
 * @brief Classe que representa um jogo de Connect Four.
 */
class ConnectFour {
public:
    /**
     * @brief Construtor que inicializa o jogo de Connect Four com um número especificado de linhas e colunas.
     * @param rows Número de linhas no tabuleiro.
     * @param cols Número de colunas no tabuleiro.
     */
    ConnectFour(int rows, int cols);

    /**
     * @brief Imprime o estado atual do tabuleiro.
     * @param currentPiece A peça ('X' ou 'O') a ser impressa.
     */
    void printBoard(char currentPiece) const;

    /**
     * @brief Faz uma jogada, colocando uma peça na coluna especificada.
     * @param col A coluna onde a peça será colocada.
     * @param piece A peça ('X' ou 'O') a ser colocada.
     * @return Verdadeiro se a jogada for válida, falso caso contrário.
     */
    bool makeMove(int col, char piece);

    /**
     * @brief Verifica se o jogador com a peça especificada ganhou.
     * @param piece A peça ('X' ou 'O') do jogador a ser verificado.
     * @return Verdadeiro se o jogador ganhou, falso caso contrário.
     */
    bool checkWin(char piece) const;

    /**
     * @brief Verifica se o tabuleiro está cheio.
     * @return Verdadeiro se o tabuleiro estiver cheio, falso caso contrário.
     */
    bool isBoardFull() const;

private:
    int rows; ///< Número de linhas no tabuleiro.
    int cols; ///< Número de colunas no tabuleiro.
    std::vector<std::vector<char>> board; ///< O tabuleiro de jogo.

    /**
     * @brief Verifica se há quatro peças consecutivas em linha na direção especificada.
     * @param startRow Linha inicial.
     * @param startCol Coluna inicial.
     * @param deltaRow Incremento de linha para a direção.
     * @param deltaCol Incremento de coluna para a direção.
     * @param piece A peça ('X' ou 'O') a ser verificada.
     * @return Verdadeiro se há quatro peças consecutivas, falso caso contrário.
     */
    bool checkDirection(int startRow, int startCol, int deltaRow, int deltaCol, char piece) const;
};

#endif // CONNECTFOUR_HPP
