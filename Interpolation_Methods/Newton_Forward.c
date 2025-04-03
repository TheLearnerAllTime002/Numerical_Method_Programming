#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], f[20], diff_table[20][20];
    float h, u, result, x_value, term;

    printf("Enter number of data points (max 20): ");
    scanf("%d", &n);

    if (n > 20 || n <= 0) {
        printf("Invalid number of points.\n");
        return 1;
    }

    printf("Enter x and f(x) values in order:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d], f[%d]: ", i, i);
        scanf("%f %f", &x[i], &f[i]);
    }

    printf("\nEnter x value to interpolate: ");
    scanf("%f", &x_value);

    for (i = 0; i < n; i++) {
        diff_table[i][0] = f[i];
    }
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            diff_table[i][j] = diff_table[i+1][j-1] - diff_table[i][j-1];
        }
    }

    printf("\nFORWARD DIFFERENCE TABLE\n");
    printf("x\tf(x)\t");
    for (i = 1; i < n; i++) {
        printf("Δ^%d\t", i);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);
        for (j = 0; j < n - i; j++) {
            printf("%.4f\t", diff_table[i][j]);
        }
        printf("\n");
    }

    h = x[1] - x[0];
    u = (x_value - x[0]) / h;
    result = f[0];
    term = 1;

    for (j = 1; j < n; j++) {
        term *= (u - (j - 1)) / j;
        result += term * diff_table[0][j];
    }

    printf("\nInterpolation Result:");
    printf("\nAt x = %.2f, f(x) ≈ %.6f\n", x_value, result);

    return 0;
}