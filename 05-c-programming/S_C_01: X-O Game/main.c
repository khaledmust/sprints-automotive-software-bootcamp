#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

/* Define error codes. */
#define SYMBOL_ERROR 1
#define SYMBOL_OK 0

/* Define game state. */
#define WINNING 0
#define DRAW 1
#define CONTINUE 2

#define SYMBOL_X 'X'
#define SYMBOL_Y 'O'

/* Player configuration array. */
uint8_t playerConfig[2];

/* Game board state. */
uint8_t gameBoard[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

/*------------------------------------------------- drawBoard -----
 |  Function drawBoard
 |
 |  Purpose:  Draw the current layout of the board.
 |
 |  Parameters:
 |      *board (IN/OUT) -- A pointer to the board layout.
 |
 |  Returns:
 |      void
 *-------------------------------------------------------------------*/
void drawBoard(uint8_t *board) {
    for (uint8_t i = 0; i < 3; i++) {
        for (uint8_t j = 0; j < 3; j++) {
            printf("%c  ", board[3 * i + j]);
        }
        printf("\n");
    }
}

/*------------------------------------------------- __getSymbol -----
 |  Function __getSymbol
 |
 |  Purpose:  Auxiliary function that prompts the user to select a symbol.
 |
 |  Parameters:
 |      *symbolChoice (IN/OUT) -- A pointer to store the input value.
 |
 |  Returns:
 |      SYMBOL_OK -- The scanned symbol is similar to the defined symbols.
 |      SYMBOL_ERROR -- The scanned symbol is different to the defined symbols.
 *-------------------------------------------------------------------*/
uint8_t __getSymbol(uint8_t *symbolChoice) {
    printf("Choose your symbol (X or O): ");
    scanf("%s", symbolChoice);
    /* Converts the input symbol to upper case. */
    *symbolChoice = toupper(*symbolChoice);
    if (*symbolChoice == SYMBOL_X || *symbolChoice == SYMBOL_Y) {
        return SYMBOL_OK;
    } else {
        return SYMBOL_ERROR;
    }
}

/*------------------------------------------------- setPlayerConfig -----
 |  Function setPlayerConfig
 |
 |  Purpose:  Prompts the user to select a symbol, and store that symbol
 |            in the configuration array.
 |
 |  Parameters:
 |      *symbolChoice (IN/OUT) -- A pointer to the configuration array.
 |
 |  Returns:
 |      void.
 *-------------------------------------------------------------------*/
void setPlayerConfig(uint8_t *configArray) {
    uint8_t state;
    uint8_t symbolChoice;
    /* Keep on prompting player 1 to enter a correct symbol. */
    do {
        state = __getSymbol(&symbolChoice);
    } while (state != SYMBOL_OK);
    /* Store player 1 symbol in the configuration array. */
    configArray[0] = symbolChoice;

    /* Keep on prompting player 2 to enter a correct symbol. */
    do {
        state = __getSymbol(&symbolChoice);
    } while (state != SYMBOL_OK || symbolChoice == configArray[0]);
    /* Store player 2 symbol in the configuration array. */
    configArray[1] = symbolChoice;
}

/*------------------------------------------------- getPlayerSymbol -----
 |  Function getPlayerSymbol
 |
 |  Purpose:  Validates the correctness of the symbol corresponding to
 |      each player that is stored in the array.
 |
 |  Parameters:
 |      playerNumber (IN) -- Number ID of the player.
 |      *symbol (IN/OUT) -- Symbol of the player.
 |
 |  Returns:  SYMBOL_OK -- Symbol is correct.
|             SYMBOL-ERROR -- Symbol is wrong.
 *-------------------------------------------------------------------*/
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t *symbol) {
    if (playerNumber == 1 || playerNumber == 2) {
        /* Retrieves the symbol from the configuration array. */
        *symbol = playerConfig[playerNumber - 1];
        if (*symbol == SYMBOL_X || *symbol == SYMBOL_Y) {
            return  SYMBOL_OK;
        }
        else {
            return SYMBOL_ERROR;
        }
    }
    else {
        return SYMBOL_ERROR;
    }
}

