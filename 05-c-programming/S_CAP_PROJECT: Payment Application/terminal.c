#include "terminal.h"

/**
 * @brief Checks the format of the input time string in the DD/MM/YY.
 * @param timeString
 * @return WRONG_DATE If the string disproves the format.
 * @return TERMINAL_OK If the string proves the format.
 */
EN_terminalError_t __isTimeFormatted(char *timeString) {
    if (strlen(timeString) != 10) {
        return WRONG_DATE;
    } else if (!isdigit(timeString[0])) {
        return WRONG_DATE;
    } else if (!isdigit(timeString[1])) {
        return WRONG_DATE;
    } else if (timeString[2] != '/') {
        return WRONG_DATE;
    } else if (!isdigit(timeString[3])) {
        return WRONG_DATE;
    } else if (!isdigit(timeString[4])) {
        return WRONG_DATE;
    } else if (timeString[5] != '/') {
        return WRONG_DATE;
    } else if (!isdigit(timeString[6])) {
        return WRONG_DATE;
    } else if (!isdigit(timeString[7])) {
        return WRONG_DATE;
    } else if (!isdigit(timeString[8])) {
        return WRONG_DATE;
    } else if (!isdigit(timeString[9])) {
        return WRONG_DATE;
    } else {
        return TERMINAL_OK;
    }
}

/**
 * @brief Asks for the transaction date and store it in the terminal data.
 *
 * The function gets the current time of the terminal and puts it the DD/MM/YYYY format,
 * then copies it to the ST_terminalData_t member 'transactionDate'.
 *
 * @param[out] termData 10 characters string in the the format DD/MM/YYYY.
 * @return WRONG_DATE The transaction date is NULL or in the wrong format.
 * @return TERMINAL_OK Transaction date is valid.
 */
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData) {
    /* Calculates the number of seconds that have passed since January 1st, 1970. */
    time_t currentTime = time(NULL);
    /* Breaks down the number of seconds passed to it into different formats. */
    struct tm *currentClock = localtime(&currentTime);

//    printf("DD: %d\n", currentClock -> tm_mday);
//    printf("MM: %d\n", currentClock -> tm_mon + 1);
//    printf("YY: %d\n", currentClock -> tm_year + 1900);

    char current_time_string[11];
    /* Puts the currentClock in the specified format. */
    strftime(current_time_string, 100, "%d/%m/%Y", currentClock);
    strcpy((char *)termData -> transactionDate, current_time_string);
//    printf("%s\n", termData -> transactionDate);

    /* Checks the format of the time. */
    return __isTimeFormatted(current_time_string);
}

/**
 * @brief Compares the card expiry date with the transaction date.
 *
 * Subtracts the card year from the current year and if the result is positive then the card is valid,
 * else it's invalid.
 *
 * @param[in] cardData This parameter is from the ST_CardData_t structure.
 * @param[in] termData ST_terminalData_t structure that holds the value for the current time of the terminal.
 * @return EXPIRED_DATA Card is expired.
 * @return TERMINAL_OK Card is accepted.
 */
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData) {
    /* Converting the current time to MM/YY format, and separating the month and year in separate values. */
    uint8_t currentMonth = strtol((const char *)termData -> transactionDate + 3, NULL, 10);
    uint8_t currentYear = strtol((const char *)termData -> transactionDate + 8, NULL, 10);

    /* Separating the month and the year of the card in separate values. */
    uint8_t cardMonth = strtol((const char *)cardData -> cardExpirationDate, NULL, 10);
    uint8_t cardYear = strtol((const char *)cardData -> cardExpirationDate + 3, NULL, 10);

    /* Check the validity of the card. */
    if (cardYear - currentYear > 0) {
        return TERMINAL_OK;
    } else {
        if (cardMonth - currentMonth > 0) {
            return TERMINAL_OK;
        } else {
            return EXPIRED_CARD;
        }
    }
}

