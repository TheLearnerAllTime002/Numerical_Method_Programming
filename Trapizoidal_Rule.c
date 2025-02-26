#include <stdio.h>
#include <math.h>

#define f(x) (4 * (x) - 3 * (x) * (x))

int main()
{
    double lower, upper, result = 0.0, h, k;
    int i, subIntervals;

    printf("Enter lower limit of integration: ");
    scanf("%lf", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &upper);
    printf("Enter number of sub intervals: ");
    scanf("%d", &subIntervals);

    h = (upper - lower) / subIntervals;

    result = f(lower) + f(upper); // First and last terms
    for (i = 1; i < subIntervals; i++)
    {
        k = lower + i * h;
        result += 2 * f(k); // Multiply by 2 for intermediate terms
    }
    result *= h / 2; // Multiply by h/2 to complete the formula

    printf("\nRequired value of integration is: %.6lf\n", result);

    return 0;
}

