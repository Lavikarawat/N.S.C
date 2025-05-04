#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
    return x * x * x - 2 * x - 5; // x^3 - 2x - 5
}

int main() {
    double a, b, c;
    double fa, fb, fc;
    double tolerance;
    int maxIterations, iteration;

    cout << "Enter the initial guess values a and b: ";
    cin >> a >> b;

    cout << "Enter the tolerance: ";
    cin >> tolerance;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    fa = func(a);
    fb = func(b);

    if (fa * fb >= 0) {
        cout << "The initial guesses do not bracket a root." << endl;
        return 1;
    }

    cout << "Iteration\t a\t\t b\t\t c\t\t f(c)" << endl;

    for (iteration = 1; iteration <= maxIterations; iteration++) {
        c = (a * fb - b * fa) / (fb - fa);
        fc = func(c);

        cout << iteration << "\t\t" << fixed << setprecision(6) << a << "\t\t" << b << "\t\t" << c << "\t\t" << fc << endl;

        if (abs(fc) < tolerance) {
            cout << "Root found after " << iteration << " iterations: " << c << endl;
            return 0;
 
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    cout << "Root not found within the maximum number of iterations." << endl;
    return 1;
}
