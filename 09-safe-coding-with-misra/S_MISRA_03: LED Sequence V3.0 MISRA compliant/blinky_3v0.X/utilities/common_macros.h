#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H

#define LOGIC_HIGH 1
#define LOGIC_LOW 0

/**
 * @brief Set a specific bit in the REG register.
 */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/**
 * @brief Clear a specific bit in the REG register.
 */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/**
 * @brief Toggle a specific bit in the REG register.
 */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/**
 * @brief Check if a specific bit is set in the REG register and return true if yes.
 */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/**
 * @brief Check if a specific bit is cleared in the REG register and return true if yes.
 */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#endif /* COMMON_MACROS_H */
