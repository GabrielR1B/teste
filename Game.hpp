#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>

/**
 * @class Game
 * @brief Classe base que representa um jogo genérico.
 */
class Game {
protected:
    std::vector<std::vector<char>> board; ///< O tabuleiro do jogo.
    int rows; ///< Número de linhas no tabuleiro.
    int cols; ///< Número de colunas no tabuleiro.

public:
    /**
     * @brief Construtor que inicializa o jogo com um número especificado de linhas e colunas.
     * @param rows Número de linhas no tabuleiro.
     * @param cols Número de colunas no tabuleiro.
     */
    Game(int rows, int cols);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Game();

    /**
     * @brief Imprime o estado atual do tabuleiro.
     */
    virtual void printBoard() const;

    /**
     * @brief Verifica se a jogada é válida.
     * @param col A coluna onde a jogada será feita.
     * @return Verdadeiro se a jogada é válida, falso caso contrário.
     */
    virtual bool isValidMove(int col) const = 0;

    /**
     * @brief Faz uma jogada, colocando uma peça na coluna especificada.
     * @param col A coluna onde a peça será colocada.
     * @param player A peça do jogador a ser colocada.
     * @return Verdadeiro se a jogada for bem-sucedida, falso caso contrário.
     */
    virtual bool makeMove(int col, char player) = 0;

    /**
     * @brief Verifica se o jogador com a peça especificada ganhou.
     * @param player A peça do jogador a ser verificada.
     * @return Verdadeiro se o jogador ganhou, falso caso contrário.
     */
    virtual bool checkWin(char player) const = 0;

    /**
     * @brief Verifica se o tabuleiro está cheio.
     * @return Verdadeiro se o tabuleiro estiver cheio, falso caso contrário.
     */
    virtual bool isBoardFull() const;

    /**
     * @brief Reseta o tabuleiro para o estado inicial.
     */
    virtual void resetBoard();
};

#endif // GAME_HPP
