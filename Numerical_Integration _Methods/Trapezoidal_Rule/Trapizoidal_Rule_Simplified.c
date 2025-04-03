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
    printf("Enter number of sub intervals: ");
    scanf("%d", &subIntervals);

    h = (upper - lower) / subIntervals;

    integral = (f(lower) + f(upper)) / 2.0;

    for (int i = 1; i < subIntervals; i++) {
        double x = lower + i * h;
        integral += f(x);
    }

    integral *= h;

    printf("\nApproximate integral value: %.6lf\n", integral);

    return 0;
}