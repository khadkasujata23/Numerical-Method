#include <stdio.h>
#include <math.h>

float g(float x)
{
    return (x + 2)/3 + 1;
}

int main()
{
    float x0, x1, error;
    int iteration = 1;

    printf("Enter initial value: ");
    scanf("%f", &x0);

    printf("Enter allowed error: ");
    scanf("%f", &error);

    printf("\nIteration\tValue\n");

    while (1)
    {
        x1 = g(x0);
        printf("%d\t\t%f\n", iteration, x1);

        if (fabs(x1 - x0) < error)
            break;

        x0 = x1;
        iteration++;
    }

    printf("\nRoot= %f\n", x1);
}