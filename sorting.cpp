#include <iostream>
#include <algorithm>

int * bubbleSort(const int *data, const size_t dataSize) {
    int* arr = new int[dataSize];
    for (size_t i = 0; i < dataSize; ++i) {
        arr[i] = data[i];
    }

    for (size_t i = 0; i < dataSize - 1; ++i) {
        for (size_t j = 0; j < dataSize - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

void merge(int *left, int *right, int leftCount, int rightCount, int *data) {
    int i = 0, j = 0, k = 0;

    while (i < leftCount && j < rightCount) {
        if (left[i] < right[j]) {
            data[k++] = left[i++];
        } else {
            data[k++] = right[j++];
        }
    }

    while (i < leftCount) {
        data[k++] = left[i++];
    }

    while (j < rightCount) {
        data[k++] = right[j++];
    }
}

int * mergeSort(const int *data, const size_t dataSize) {
    if (dataSize < 2) {
        int *singleElementArray = new int[dataSize];
        if (dataSize == 1) {
            singleElementArray[0] = data[0];
        }
        return singleElementArray;
    }

    size_t mid = dataSize / 2;
    int *left = new int[mid];
    int *right = new int[dataSize - mid];

    std::copy(data, data + mid, left);
    std::copy(data + mid, data + dataSize, right);

    int *sortedLeft = mergeSort(left, mid);
    int *sortedRight = mergeSort(right, dataSize - mid);

    int *sortedData = new int[dataSize];
    merge(sortedLeft, sortedRight, mid, dataSize - mid, sortedData);

    delete[] left;
    delete[] right;
    delete[] sortedLeft;
    delete[] sortedRight;

    return sortedData;
}

int* insertionSort(const int* data, const size_t dataSize) {
    // Создаем копию исходного массива
    int* arr = new int[dataSize];
    for (size_t i = 0; i < dataSize; ++i) {
        arr[i] = data[i];
    }

    // Алгоритм сортировки вставками
    for (size_t i = 1; i < dataSize; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Перемещаем элементы arr[0..i-1], которые больше, чем key, на одну позицию вперед
        // от их текущего положения
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    return arr;
}

// Вспомогательная функция для разделения массива
int partition(int* arr, int low, int high) {
    int pivot = arr[high]; // выбор опорного элемента
    int i = (low - 1); // индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++; // инкремент индекса меньшего элемента
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortRecursive(int* arr, int low, int high) {
    if (low < high) {
        // pi - индекс разделения, arr[pi] теперь на правильном месте
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы до разделения и после разделения
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

int* quickSort(const int* data, const size_t dataSize) {
    int* arr = new int[dataSize];
    for (size_t i = 0; i < dataSize; ++i) {
        arr[i] = data[i];
    }

    quickSortRecursive(arr, 0, dataSize - 1);
    return arr;
}