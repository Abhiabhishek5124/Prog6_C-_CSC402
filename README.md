# Multi-Threaded Simulation in C++

## Overview
This C++ program demonstrates the use of **multi-threading**, **synchronization**, and **random number generation** to simulate concurrent tasks. The program creates multiple threads based on user input. Each thread waits until all threads are ready, sleeps for a random duration, generates a random value, and returns it. The main function manages thread creation, synchronization, and termination.

This project provides hands-on learning in:
- **Thread management** using `std::thread`.
- **Synchronization** using `std::mutex` and `std::condition_variable`.
- **Random number generation** with `rand()` and `srand()`.
- **Promise-Future** pattern for returning values from threads.

## Features
- **Dynamic Thread Creation**: The number of threads is determined by user input.
- **Synchronization**: Threads wait until all are ready before proceeding.
- **Random Sleep Duration**: Each thread sleeps for a random time between 100 and 1000 milliseconds.
- **Random Value Generation**: Each thread generates a random value between 1 and 100 and returns it.
- **Thread Management**: The main function ensures all threads complete execution before terminating.

## Programming Concepts Used
1. **Multi-Threading**:
   - The program uses `std::thread` to create and manage multiple threads dynamically based on user input.
   - Each thread executes the `doStuff` function, which performs tasks such as waiting, sleeping, and generating random values.

2. **Synchronization**:
   - A `std::mutex` is used to ensure thread-safe access to shared resources.
   - A `std::condition_variable` is employed to synchronize threads, ensuring they all start execution simultaneously after being created.

3. **Random Number Generation**:
   - The `rand()` function, seeded with `srand()`, is used to generate random sleep durations and values for each thread.
   - Sleep durations range between 100 and 1000 milliseconds, while random values range between 1 and 100.

4. **Promise-Future Pattern**:
   - Each thread uses a `std::promise` to return a generated random value to the main thread.
   - The main thread retrieves these values using `std::future`.

5. **Thread Management**:
   - Threads are stored in a `std::vector` for easy management.
   - The main thread waits for all threads to complete using the `join()` method.

6. **User Input Handling**:
   - The program prompts the user to enter a non-negative integer to determine the number of threads to create.
   - Input validation ensures the user provides a valid non-negative value.

## How to Run
1. **Compile the Code**:
   - Compile the program using a C++ compiler (e.g., `g++`):
     ```bash
     g++ -o thread_simulation main.cpp -std=c++11 -pthread
     ```

2. **Run the Program**:
   - Execute the compiled program:
     ```bash
     ./thread_simulation
     ```

3. **Input the Number of Threads**:
   - Enter a non-negative integer when prompted:
     ```
     Enter a non-negative integer: 5
     ```

## Code Structure
- **Global Variables**:
  - `mutex mtx`: Ensures thread-safe access to shared resources.
  - `bool allReady`: Indicates whether all threads are ready to proceed.
  - `condition_variable cv`: Used to synchronize threads.

- **`doStuff` Function**:
  - Executed by each thread.
  - Generates a random sleep duration and a random value.
  - Uses a `promise` to return the generated value.

- **`runSimulation` Function**:
  - Notifies all threads to start execution once they are ready.

- **`main` Function**:
  - Takes user input for the number of threads.
  - Creates and manages threads using a `vector<thread>`.
  - Ensures all threads complete execution before terminating.

## Dependencies
- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., `g++`).
- **C++11 or Later**: The program uses features from C++11, such as `std::thread` and `std::promise`.

## Future Enhancements
- **Thread Pool**: Implement a thread pool for better resource management.
- **User-Defined Ranges**: Allow users to specify ranges for sleep duration and random values.
- **Error Handling**: Add robust error handling for invalid inputs or thread creation failures.

---

This README provides a professional overview of the program, including **programming concepts used**, **features**, **how to run**, **code structure**, **dependencies**, and **future enhancements**. It’s ready to be used as your project's `README.md` file.
