
#include <stdio.h>
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void printArray(int arr[], int n);
void copyArray(int source[], int dest[], int n);
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;       
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;    
    int L[n1], R[n2];   
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];   
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }   
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}
int main() {
    int choice, n;    
    printf("Enter the number of elements: ");
    scanf("%d", &n);    
    int original[n], arr[n];    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &original[i]);
    }    
    do {  
        copyArray(original, arr, n);    
        printf("\n=== Sorting Algorithms Menu ===\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Display Original Array\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);        
        switch(choice) {
            case 1:
                printf("\nOriginal array: ");
                printArray(arr, n);
                bubbleSort(arr, n);
                printf("After Bubble Sort: ");
                printArray(arr, n);
                break;               
            case 2:
                printf("\nOriginal array: ");
                printArray(arr, n);
                selectionSort(arr, n);
                printf("After Selection Sort: ");
                printArray(arr, n);
                break;                
            case 3:
                printf("\nOriginal array: ");
                printArray(arr, n);
                insertionSort(arr, n);
                printf("After Insertion Sort: ");
                printArray(arr, n);
                break;                
            case 4:
                printf("\nOriginal array: ");
                printArray(arr, n);
                quickSort(arr, 0, n-1);
                printf("After Quick Sort: ");
                printArray(arr, n);
                break;                
            case 5:
                printf("\nOriginal array: ");
                printArray(arr, n);
                mergeSort(arr, 0, n-1);
                printf("After Merge Sort: ");
                printArray(arr, n);
                break;                
            case 6:
                printf("\nOriginal array: ");
                printArray(original, n);
                break;                
            case 7:
                printf("Exiting program...\n");
                break;                
            default:
                printf("Invalid choice! Please try again.\n");
        }        
    } while(choice != 7);    
    return 0;
}