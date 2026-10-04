#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float a[20][20], inv[20][20], pivot, factor;

    /* 1. Read dimension of matrix */
    printf("Enter dimension of matrix: ");
    scanf("%d", &n);

    /* 2. Read matrix with prompts */
    printf("Enter elements of matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }

    /* 3. Initialize inverse matrix as identity */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            inv[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    /* 4. Gauss-Jordan Elimination */
    for (k = 0; k < n; k++) {
        pivot = a[k][k];
        if (fabs(pivot) < 1e-6) {
            printf("Matrix is singular, cannot invert.\n");
            return 0;
        }

        /* Normalize pivot row */
        for (j = 0; j < n; j++) {
            a[k][j] /= pivot;
            inv[k][j] /= pivot;
        }

        /* Eliminate other rows */
        for (i = 0; i < n; i++) {
            if (i != k) {
                factor = a[i][k];
                for (j = 0; j < n; j++) {
                    a[i][j] -= factor * a[k][j];
                    inv[i][j] -= factor * inv[k][j];
                }
            }
        }
    }

    /* 5. Display inverse matrix */
    printf("\nInverse matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%10.4f ", inv[i][j]);
        }
        printf("\n");
    }

    return 0;
}