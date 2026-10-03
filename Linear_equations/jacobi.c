#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
    int n, i, j, iter, maxIter;
    float a[20][20], b[20], x[20], xnew[20], sum, error, maxError;

    /* 1. Read dimension of system of equations */
    printf("Enter dimension of system of equations: ");
    scanf("%d", &n);

    /* 2. Read coefficients with prompts */
    printf("Enter coefficients row-wise:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }

    /* 3. Read RHS vector */
    printf("Enter RHS vector:\n");
    for (i = 0; i < n; i++) {
        printf("b[%d] = ", i+1);
        scanf("%f", &b[i]);
    }

    /* 4. Read maximum iterations */
    printf("Enter maximum iterations: ");
    scanf("%d", &maxIter);

    /* 5. Read initial guesses */
    printf("Enter initial values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i+1);
        scanf("%f", &x[i]);
    }

    /* Jacobi Iteration */
    printf("\nIteration Results:\n");
    for (iter = 1; iter <= maxIter; iter++) {
        /* Compute new values */
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            xnew[i] = sum / a[i][i];
        }

        /* Compute maximum relative error */
        maxError = 0.0;
        for (i = 0; i < n; i++) {
            error = fabs(xnew[i] - x[i]);
            if (fabs(xnew[i]) > 1e-6)  // avoid division by zero
                error /= fabs(xnew[i]);
            if (error > maxError)
                maxError = error;
            x[i] = xnew[i];  // update x for next iteration
        }

        /* Display iteration results */
        printf("Iteration #%d: ", iter);
        for (i = 0; i < n; i++) {
            printf("x[%d] = %0.4f  ", i+1, x[i]);
        }
        printf("\n");

        /* Check for convergence */
        if (maxError < EPSILON) {
            printf("\nConverged after %d iterations\n", iter);
            break;
        }
    }

    if (iter > maxIter) {
        printf("\nDid not converge after %d iterations\n", maxIter);
    }

    /* Display final solution */
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %0.4f\n", i+1, x[i]);
    }

    return 0;
}