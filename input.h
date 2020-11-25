#ifndef GETFUNCTIONS_H_INCLUDED
#define GETFUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/** \brief Gets a validated int number
 *
 * \param message[]: prompted to user, asking for a number
 * \param errorMessage[]: error message if the number inputted is out of range
 * \param min: minimum value to input
 * \param max: maximum value to input
 * \return int: the validated int number
 *
 */
int getInt(char message[], char errorMessage[], int min, int max);



/** \brief Gets a validated float number
 *
 * \param message[]: prompted to user, asking for a number
 * \param errorMessage[]: error message if the number inputted is out of range
 * \param min: minimum value to input
 * \param max: maximum value to input
 * \return float: the validated float number
 *
 */
float getFloat(char message[], char errorMessage[], float min, float max);



/** \brief gets an alphabetical character
 *
 * \param message[]: prompted to user, asking for a letter
 * \param errorMessage[]: error message if character inputted is not an alphabetical character
 * \return char: the inputted alphabetical character
 *
 */
char getLetter(char message[], char errorMessage[]);



/** \brief gets a string with the first letter in uppercase
 *
 * \param message[]: prompted to user, asking for input
 * \param errorMessage[]: error message if the string inputted by the user exceeds the length value
 * \param len int: maximum amount of characters to input by the user
 * \param str[]: the array of characters to copy the string inputted
 *
 *
 */
void getStrings(char message[], char errorMessage[], int len, char str[]);

void firstUpper(char str[]);

/** \brief Copia en "str" una cadena que solo puede tener espacios y letras
 *
 * \param message[] char
 * \param errorMessage[] char
 * \param str[] char
 * \return void
 *
 */
void getAlphaString(char message[], char errorMessage[], char str[]);

/** \brief Copia en "nums" una cadena que solo puede ser de numeros
 *
 * \param message[] char
 * \param errorMessage[] char
 * \param nums[] char
 * \return void
 *
 */
void getNumberString(char message[], char errorMessage[], char nums[]);

#endif // GETFUNCTIONS_H_INCLUDED