/**
 * @brief Asks for the transaction amount and saves it into terminal data.
 *
 * Prompts the user to enter the transaction amount and saves transAmount member of ST_terminalData_t.
 *
 * @param[out] termData ST_terminalData_t structure that holds the value of the transaction amount.
 * @return INVALID_AMOUNT Transaction amount is less than or equal to 0.
 * @return TERMINAL_OK Transaction amount is valid.
 */
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData) {
    printf("Enter your transaction amount: ");
    scanf("%f", &(termData -> transAmount));
    if (termData -> transAmount <= 0) {
        return INVALID_AMOUNT;
    } else {
        return TERMINAL_OK;
    }
}

/**
 * @brief Compares the input transaction amount with the terminal max allowed amount.
 * @param[in] termData ST_terminalData_t structure that holds the value for the maximum transaction amount.
 * @return EXCEED_MAX_AMOUNT Transaction amount is larger than the terminal max allowed amount.
 * @return TERMINAL_OK Transaction amount is within the accepted range.
 */
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData) {
    if (termData -> transAmount <= termData -> maxTransAmount) {
        return TERMINAL_OK;
    } else {
        return EXCEED_MAX_AMOUNT;
    }
}

/**
 * @brief Sets the maximum transaction amount.
 * @param[out] termData ST_terminalData_t structure that contains 'maxTransAmount' member.
 * @param[in] maxAmount The maximum amount to be performed by the terminal.
 * @return INVALID_MAX_AMOUNT Transaction amount is less than or equal 0.
 * @return TERMINAL_OK Transaction amount is valid.
 */
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount) {
    if (maxAmount <= 0) {
        return INVALID_MAX_AMOUNT;
    } else {
        termData -> maxTransAmount = maxAmount;
        return TERMINAL_OK;
    }
}

/**
 * @brief Check if the PAN is a Luhn number or not.
 * @param cardData
 * @return INVALID_CARD If the number is not Luhn number.
 * @return TERMINAL_OK If the number is valid.
 */
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData); // Optional

/**
 * @brief This array corresponds to all the return status of the terminal application.
 */
const char* terminalError_test[] = {"TERMINAL_OK","WRONG_DATE","EXPIRED_CARD","INVALID_CARD",
                               "INVALID_AMOUNT","EXCEED_MAX_AMOUNT","INVALID_MAX_AMOUNT"};

/**
 * @brief This variable holds the return status of the function we are performing the unit test on.
 */
int8_t programState_test = -1;

/**
 * @brief ST_terminalData_t structure that is used for unit testing.
 */
ST_terminalData_t terminalData_test;

/**
 * @brief ST_cardData_t structure that is used for unit testing.
 */
ST_cardData_t cardData_test;

/**
 * @brief Perform unit testing on the getTransactionDate function.
 */
void getTransactionDateTest(void) {
    printf("Tester name: Khaled Mustafa\n"
           "Function Name: getTransactionDate\n");
    printf("Test case #1\n");
    printf("The function will always return the current time in this format DD/MM/YYYY\n");
    printf("Expected result: TERMINAL_OK\n");
    programState_test = getTransactionDate(&terminalData_test);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);
}

/**
 * @brief Perform unit testing on the isCardExpired function.
 */
