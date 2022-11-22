//
//  QuickSort.h
//  MTH9815 QUIZ 1 Exercise 1
//

#ifndef QuickSort_h
#define QuickSort_h
#include <functional>



void quick_sort(int* arr, int count) {
    quick_sort_impl(arr, 0, count - 1);
}

void quick_sort_impl(int* arr, int left, int right) {
    
    if (left >= right) {
        return;
    }
    
    int pivot = partition(arr, left, right);
    quick_sort_impl(arr, left, pivot - 1);
    quick_sort_impl(arr, pivot + 1, right);
    return;
    
}


int partition(int* arr, int left, int right) {
    int pivot = arr[right];
    
    int i = left;
    int j = right - 1;
    
    
    while(i <= j) {
      if(arr[i] < pivot){
        i++;
      }else {
        swap(&arr, i, j--);
      }
    }
    swap(array, i, right);
    return i;
    
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



#endif /* QuickSort_h */

