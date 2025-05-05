#include <stdio.h>
#include "functions.h"

int main(){
    int A[2] = {1, 2};

    int* ve = bubble_sort(A);
    printf("%d", ve[0]);

    return 0;
}