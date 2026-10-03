#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float a[20][20], l[20][20], u[20][20], temp;

    /* 1. Read dimension of the matrix */
    printf("Enter dimension of matrix: ");
    scanf("%d", &n);

    /* 2. Read matrix elements with prompts */
    printf("Enter elements of matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }

    /* 3. Initialize L and U matrices to zero */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            l[i][j] = 0.0;
            u[i][j] = 0.0;
        }
    }

    /* 4. Calculate U matrix using Cholesky method */
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            temp = 0.0;
            if (i == j) {
                for (k = 0; k < i; k++)
                    temp += u[k][i] * u[k][i];
                u[i][i] = sqrt(a[i][i] - temp);
            } else {
                for (k = 0; k < i; k++)
                    temp += u[k][i] * u[k][j];
                u[i][j] = (a[i][j] - temp) / u[i][i];
            }
        }
    }

    /* 5. Compute L matrix as transpose of U */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            l[j][i] = u[i][j];
        }
    }

    /* 6. Display L matrix */
    printf("\n*********** L Matrix **********\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.4f\t", l[i][j]);
        }
        printf("\n");
    }

    /* 7. Display U matrix */
    printf("\n*********** U Matrix **********\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.4f\t", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}