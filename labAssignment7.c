#include <stdio.h>

void bubbleSort(int arr[], int n, int swapCount[]) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapCount[arr[j]]++;
                swapCount[arr[j+1]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swapCount[]) {
    for (int i = 0; i < n - 1; i++) {
        int smallestIndex = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallestIndex]) {
                smallestIndex = j;
            }
        }
        if (smallestIndex != i) {
            swapCount[arr[smallestIndex]]++;
            swapCount[arr[i]]++;
            
           int temp = arr[smallestIndex];
            arr[smallestIndex] = arr[i];
            arr[i] = temp;
        }
    }
}


void printSwaps(int swapCount[], int arr[], int n) {
    int totalSwaps = 0;
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swapCount[arr[i]]);
        totalSwaps += swapCount[arr[i]];
    }
    printf("%d\n", totalSwaps / 2); 
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int swapCount1[101] = {0};

    printf("array1 bubble sort:\n");
    bubbleSort(array1, n1, swapCount1);
    printSwaps(swapCount1, array1, n1);

    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int swapCount2[101] = {0};

    printf("\narray2 bubble sort:\n");
    bubbleSort(array2, n2, swapCount2);
    printSwaps(swapCount2, array2, n2);

    
    int array1b[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int swapCount1b[101] = {0};
    printf("\narray1 selection sort:\n");
    selectionSort(array1b, n1, swapCount1b);
    printSwaps(swapCount1b, array1b, n1);

    int array2b[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swapCount2b[101] = {0};
    printf("\narray2 selection sort:\n");
    selectionSort(array2b, n2, swapCount2b);
    printSwaps(swapCount2b, array2b, n2);

    return 0;
}
