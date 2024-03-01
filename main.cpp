#include "sorting.hpp"
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

int main() {
    for (size_t arrSize = 10000; arrSize <= 1000000; arrSize *= 10) {
        std::string fileName = "data/" + std::to_string(arrSize) + "_not_sorted.txt";

        std::ifstream ifstr(fileName);
        if (!ifstr.is_open()) {
            std::cerr << "Error opening file: " << fileName << std::endl;
            return EXIT_FAILURE;
        }

        int data[arrSize];
        for (size_t i = 0; i < arrSize; ++i) {
            ifstr >> data[i];
        }
        ifstr.close();

        // Bubble Sort
        auto start = std::chrono::high_resolution_clock::now();
        int *sortedDataBubble = mergeSort(data, arrSize);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << std::to_string(arrSize) << ": Bubble sort took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n";
        delete[] sortedDataBubble; // Очистка памяти

    }

    // Здесь будут вызовы и замеры времени для mergeSort, insertionSort, quickSort
    // Пример:
    // start = std::chrono::high_resolution_clock::now();
    // int *sortedDataMerge = mergeSort(data, arrSize);
    // end = std::chrono::high_resolution_clock::now();
    // std::cout << "Merge sort took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n";
    // delete[] sortedDataMerge; // Очистка памяти

    return 0;
}
