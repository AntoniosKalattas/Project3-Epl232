/** @file readLatin.c
 *  @brief Reads the latin square from file and prints it in the corresponding grid form.
 *
 *  @author Antonios Kalattas.
 *  @author Alexandros Georgiou.
 */

#ifndef READ_LATIN_H
#define READ_LATIN_H

#include<stdlib.h>
#include<stdio.h>

/**
 * @brief reads a Latin square from a file and initializes with its values
 * 
 * This function opens the file and reads the size and values of the Latin square, 
 * dynamically allocating memory for the 2D array to store these values
 * 
 * @param latinSquare Pointer to a pointer of a 2D array that will hold the Latin square values
 * @param filename Name of the file containing the Latin square data
 * @return int Size of the Latin square
 */
int readLatinSquare(int ***,char *);

/**
 * @brief prints the Latin square in a formatted layout
 * 
 * This function outputs the current state of the Latin square
 * 
 * @param latinSquare Pointer to a 2D array representing the Latin square
 * @param size Size of the Latin square (n x n)
 */
void printLatinSquare(int ***,int);

#endif /* READ_LATIN_H */
