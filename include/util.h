#ifndef SUDOKU_UTIL_H
#define SUDOKU_UTIL_H

/**
* @file Util.h
*
* @brief Declares some usefull methods, which are implemented in util.cpp
*
**/

/**
 * @brief prints a given two dimensional array with the given size.
 *
 * Used to print a gameboard, represented by a two dimensional int array.
 * @param array the array(or gameboard) to be printed.
 * @param size size of the array. Always taken as square.
 */
void print2DArray(int **array, int size);

/**
 * @brief gives the index, where the segment starts, that belongs to the given index.
 * @param index index, belonging to the position of interest.
 * @return start-index of the segment belonging to the given index.
 */
int getSegmentStart(int index);

/**
 * @brief gives the number of the segment belonging to column and row.
 *
 * segments are numbered from left to right and up to down.
 * 0 1 2
 * 3 4 5
 * 6 7 8
 * @param column column of interest.
 * @param row row of interest.
 * @return segment number to the given row and column.
 */
int getSegmentNumber(int column, int row);


#endif