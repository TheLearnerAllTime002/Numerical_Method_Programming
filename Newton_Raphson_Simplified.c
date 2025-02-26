#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define f(x) ((x) * sin(x) + cos(x)) // Function
#define df(x) (x * cos(x))           // Derivative of function

void newton_raphson(float x0);

int main()
{
    float x0;
    printf("Enter an initial guess: ");
    scanf("%f", &x0);

    newton_raphson(x0);
    return 0;
}

void newton_raphson(float x0)
{
    float x1;
    int iteration = 0;

    printf("\nIteration\t x_n\t\t f(x_n)\n");
    printf("--------------------------------------\n");

    do
    {
        if (fabs(df(x0)) < EPSILON) // Prevent division by zero
        {
            printf("Mathematical error: Derivative near zero. Choose a different initial guess.\n");
            return;
        }

        x1 = x0 - f(x0) / df(x0); // Newton-Raphson formula
        printf("%d\t\t %.6f\t %.6f\n", ++iteration, x1, f(x1));

        if (fabs(f(x1)) < EPSILON) // Root found
            break;

        x0 = x1;

    } while (fabs(f(x1)) > EPSILON);

    printf("\nRoot found: %.6f\n", x1);
}

