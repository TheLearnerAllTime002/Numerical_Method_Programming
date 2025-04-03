#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1.0 / sqrt(1.0 + x * x * x);
}

int main() {
    double lower, upper, h, integral = 0.0;
    int subIntervals;

    printf("Enter lower limit of integration: ");
    scanf("%lf", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &upper);
    printf("Enter number of sub intervals (must be multiple of 6): ");
    scanf("%d", &subIntervals);

    if (subIntervals % 6 != 0) {
        printf("Error: Number of sub-intervals must be multiple of 6 for Weddle's rule.\n");
        return 1;
    }

    h = (upper - lower) / subIntervals;

    printf("\n%10s %12s %15s %15s\n", "x", "f(x)", "Weight", "Contribution");
    printf("--------------------------------------------\n");

    const int weights[] = {1, 5, 1, 6, 1, 5, 2};
    int weight_index = 0;

    for (int i = 0; i <= subIntervals; i++) {
        double x = lower + i * h;
        double fx = f(x);
        int current_weight = weights[weight_index % 7];
        
        if (i == 0 || i == subIntervals) {
            integral += fx;
        } else {
            integral += current_weight * fx;
        }

        printf("%10.4lf %12.6lf %15d %15.6lf\n", x, fx, current_weight, current_weight * fx);
        
        weight_index++;
        if (weight_index == 7) weight_index = 1;
    }

    integral *= 3 * h / 10;
    printf("\nApproximate integral value: %.6lf\n", integral);

    return 0;
}