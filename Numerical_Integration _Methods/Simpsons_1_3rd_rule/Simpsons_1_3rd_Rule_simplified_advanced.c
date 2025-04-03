#include<stdio.h>
#include<math.h>

#define f(x) (1.0 / sqrt(1 + x * x * x))

int main()
{
    float lower, upper, stepSize, k, integration = 0.0;
    int i, subInterval;

    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);
    printf("Enter number of sub intervals (must be even): ");
    scanf("%d", &subInterval);

    if (subInterval % 2 != 0) {
        printf("Error: Number of sub-intervals must be even for Simpson's 1/3 Rule.\n");
        return 1;
    }

    stepSize = (upper - lower) / subInterval;

    printf("\n%10s %10s %15s %15s\n", "x", "f(x)", "Weight", "Contribution");
    printf("-----------------------------------------------------------------\n");

    integration = f(lower);
    printf("%10.4f %10.4f %15s %15.4f\n", lower, f(lower), "1 (End)", f(lower));

    for (i = 1; i <= subInterval - 1; i++)
    {
        k = lower + i * stepSize;
        if (i % 2 == 0) {
            integration += 2 * f(k);
            printf("%10.4f %10.4f %15s %15.4f\n", k, f(k), "2 (Even)", 2 * f(k));
        } else {
            integration += 4 * f(k);
            printf("%10.4f %10.4f %15s %15.4f\n", k, f(k), "4 (Odd)", 4 * f(k));
        }
    }
    
    integration += f(upper);
    printf("%10.4f %10.4f %15s %15.4f\n", upper, f(upper), "1 (End)", f(upper));

    integration = (integration * stepSize) / 3.0;

    printf("\nFinal Integration Result = %.6f\n", integration);

    return 0;
}