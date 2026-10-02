#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // To avoid overflow

        if (arr[mid] == key)
            return mid; // Element found at index mid
        else if (arr[mid] < key)
            low = mid + 1; // Search in the right half
        else
            high = mid - 1; // Search in the left half
    }
    
    return -1; // Element not found
}

int main() {
    int n, key, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted order: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}