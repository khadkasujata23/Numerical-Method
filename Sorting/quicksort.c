#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot, i, j, temp;
    
    pivot = a[low];
    i = low + 1;
    j = high;

    while(i <= j)
    {
        while(a[i] <= pivot && i <= high)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[], int low, int high)
{
    int loc;

    if(low < high)
    {
        loc = partition(a, low, high);

        quicksort(a, low, loc - 1);
        quicksort(a, loc + 1, high);
    }
}

int main()
{
    int a[50], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n-1);

    printf("Sorted elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}