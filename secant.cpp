#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x, 3) - 2 * x - 5; 
}

// Secant method implementation
double secant(double x0, double x1, double tolerance, int maxIterations) {
    int iteration = 0;
    double x2;

    while (iteration < maxIterations) {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));

        if (fabs(x2 - x1) < tolerance) {
            cout << "Root found after " << iteration + 1 << " iterations." << endl;
            return x2;
        }

        x0 = x1;
        x1 = x2;
        iteration++;
    }

    cout << "Secant method did not converge within " << maxIterations << " iterations." << endl;
    return x1;
}

int main() {
    double x0, x1, tolerance;
    int maxIterations;

    cout << "Enter the first initial guess (x0): ";
    cin >> x0;
    cout << "Enter the second initial guess (x1): ";
    cin >> x1;

    cout << "Enter the tolerance (e.g., 0.0001): ";
    cin >> tolerance;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    double root = secant(x0, x1, tolerance, maxIterations);

    cout << fixed << setprecision(10);
    cout << "Approximate root: " << root << endl;

    return 0;
}
