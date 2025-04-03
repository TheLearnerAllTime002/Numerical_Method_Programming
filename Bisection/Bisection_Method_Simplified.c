#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define f(x) ((x) * (x) * (x) - 9 * (x) + 1) // Define the function

void find_root(float a, float b);

int main()
{
    float a, b;
    int root_found; // Flag to check if at least one root is found

    do
    {
        root_found = 0; // Reset flag for each new range
        printf("Enter the range : ");
        scanf("%f %f", &a, &b);

        float step = 0.1;

        for (float i = a; i < b; i += step)
        {
            if (i + step > b)
                break;

            float f1 = f(i);
            float f2 = f(i + step);

            if (f1 * f2 < 0)
            { // Root existence check
                printf("Root found in range [%.2f, %.2f]: ", i, i + step);
                find_root(i, i + step);
                root_found = 1;
            }
        }

        if (!root_found)
        {
            printf("No root found in the range [%.2f, %.2f]. Please enter a new range.\n", a, b);
        }

    } while (!root_found); 
    return 0;
}

void find_root(float a, float b)
{
    float c, fc;

    do
    {
        c = (a + b) / 2;
        fc = f(c);

        if (fc == 0.0 || fabs(fc) < EPSILON)
         break;
        

        if (f(a) * fc < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    } while ((b - a) / 2 > EPSILON); 

    printf("%.6f\n", c);
}
