#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define f(x) ((x) * (x) * (x) - 3 * (x) - 5) // write your own equation

void find_root(float a, float b);

int main()
{
    float a, b;
    printf("Enter the range (a b): ");
    scanf("%f %f", &a, &b);

    float step = 0.01; // searching frequency 
    int root_found = 0;

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
        printf("No roots found in the given range.\n");

    return 0;
}

void find_root(float a, float b)
{
    float c, fc;
    int iteration = 0;

    
    do
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
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
