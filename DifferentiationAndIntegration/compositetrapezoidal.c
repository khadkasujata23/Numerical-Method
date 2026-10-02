#include <stdio.h>

#define f(x) (x*x*x+2)

int main() {
    float x0, xn, h, term, I, a;
    int k, i;

    printf("Enter Lower Limit: ");
    scanf("%f", &x0);

    printf("Enter Upper Limit: ");
    scanf("%f", &xn);

    printf("Enter Number of Segments: ");
    scanf("%d", &k);

    h = (xn - x0) / k;

    term = f(x0) + f(xn);

    for (i = 1; i < k; i++) {
        a = x0 + i * h;
        term += 2 * f(a);
    }

    I = h / 2 * term;

    printf("Integral Value: %.4f\n", I);

    return 0;
}