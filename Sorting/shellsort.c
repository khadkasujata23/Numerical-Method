#include <stdio.h>

int main()
{
    int a[50], n, i, j, gap, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Shell Sort
    for(gap = n/2; gap > 0; gap = gap/2)
    {
        for(i = gap; i < n; i++)
        {
            temp = a[i];
            for(j = i; j >= gap && a[j-gap] > temp; j = j-gap)
            {
                a[j] = a[j-gap];
            }
            a[j] = temp;
        }
    }

    printf("Sorted elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}