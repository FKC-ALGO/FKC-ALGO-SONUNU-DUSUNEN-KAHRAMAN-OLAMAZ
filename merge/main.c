#include <stdio.h>
#include <stdlib.h>

void Merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int P[n1];
    int Q[n2];

    for (int i = 0; i < n1; i++) {
        P[i] = arr[start + i];
    }

    for (int j = 0; j < n2; j++) {
        Q[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int idx = start;

    while (i < n1 && j < n2) {
        if (P[i] < Q[j]) {
            arr[idx] = P[i];
            i++;
        } else {
            arr[idx] = Q[j];
            j++;
        }
        idx++;
    }

    while (i < n1) {
        arr[idx] = P[i];
        i++;
        idx++;
    }

    while (j < n2) {
        arr[idx] = Q[j];
        j++;
        idx++;
    }
}

void MergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

void Print_Elements(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int max_elements = 100;
    int arr[max_elements];
    printf("Input Array:\n");
    int num_elements = 0;

    while (num_elements < max_elements && scanf("%d", &arr[num_elements]) == 1) {
        num_elements++;
    }

    if (num_elements <= 1)
    {
        printf("Error: The number of elements to sort must be greater than 1.\n");
        return 1;
    }

    int start = 0;
    int end = num_elements - 1;
    

    printf("Number of elements: %d\n", num_elements);
    Print_Elements(arr, num_elements);

    MergeSort(arr, start, end);

    printf("\nSorted Array:\n");
    Print_Elements(arr, num_elements);

    return 0;
}
