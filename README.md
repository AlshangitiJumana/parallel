# parallel
Parallel computing
Linear Regression Implementation: Sequential vs. Parallel
This repository contains two versions of a simple linear regression implementation using gradient descent:

Sequential Version (mark_prediction.cpp): A standard implementation where the gradient descent computation is done sequentially.
Parallel Version (parallel_code.cpp): A parallelized version using OpenMP to speed up the gradient computation.
Both implementations perform linear regression on a generated dataset of (x, y) pairs, simulating a relationship between study hours and exam scores.

Files Overview
1. mark_prediction.cpp (Sequential Version)
Purpose: Implements linear regression using a single-threaded approach.
Key Features:
Uses a fixed dataset size of 6,000,000 records.
Processes the dataset sequentially for gradient calculations.
Demonstrates the time taken for training and prediction.
Usage: Use this file to understand the baseline performance of sequential computation.
2. parallel_code.cpp (Parallel Version)
Purpose: Optimized linear regression implementation using OpenMP.
Key Features:
Utilizes OpenMP for parallelizing the loop that computes gradients.
Threads are specified using #pragma omp parallel for reduction.
Uses a dataset size of 10,000 records for demonstration but can scale as needed.
Faster computation for large datasets by leveraging multi-core CPUs.
Parallelization Details:
The gradient calculation (m_gradient and b_gradient) is parallelized.
Reduction is used to ensure that thread-local results are safely combined.
Example: #pragma omp parallel for reduction(+ : m_gradient, b_gradient) threads_num(4)
Key Differences Between the Versions
Feature	Sequential Version	Parallel Version
Dataset Size	6,000,000 records	10,000 records (adjustable)
Execution Time	Slower due to sequential loop	Faster using OpenMP
Parallelism	No parallelization	Uses OpenMP for gradients
Use Case	Baseline performance testing	High-performance computations
How to Run
Prerequisites
A C++ compiler supporting OpenMP (e.g., GCC).
C++17 or later.
Compilation
Compile the code using the following commands:

Sequential Version:
bash
Copy code
g++ -o sequential mark_prediction.cpp -std=c++17
Parallel Version:
bash
Copy code
g++ -o parallel parallel_code.cpp -std=c++17 -fopenmp
Execution
Run the compiled binaries:

Sequential Version:
bash
Copy code
./sequential
Parallel Version:
bash
Copy code
./parallel
Performance Comparison
Run both versions and compare:

Execution time (Time taken) for training the model.
Prediction accuracy for a given input (new_x = 6.0).
Future Enhancements
Increase dataset sizes and test the scalability of both versions.
Experiment with dynamic thread allocation in the parallel version.
Implement additional optimizations such as vectorization.
This repository demonstrates the advantages of parallelization in numerical computation tasks. The parallel version is designed to efficiently handle large datasets, making it a practical choice for real-world applications.
