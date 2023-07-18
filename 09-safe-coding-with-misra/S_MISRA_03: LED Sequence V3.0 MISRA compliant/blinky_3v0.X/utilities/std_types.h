#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define NULL ((void *)0)
#define TRUE 1
#define FALSE 0

/* Boolean Data Type */
typedef unsigned char boolean;

/**
 * @defgroup stdTypes Standard Types
 * @{
 */
typedef unsigned char uint8; ///< Unsigned 8-bits.
typedef signed char sint8; ///< Signed 8-bits.
typedef unsigned short uint16; ///< Unsigned 16-bits.
typedef signed short sint16; ///< Signed 16-bits.
typedef unsigned long uint32; ///< Unsigned 32-bits.
typedef signed long sint32; ///< Signed 32-bits.
typedef unsigned long long uint64; ///< Unsigned 64-bits.
typedef signed long long sint64; ///< Signed 64-bits.
typedef float float32; ///< 32-bits float.
typedef double float64; ///< 64-bits float.
/**@}*/

#endif /* STD_TYPE_H_ */
