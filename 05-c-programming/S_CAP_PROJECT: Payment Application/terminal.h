#ifndef PROJECT_SPRINT_2_TERMINAL_H
#define PROJECT_SPRINT_2_TERMINAL_H

#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TRANSACTION_AMOUNT 5000

typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
}ST_cardData_t;

/**
 * @struct ST_terminalData_t
 * @brief This structure contains all the data regarding the terminal.
 * @var ST_terminalData_t::transAmount
 * Member 'transAmount' contains the amount required by the client to withdraw.
 * @var ST_terminalData_t::maxTransAmount
 * Member 'maxTransAmount' contains the maximum amount that could be performed in one transaction.
 * @var ST_terminalData_t::transactionDate
 * Member 'transactionDate' contains the date required to perform the transaction.
 */
typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

void __currentTime(void);

/**
 * @enum EN_terminalError_t
 * @brief Determines the state of the terminal, date, card and the amount to be operated on.
 */
typedef enum EN_terminalError_t
{
    TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

/**
 * @brief Asks for the transaction date and store it in the terminal data.
 * @param termData 10 characters string in the the format DD/MM/YYYY.
 * @return WRONG_DATE If the transaction date is NULL or in the wrong format.
 * @return TERMINAL_OK If transaction date is valid. TODO What defines a valid transaction date?
 */

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
/**
 * @brief Compares the card expiry date with the transaction date.
 * @param cardData This parameter is taken from the ST_CardData_t structure.
 * @param termData This parameter is determined from the current date of the temrinal.
 * @return EXPIRED_DATA If the card is expired.
 * @return TERMINAL_OK If the card is accepted.
 */
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData);

/**
 * @brief Asks for the transaction amount and saves it into terminal data.
 * @param termData Transaction amount read from the ST_CardData_t structure.
 * @return INVALID_AMOUNT If the transaction amount is less than or equal to 0.
 * @return TERMINAL_OK If the transaction amount is valid.
 */
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);

/**
 * @brief Compares the input transaction amount with the terminal max allowed amount.
 * @param termData
 * @return EXCEED_MAX_AMOUNT The transaction amount is larger than the terminal max allowed amount.
 * @return TERMINAL_OK The transaction amount is within the accepted range.
 */
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);

/**
 * @brief Takes the maximum allowed amount and stores it into terminal data.
 * @param termData Stores the value of the maximum amount to be performed by the terminal.
 * @param maxAmount The maximum amount to be peroformed by the terminal.
 * @return INVALID_MAX_AMOUNT If the transaction amount is less than or equal 0.
 * @return TERMINAL_OK If the transaction amount is valid.
 */
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount);

/**
 * @brief Check if the PAN is a Luhn number or not.
 * @param cardData
 * @return INVALID_CARD If the number is not Luhn number.
 * @return TERMINAL_OK If the number is valid.
 */
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData); // Optional

/**
 * @defgroup unitTesting Unit testing
 * Performs unit testing on the terminal functions.
 * @{
 */
void getTransactionDateTest(void); ///< Perform unit testing on the getTransactionDate function.

void isCardExpiredTest(void); ///< Perform unit testing on the isCardExpired function.

void getTransactionAmountTest(void); ///< Perform unit testing on the getTransactionAmount function.

void isBelowMaxAmountTest(void); ///< Perform unit testing on the isBelowMaxAmount function.

void setMaxAmountTest(void); ///< Perform unit testing on the setMaxAmount function.
/**@}*/

#endif //PROJECT_SPRINT_2_TERMINAL_H
