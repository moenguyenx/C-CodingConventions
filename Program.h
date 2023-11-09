#ifndef PROGRAM_H
#define PROGRAM_H

/*======================================================================================================================
 *                                                  INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
======================================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <windows.h>

#ifdef __cplusplus
extern "C"{
#endif

/*======================================================================================================================
 *                                                  CONSTANTS
======================================================================================================================*/

/*======================================================================================================================
 *                                              DEFINES AND MACROS
======================================================================================================================*/

/*======================================================================================================================
 *                                                      ENUMS
======================================================================================================================*/
typedef enum
{
	E_OK = 0,
	E_PRAM_WRONG = 1,
	E_ARR_EMPTY = 2,
	E_CANNOT_ALLOC_MEM = 3,
	E_ARR_IS_FULL = 4,
	E_NO_ELEMENT = 5,
} statusResult;

/*======================================================================================================================
 *                                              STRUCTURES AND OTHER TYPEDEFS
======================================================================================================================*/

/*======================================================================================================================
 *                                              GLOBAL VARIABLE DECLARATIONS
======================================================================================================================*/

/*======================================================================================================================
 *                                                  FUNCTION PROTOTYPES
======================================================================================================================*/
/*
* @brief    print Menu Choice
* @details  Display Menu Choice to user
*
* @param    None
* @pre      N/A
*/
void printMenu(void);

/*
* @brief    print Array
* @details  Display created array to user
*
* @param    Pointer to dynamic array and Size of array
* @pre      N/A
*/
statusResult printArray(int** arr, int *size);

/*
* @brief    Create Array
* @details  Create dynamic array with n elements
*
* @param    None
* @pre      N/A
*/
statusResult createArray(int** dynamicArray, int* n);

/*
* @brief    Insert Element
* @details  Insert an element in to an array
*
* @param    Pointer to dynamic array and size of array
* @pre      Allocated array
*/
statusResult insert(int** arr, int* size);

/*
* @brief    Delete Element
* @details  Delete an element in user-input's index
*
* @param    Pointer to dynamic array and size of array
* @pre      Allocated array
*/
statusResult deleteElement(int** arr, int* size);

/*
* @brief    Increase Sort
* @details  Sort an array in increment order using bubble sort
*
* @param    Pointer to dynamic array and size of array
* @pre      Allocated array
*/
statusResult increSort(int** arr, int* size);

/*
* @brief    Decrease Sort
* @details  Sort an array in decrement order using bubble sort
*
* @param    Pointer to dynamic array and size of array
* @pre      Allocated array
*/
statusResult decreSort(int** arr, int* size);

/*
* @brief    Search
* @details  Search an element in array
*
* @param    Pointer to dynamic array and size of array
* @pre      Allocated array
*/
void search(int** arr, int* size);

/*
* @brief    Exit program
* @details  Free up memory and switch the state to false to exit the loop
*
* @param    Pointer to dynamic array and bool state of program
* @pre      N/A
*/
void exitProgram(int** dynamicArray, bool* state);

#ifdef __cplusplus
}
#endif

#endif /* PROGRAM_H */
