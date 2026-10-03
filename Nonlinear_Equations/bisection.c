#include <stdio.h>
float function(float x)
{
   return x*x*x - x - 2;
}
int main()
{
    float left, right, middle;
    int iteration = 1;
    printf("Enter left value: ");
    scanf("%f", &left);
    printf("Enter right value: ");
    scanf("%f", &right);
    if (function(left) * function(right) > 0)
    {
       printf("Invalid interval. No root exists.\n");
       return 0;
    }
    while ((right - left) > 0.0001)
    {
       middle = (left + right) / 2;
       printf("Iteration %d: x = %f\n", iteration, middle);
       if (function(left) * function(middle) < 0)
          right = middle;
       else
           left = middle;
           iteration++;
    }
        middle = (left + right) / 2;
        printf("Final root: %f\n", middle);
        return 0;
}