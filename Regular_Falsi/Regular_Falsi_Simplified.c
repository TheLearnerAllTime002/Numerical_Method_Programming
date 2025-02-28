#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define f(x) ((x) * (x) * (x) - 3 * (x) - 5) // Define your equation

void find_root(float a, float b);

int main()
{
    float a, b;
    float step = 0.01; // Searching frequency
    int root_found;

    do
    {
        printf("Enter the range (a b): ");
        scanf("%f %f", &a, &b);

        root_found = 0;

        for (float i = a; i < b; i += step)
        {
            if (i + step > b)
                break;

            if (f(i) * f(i + step) < 0)
            {
                printf("Root found in range [%.2f, %.2f]: ", i, i + step);
                find_root(i, i + step);
                root_found = 1;
            }
        }

        if (!root_found)
            printf("No roots found in the given range. Please enter a new range.\n");

    } while (!root_found); // Keep asking until a root is found

    return 0;
}

void find_root(float a, float b)
{
    float c, fc;
    int iteration = 0;

    do
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a)); // Regula Falsi formula
        fc = f(c);
        iteration++;

        if (fabs(fc) < EPSILON)
            break;

        if (f(a) * fc < 0)
            b = c;
        else
            a = c;

    } while (fabs(fc) > EPSILON);

    printf("Root: %.6f found after %d iterations\n", c, iteration);
}
