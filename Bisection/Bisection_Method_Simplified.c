#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define f(x) ((x) * (x) * (x) - 9 * (x) + 1) // Enter your given equation

void find_root(float a, float b);

int main()
{
    float a, b;
    printf("Enter the range (a b): ");
    scanf("%f %f", &a, &b);

    float step = 0.1;

    for (float i = a; i < b; i += step)
    {
        if (i + step > b)
            break; // Prevents out-of-range errors

        if (f(i) * f(i + step) < 0)
        { // Check for root existence
            printf("Root found in range [%.2f, %.2f]: ", i, i + step);
            find_root(i, i + step);
        }
    }
    return 0;
}

void find_root(float a, float b)
{
    float c;

    do
    {
        c = (a + b) / 2;
        if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    } while (fabs(f(c)) > EPSILON);

    printf("%.6f\n", c);
}

