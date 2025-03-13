#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define f(x) ((x) * (x) * (x) * (x) - 1 * (x) - 10) // Define the function

void find_root_ita(float a, float b, int show_table);

int main()
{
    float a, b;
    char choice;
    int root_count = 0;

    printf("Enter the range:\n");
    scanf("%f %f", &a, &b);

    printf("Do you want to see the iteration table? (y/n): ");
    scanf(" %c", &choice);

    int show_table = (choice == 'y' || choice == 'Y');

    printf("\nSearching for roots in the interval [%.2f, %.2f]:\n", a, b);

    float step = 0.1;

    for (float i = a; i < b; i += step)
    {
        if (i + step > b) break;

        float f1 = f(i);
        float f2 = f(i + step);

        if (f1 * f2 < 0) // Check sign change
        {
            printf("\nRoot found in the interval [%.2f, %.2f]:\n", i, i + step);
            find_root_ita(i, i + step, show_table);
            root_count++;
        }
    }

    if (root_count == 0)
        printf("\nNo roots found in the given range. Try a different interval.\n");

    printf("\nTotal roots found: %d\n", root_count);
    return 0;
}

void find_root_ita(float a, float b, int show_table)
{
    float c, fc;
    int iteration = 0;

    if (show_table)
    {
        printf("\nIter\t  a\t\t  b\t\t  c (Mid)\t  f(c)\n");
        printf("----------------------------------------------------------\n");
    }

    do
    {
        c = (a + b) / 2;
        fc = f(c);
        iteration++;

        if (show_table)
            printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\n", iteration, a, b, c, fc);

        if (fc == 0.0 || fabs(fc) < EPSILON) // Exact or close enough
            break;

        if (f(a) * fc < 0)
            b = c;
        else
            a = c;

    } while ((b - a) / 2 > EPSILON); // More stable stopping condition

    printf("Root found: %.6f\n", c);
}
