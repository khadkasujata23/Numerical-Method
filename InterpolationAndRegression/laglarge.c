#include <stdio.h>
#define MAX 50

void LagrangeInterpolation();

int main() {
    printf("\n Lagrange's Interpolation\n");
    LagrangeInterpolation();
  return 0;
}

void LagrangeInterpolation() {
  float x[MAX], y[MAX], point, numerator, denominator, interpolatedY = 0;
  int i, j, terms, flag = 1;
  printf("Enter the number of terms of the table : ");
  scanf("%d", &terms);
  printf("Enter the respective values of x & y: \n");
  for(i=0; i<terms; i++) {
    printf("Enter the value for x[%d]: ", i+1);
    scanf("%f", &x[i]);
    printf("Enter the value for y[%d]: ", i+1);
    scanf("%f", &y[i]);
  }
  printf("\nThe table values you entered are as follows : \n");
  printf("x\t\ty\n");
  for (i=0; i<terms; i++) {
    printf("%f\t%f\n", x[i], y[i]);
  }
  while(flag) {
    printf("Enter the value of the x to find value of y: ");
    scanf("%f", &point);
    for(i=0; i<terms; i++) {
      numerator = 1;
      denominator = 1;
      for(j=0; j<terms; j++) {
        if(i != j) {
          numerator =  numerator*(point-x[j]);
          denominator = denominator*(x[i]-x[j]);
        }
      }
      interpolatedY = interpolatedY + ((numerator/denominator)*y[i]);
    }
    printf("\nThe respective value of the variable is : %f", interpolatedY);
    printf("\nDo you want to continue with same data points (0 to exit) ? ");
    scanf("%d", &flag);
  }
}