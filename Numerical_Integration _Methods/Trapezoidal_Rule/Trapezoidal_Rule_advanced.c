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

    printf("\n%10s %12s %15s %15s\n", "x", "f(x)", "Weight", "Contribution");
    printf("--------------------------------------------\n");

    integral = 0.5 * f(lower);
    printf("%10.4lf %12.6lf %15.1lf %15.6lf\n", lower, f(lower), 0.5, 0.5 * f(lower));

    for (int i = 1; i < subIntervals; i++) {
        double x = lower + i * h;
        double fx = f(x);
        integral += fx;
        printf("%10.4lf %12.6lf %15.1lf %15.6lf\n", x, fx, 1.0, fx);
    }

    integral += 0.5 * f(upper);
    printf("%10.4lf %12.6lf %15.1lf %15.6lf\n", upper, f(upper), 0.5, 0.5 * f(upper));

    integral *= h;
    printf("\nApproximate integral value: %.6lf\n", integral);

    return 0;
}
