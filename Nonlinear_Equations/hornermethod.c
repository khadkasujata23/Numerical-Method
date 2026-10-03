#include <stdio.h>

void horner();

int main() {
    horner();
    return 0;
}

void horner() {
    int i, n;
    float x0;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);

    float a[n+1], b[n+1];  // n+1 to avoid out-of-bounds

    printf("Enter the coefficients (a0 to a%d):\n", n);
    for(i = 0; i <= n; i++) {
        printf("a%d = ", i);
        scanf("%f", &a[i]);
    }

    printf("Enter the value of x0: ");
    scanf("%f", &x0);

    b[n] = a[n];
    printf("\nb%d = %f", n, b[n]);

    for(i = n-1; i >= 0; i--) {
        b[i] = a[i] + b[i+1]*x0;  // Horner formula
        printf("\nb%d = %f", i, b[i]);
    }

    printf("\nThe evaluated value at x = %f is P(%f) = %f\n", x0, x0, b[0]);
}