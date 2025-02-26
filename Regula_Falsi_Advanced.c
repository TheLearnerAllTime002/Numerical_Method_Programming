#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define f(x) (2 * (x) * (x) * (x) - 3 * (x) - 6) // Enter Your Given Equation

void find_root(float a, float b, int show_table);

int main()
{
    float a, b;
    char choice;
    printf("Enter the range:\n");
    scanf("%f %f", &a, &b);

    printf("Do you want to see the iteration table? (y/n): ");
    scanf(" %c", &choice);

    int show_table = (choice == 'y' || choice == 'Y');

    float step = 0.1;
    int root_count = 0;

    printf("\nSearching for roots in the interval [%.2f, %.2f]:\n", a, b);

    for (float i = a; i < b; i += step)
    {
        if (i + step > b)
            break;

        if (f(i) * f(i + step) < 0)
        {
            printf("\nRoot found in the interval [%.2f, %.2f]:\n", i, i + step);
            find_root(i, i + step, show_table);
            root_count++;
        }
    }

    printf("\nTotal roots found: %d\n", root_count);
    return 0;
}

void find_root(float a, float b, int show_table)
{
    float c, fc;
    int iteration = 0;

    if (f(a) * f(b) >= 0)
    {
        printf("Invalid range: f(a) and f(b) must have opposite signs.\n");
        return;
    }

    if (show_table)
    {
        printf("\nIteration\t  a\t  b\t   c (False Position)\t  f(c)\t\n");
        printf("-------------------------------------------------------------------\n");
    }

    do
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a)); // Regula Falsi formula
        fc = f(c);
        iteration++;

        if (show_table)
        {
            printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\n", iteration, a, b, c, fc);
        }

        if (fabs(fc) < EPSILON) // Root found
        {
            break;
        }

        if (f(a) * fc < 0)
        {
            b = c; // Root lies in [a, c]
        }
        else
        {
            a = c; // Root lies in [c, b]
        }

    } while (fabs(fc) > EPSILON);

    printf("Root found: %.6f\n", c);
}

