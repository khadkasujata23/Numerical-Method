#include <stdio.h>
float function(float x)
{
 return x*x*x - x - 2;
}
int main()
{
    float x0, x1, x2;
    int iteration = 1;
    printf("Enter first guess: ");
    scanf("%lf", &x0);
    printf("Enter second guess: ");
    scanf("%lf", &x1);
    while (1)
    {
       x2 = x1 - (function(x1) * (x1 - x0)) / (function(x1) - function(x0));
       printf("Iteration %d: x = %lf\n", iteration, x2);
       if (x2 - x1 < 0.0001 && x1 - x2 < 0.0001)
       break;
       x0 = x1;
       x1 = x2;
       iteration++;
    }
       printf("Final root: %lf\n", x2);
       return 0;
}