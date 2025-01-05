#include <stdio.h>

// Swap function using XOR (safer than arithmetic operations)
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function
void heapify(int arr[], int i, int n,int *co) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    // Compare with left child
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Compare with right child
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the current node, swap and heapify again
    if (largest != i) {
        printf("\nSwapped %d <-> %d\n", arr[i], arr[largest]);
        swap(&arr[i], &arr[largest]);
        *co += 1;

        // Print the array after swap
        for (int k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n");

        heapify(arr, largest, n,co);
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(int);
    int c = 0;

    printf("Initial Array:\n");
    for (int k = 0; k < size; k++) printf("%d ", arr[k]);
    printf("\n");

    // Building the heap
    for (int j = size / 2 ; j >= 0; j--) {
        printf("\nHeapifying at index %d\n", j);
        heapify(arr, j, size,&c);
    }

    printf("\nHeapified Array:\n");
    for (int k = 0; k < size; k++) printf("%d ", arr[k]);
    printf("\n\n");
    printf("interchanges done here %d",c);

    return 0;
}
