//  main.cpp
//  MTH9815-Quiz1
//

#include <iostream>
#include "quick_sort.h"
#include "max_heap.hpp"

void print_array(const int* arr, std::size_t size) {
    for (std::size_t i = 0; i < size; i++) {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
}

void test_quick_sort() {
    int arr[] = {7, 7, 4, 5, 1, 4};
    int count = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, count);
    quick_sort(arr, count);
    print_array(arr, count);

}

void test_max_heap() {
    std::vector<int> arr = {1, 9, 9, 6, 0, 6, 1, 3};
    
    MaxHeap max_heap;
    
    for (int elem : arr) {
        max_heap.add(elem);
    }
    
    std::cout << "max_heap.get_size(): " << std::endl;
    std::cout << max_heap.get_size() << std::endl;
    
    while (!max_heap.empty()) {
        std::cout << max_heap.pop() << '\t';
    }
    std::cout << std::endl;
    std::cout << "max_heap.get_size(): " << std::endl;
    std::cout << max_heap.get_size() << std::endl;
    
    std::cout << "max_heap.is_empty(): " << std::endl;
    std::cout << max_heap.is_empty() << std::endl;
    
    
}

int main(int argc, const char * argv[]) {
    
    test_quick_sort();
    test_max_heap();
    1
    return 0;
}

