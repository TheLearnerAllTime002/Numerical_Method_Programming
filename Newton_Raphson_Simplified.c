#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define f(x) ((x) * (x) * (x) - 3 * (x) - 5) // Function definition
#define df(x) (3 * (x) * (x) - 3)            // Derivative of the function

void find_root(float a, float b);

int main()
{
    float a, b;
    float step = 0.01; // Searching frequency
    int root_found;

    do
    {
        printf("Enter the range: ");
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

    } while (!root_found);

    return 0;
}

void find_root(float a, float b)
{
    float x = (a + b) / 2; // Initial guess (midpoint of the interval)
    float fx, dfx;
    int iteration = 0;

    do
    {
        fx = f(x);
        dfx = df(x);

        if (dfx == 0.0)
        {
            printf("Derivative is zero. Newton-Raphson method cannot proceed.\n");
            return;
        }

        float x_new = x - fx / dfx;

        if (fabs(x_new - x) < EPSILON)
            break;

        x = x_new;
        iteration++;

    } while (fabs(fx) > EPSILON);

    printf("Root: %.6f found after %d iterations\n", x, iteration);
}