void isCardExpiredTest(void) {
    printf("Tester name: Khaled Mustafa\n"
           "Function Name: getTransactionDate\n");

    getTransactionDate(&terminalData_test);

    printf("Test case #1\n");
    uint8_t cardDate_test_1[6] = "03/25";
    mempcpy(cardData_test.cardExpirationDate, cardDate_test_1, 6);
    printf("Input date: 03/25\n");
    printf("Expected result: TERMINAL_OK\n");
    programState_test = isCardExpired(&cardData_test, &terminalData_test);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);

    printf("--------------------\n");

    printf("Test case #2\n");
    uint8_t cardDate_test_2[6] = "03/20";
    mempcpy(cardData_test.cardExpirationDate, cardDate_test_2, 6);
    printf("Input date: 03/20\n");
    printf("Expected result: EXPIRED_CARD\n");
    programState_test = isCardExpired(&cardData_test, &terminalData_test);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);

    printf("--------------------\n");

    printf("Test case #3\n");
    uint8_t cardDate_test_3[6] = "02/23";
    mempcpy(cardData_test.cardExpirationDate, cardDate_test_3, 6);
    printf("Input date: 02/23\n");
    printf("Expected result: EXPIRED_CARD\n");
    programState_test = isCardExpired(&cardData_test, &terminalData_test);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);

    printf("--------------------\n");

    printf("Test case #4\n");
    uint8_t cardDate_test_4[6] = "03/23";
    mempcpy(cardData_test.cardExpirationDate, cardDate_test_4, 6);
    printf("Input date: 03/23\n");
    printf("Expected result: EXPIRED_CARD\n");
    programState_test = isCardExpired(&cardData_test, &terminalData_test);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);
}

/**
 * @brief Perform unit testing on the getTransactionAmount function.
 */
void getTransactionAmountTest(void) {
    printf("Tester name: Khaled Mustafa\n"
           "Function Name: getTransactionDate\n");

    printf("Test case #1\n");
    printf("Input date: 1\n");
    printf("Expected result: TERMINAL_OK\n");
    programState_test = getTransactionAmount(&terminalData_test);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);

    printf("--------------------\n");

    printf("Test case #2\n");
    printf("Input date: 0\n");
    printf("Expected result: INVALID_AMOUNT\n");
    programState_test = getTransactionAmount(&terminalData_test);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);

    printf("--------------------\n");

    printf("Test case #3\n");
    printf("Input date: -1\n");
    printf("Expected result: INVALID_AMOUNT\n");
    programState_test = getTransactionAmount(&terminalData_test);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);
}

/**
 * @brief Perform unit testing on the isBelowMaxAmount function.
 */
void isBelowMaxAmountTest(void) {
    printf("Tester name: Khaled Mustafa\n"
           "Function Name: getTransactionDate\n");

    terminalData_test.maxTransAmount = 10000;

    printf("Test case #1\n");
    terminalData_test.transAmount = 0;
    printf("Input date: 0\n");
    printf("Expected result: TERMINAL_OK\n");
    programState_test = isBelowMaxAmount(&terminalData_test);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);

    printf("--------------------\n");

    printf("Test case #2\n");
    terminalData_test.transAmount = 10;
    printf("Input date: 10\n");
    printf("Expected result: TERMINAL_OK\n");
    programState_test = isBelowMaxAmount(&terminalData_test);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);

    printf("--------------------\n");

    printf("Test case #3\n");
    terminalData_test.transAmount = 20000;
    printf("Input date: 2000\n");
    printf("Expected result: EXCEED_MAX_AMOUNT\n");
    programState_test = isBelowMaxAmount(&terminalData_test);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);
}

/**
 * @brief Perform unit testing on the setMaxAmount function.
 */
void setMaxAmountTest(void) {
    printf("Tester name: Khaled Mustafa\n"
           "Function Name: getTransactionDate\n");

    printf("Test case #1\n");
    float maxAmount_test_1 = 0;
    printf("Input date: 0\n");
    printf("Expected result: INVALID_MAX_AMOUNT\n");
    programState_test = setMaxAmount(&terminalData_test, maxAmount_test_1);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);

    printf("--------------------\n");

    printf("Test case #2\n");
    float maxAmount_test_2 = -1;
    printf("Input date: 0\n");
    printf("Expected result: INVALID_MAX_AMOUNT\n");
    programState_test = setMaxAmount(&terminalData_test, maxAmount_test_2);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);

    printf("--------------------\n");

    printf("Test case #2\n");
    float maxAmount_test_3 = 1;
    printf("Input date: 0\n");
    printf("Expected result: TERMINAL_OK\n");
    programState_test = setMaxAmount(&terminalData_test, maxAmount_test_3);
    printf("Actual result: %s.\n", terminalError_test[programState_test]);
}