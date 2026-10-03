#include <stdio.h>
#include <math.h>

// Factorial function
int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

// Example derivative function dy/dx = f(x, y) = x^2 + y^2
float f(float x, float y) {
    return x*x + y*y;
}

int main() {
    float x0, y0, x, y, h;
    float f1, f2, f3; // first, second, third derivatives

    // Input initial values
    printf("Enter initial values of x0 and y0: ");
    scanf("%f %f", &x0, &y0);

    // Input point to evaluate
    printf("Enter x at which function is to be evaluated: ");
    scanf("%f", &x);

    h = x - x0; // step size

    // First derivative
    f1 = f(x0, y0);

    // Second derivative (dy'/dx = df/dx + df/dy * dy/dx)
    f2 = 2*x0 + 2*y0*f1;  // df/dx + df/dy*f1 for f(x,y)=x^2+y^2

    // Third derivative (d^3y/dx^3)
    f3 = 2 + 2*y0*f2 + 2*f1*f1; // formula for this example

    // Taylor series expansion: y(x) = y0 + h*f1 + h^2/2!*f2 + h^3/3!*f3
    y = y0 + h*f1 + (h*h/ fact(2))*f2 + (h*h*h/ fact(3))*f3;

    printf("Function value at x = %.4f is y = %.4f\n", x, y);

    return 0;
}