/*------------------------------------------------- updateBoard -----
 |  Function updateBoard
 |
 |  Purpose:  Updates the layout of the board, by adding each player's
 |            movement.
 |
 |  Parameters:
 |      *board (IN/OUT) -- A pointer to the current layout of the board.
 |      position (IN) -- The position the player wants to place
 |                       the movement.
 |      symbol (IN) -- Symbol of the player to be played.
 |
 |  Returns:
|             void
 *-------------------------------------------------------------------*/
void updateBoard(uint8_t *board, uint8_t position, uint8_t symbol) {
    board[position] = symbol;
}

/*------------------------------------------------- loadAndUpdate -----
 |  Function loadAndUpdate
 |
 |  Purpose:  Prompts the user to make a movement and updates the board
 |            accordingly, and then redraws the board with the updated
 |            values.
 |
 |  Parameters:
 |      playerNumber (IN) -- The player number ID to play.
 |
 |  Returns:
|             void
 *-------------------------------------------------------------------*/
void loadAndUpdate(uint8_t playerNumber) {
    /* Load the player configuration. */
    uint8_t symbol;
    int positionToPlay;
    uint8_t state = getPlayerSymbol(playerNumber, &symbol);
    if (state == SYMBOL_OK) {
        printf("Enter the position to make your move in: ");
        scanf("%d", &positionToPlay);
    } else {
        printf("Symbol error.");
        return;
    }
    updateBoard(gameBoard, positionToPlay, symbol);
    drawBoard(gameBoard);
}

/*------------------------------------------------- getGameState -----
 |  Function getGameState
 |
 |  Purpose:  Determines the current state of the game.
 |
 |  Parameters:
 |      *board (IN/OUT) -- Current layout of the game.
 |      *gameState (IN/OUT) -- A variable for storing the game state.
 |
 |  Returns:  void
 *-------------------------------------------------------------------*/
void getGameState(uint8_t *board, uint8_t *gameState)
{
    /* Check for the winning state. */
    if ( (board[0] == board[1] && board[0] == board[2])
    || (board[3] == board[4] && board[3] == board[5])
    || (board[6] == board[7] && board[6] == board[8])
    || (board[0] == board[3] && board[0] == board[6])
    || (board[1] == board[4] && board[1] == board[7])
    || (board[2] == board[5] && board[2] == board[8])
    || (board[0] == board[4] && board[0] == board[8])
    || (board[2] == board[4] && board[2] == board[6])) {
        *gameState = WINNING;
        /* Check for the continue state. */
    } else if (board[0] == '0' || board[1] == '1' || board[2] == '2' || board[3] == '3' || board[4] == '4'
    || board[5] == '5' || board[6] == '6' || board[7] == '7' || board[8] == '8') {
        *gameState = CONTINUE;
        /* Check for the draw state. */
    } else {
        *gameState = DRAW;
    }
}

/*------------------------------------------------- main -----
 |  Function main
 |
 |  Purpose:  Tha main flow of the X-O game.
 |
 |  Parameters:
 |      void
 |
 |  Returns:
 |          0 when the programs exits correctly.
 *-------------------------------------------------------------------*/
int main() {
    /* State of game. */
    uint8_t gameState;
    setPlayerConfig(playerConfig);
    drawBoard(gameBoard);
    int playerNumber = 0;
    do {
        playerNumber %= 2;
        if (playerNumber == 0) {
            printf("Player #1 turn.\n");
        } else if (playerNumber == 1) {
            printf("Player #2 turn. \n");
        }
        loadAndUpdate(playerNumber+1);
        getGameState(gameBoard, &gameState);
        playerNumber++;
    } while (gameState != WINNING && gameState != DRAW);
    if (gameState == WINNING) {
        printf("CONGRATULATIONS! YOU WON.\n");
    } else {
        printf("DRAW!");
    }
    return 0;
}
