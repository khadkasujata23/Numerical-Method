#include <stdio.h>
float function(float x)
{
 return x*x*x - x - 2;
}
float derivative(float x)
{
 return 3*x*x - 1;
}
int main()
{
    float x0, x1, error;
    int iteration = 1;
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter allowed error: ");
    scanf("%f", &error);
    printf("\nIteration\tValue\n");
    while (1)
    {
       x1 = x0 - function(x0) / derivative(x0);
       printf("%d\t\t%f\n", iteration, x1);
       if (x1 - x0 < error && x0 - x1 < error)
       break;
       x0 = x1;
       iteration++;
    }
        printf("\nRoot is approximately: %f\n", x1);
        return 0;
}