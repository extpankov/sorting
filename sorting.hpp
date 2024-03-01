#ifndef SORTING
#define SORTING

#include <stdlib.h>

// сортировки не должны менять содержимое входных данных
// сортировки должны на выход возвращать отсортированный массив

int * bubbleSort(const int *data, const size_t dataSize);
int * mergeSort(const int *data, const size_t dataSize);
int * insertionSort(const int *data, const size_t dataSize);
int * quickSort(const int *data, const size_t dataSize);


#endif