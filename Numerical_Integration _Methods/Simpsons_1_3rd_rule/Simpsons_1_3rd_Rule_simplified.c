#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1.0 / sqrt(1.0 + x * x * x);
}

double simpsonsRule(double lower, double upper, int subIntervals) {
    double stepSize = (upper - lower) / subIntervals;
    double integral = f(lower) + f(upper); 
    double weight;

    for (int i = 1; i < subIntervals; i++) {
        double x = lower + i * stepSize;
        double fx = f(x);
        if (i % 2 == 0) {
            weight = 2.0; 
        } else {
            weight = 4.0; 
        }
        integral += weight * fx;
    }

    integral *= stepSize / 3.0; 
    return integral;
}

int main() {
    double lower, upper;
    int subIntervals;

    printf("Enter lower limit of integration: ");
    if (scanf("%lf", &lower) != 1) {
        printf("Error: Invalid input for lower limit.\n");
        return 1; 
    }

    printf("Enter upper limit of integration: ");
    if (scanf("%lf", &upper) != 1 || upper <= lower) {
        printf("Error: Invalid input for upper limit or upper limit is less than lower limit.\n");
        return 1; 
    }

    do {
        printf("Enter number of sub-intervals (must be even): ");
        if (scanf("%d", &subIntervals) != 1 || subIntervals <= 0) {
            printf("Error: Invalid input for sub-intervals.\n");
            return 1; 
        }
        if (subIntervals % 2 != 0) {
            printf("Error: Number of sub-intervals must be even.\n");
        }
    } while (subIntervals % 2 != 0);

    double result = simpsonsRule(lower, upper, subIntervals);

    printf("\nApproximate Integral = %.6lf\n", result);

    return 0;
}

