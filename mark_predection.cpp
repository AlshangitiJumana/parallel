#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include <omp.h>

using namespace std;

// Function to perform a simple linear regression
// y = m * x + b
void linear_regression(const vector<double>& x, const vector<double>& y, double& m, double& b, double learning_rate, int epochs) {
    int n = x.size();
    m = 0.0; // slope
    b = 0.0; // intercept

    // Gradient Descent
    for (int epoch = 0; epoch < epochs; ++epoch) {
        double m_gradient = 0.0;
        double b_gradient = 0.0;

        // Compute gradients over the dataset
       
        for (int i = 0; i < n; ++i) {
            double prediction = m * x[i] + b;
            double error = prediction - y[i];
            m_gradient += (2.0 / n) * x[i] * error;
            b_gradient += (2.0 / n) * error;
        }

        // Update the parameters
        m -= learning_rate * m_gradient;
        b -= learning_rate * b_gradient;
    }
}

int main() {
    // Start the timer
    auto start = chrono::high_resolution_clock::now();

    // Generate a large dataset: x = hours studied, y = exam score
    int dataset_size = 6000000; // Increase this if you want to make the code take more time
    vector<double> x(dataset_size);
    vector<double> y(dataset_size);

    // Random data generation for x (hours studied) and y (exam scores)
    random_device rd;
    mt19937 gen(42); // Fixed seed for reproducibility
    uniform_real_distribution<> dist_x(0.0, 10.0); // Hours studied between 0 and 10
    uniform_real_distribution<> dist_y(0.0, 10.0); // Exam scores between 0 and 10

    for (int i = 0; i < dataset_size; ++i) {
        x[i] = dist_x(gen);
        y[i] = dist_y(gen);
    }

    double m = 0.0;
    double b = 0.0;
    double learning_rate = 0.0001;
    int epochs = 1000;

    // Train the model
    linear_regression(x, y, m, b, learning_rate, epochs);

    // Predict a value
    double new_x = 6.0;
    double prediction = m * new_x + b;
    cout << "For " << new_x << " hours of study, you will get a mark of approximately " << prediction << endl;

    // End the timer and calculate the duration
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Time taken: " << duration.count() << " seconds" << endl;

    return 0;
}
