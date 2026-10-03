#include <stdio.h>

int main()
{
    int n, i;
    float a;

    printf("Enter number of coefficients: ");
    scanf("%d", &n);

    if(n < 2)
    {
        printf("Polynomial degree must be at least 1\n");
        return 0;
    }

    float coef[100], result[100];

    printf("Enter coefficients from highest power to constant:\n");
    for(i=0; i<n; i++)
        scanf("%f", &coef[i]);

    printf("Enter value of a (for divisor x - a): ");
    scanf("%f", &a);

    result[0] = coef[0];

    printf("\nSteps:\n");
    printf("Step 1: %.2f\n", result[0]);

    for(i=1; i<n; i++)
    {
        result[i] = coef[i] + result[i-1] * a;
        printf("Step %d: %.2f\n", i+1, result[i]);
    }

    printf("\nQuotient coefficients:\n");
    for(i=0; i<n-1; i++)
        printf("%.2f ", result[i]);

    printf("\nRemainder: %.2f\n", result[n-1]);

    return 0;
}