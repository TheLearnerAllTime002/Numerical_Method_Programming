#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITERATIONS 1000
#define f(x) ((x) * (x) * (x) - 3 * (x) - 5)  // Given function

void find_root_ita(float a, float b);
int find_all_roots_ita(float a, float b, float step);

int main() {
    float a, b, step = 0.01;
    int root_count;

    do {
        printf("Enter the range: ");
        scanf("%f %f", &a, &b);

        root_count = find_all_roots_ita(a, b, step);

        if (root_count == 0)
            printf("No roots found in the given range. Please enter a new range.\n");

    } while (root_count == 0);

    printf("\nTotal roots found: %d\n", root_count);
    return 0;
}

int find_all_roots_ita(float a, float b, float step) {
    int count = 0;
    printf("\nSearching for roots in [%.2f, %.2f]:\n", a, b);

    for (float i = a; i < b - step / 2; i += step) {
        if (f(i) * f(i + step) < 0) {
            printf("Root found in range [%.2f, %.2f]: ", i, i + step);
            find_root_ita(i, i + step);
            count++;
        }
    }

    return count;
}

void find_root_ita(float a, float b) {
    float c, fc;
    int iteration = 0;

    do {
        c = (a + b) / 2;
        fc = f(c);
        iteration++;

        if (fabs(fc) < EPSILON) // Stopping condition
            break;

        if (f(a) * fc < 0)
            b = c;
        else
            a = c;

    } while ((b - a) / 2 > EPSILON && iteration < MAX_ITERATIONS);

    if (iteration >= MAX_ITERATIONS)
        printf("Warning: Max iterations reached. May not have fully converged.\n");

    printf("Root: %.6f found after %d iterations\n", c, iteration);
}
