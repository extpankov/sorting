#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

int main() {
    size_t arrSize = 100;
     std::string fileName = "test_" + std::to_string(arrSize) + "not_sort.txt";

    std::ifstream ifstr(fileName);
    int arr2[100];
    for (int i = 0; i < 100; ++i) {
        int buff;
        ifstr >> buff;
        arr2[i] = buff;
        std::cout << buff << std::endl;
    }

    for (int i = 0; i < 100; ++i) {
        std::cout << arr2[i] << std::endl;
    }
    ifstr.close();
}