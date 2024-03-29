/*
  Author: Abhishek Shrestha
  CSC 402 - Program #6
  This C++ program creates multiple threads based on user input. Each thread waits until all threads are ready, sleeps for a random duration, generates a random value, and returns it. The main function manages thread creation, synchronization, and termination.
  Date: 03/28/2024
 */


#include <iostream>
#include <thread>
#include <fstream>
#include <future>
#include <vector>
#include <ctime>
#include <mutex>
#include <condition_variable>

using namespace std;

// Global variables
mutex mtx;
bool allReady = false;
condition_variable cv;

// Function executed by threads
void doStuff(promise<int>&& P, int id) {
    srand(time(0) + id); // Seed random number generator with thread ID
    unique_lock<mutex> UL(mtx); // Lock mutex
    cout << "Thread " << id << " is now active" << endl;// Print thread activation message
    while (!allReady) {
        cout << "Thread " << id << " is waiting" << endl; // Print waiting message
        cv.wait(UL);  //Wait until all threads are ready
    }

    int amt = rand() % 901 + 100; // Generate random sleep time between 100 and 1000 milliseconds
    cout << "Thread " << id << " is preparing to sleep for " << amt << " milliseconds" << endl; // Print sleep preparation message
    this_thread::sleep_for(amt * 1ms); // Sleep for generated time


    int val = rand() % 100 + 1; // Generate random value between 1 and 100
    cout << "Thread " << id << " is returning the value " << val << endl; // Print returned value message
    P.set_value(val); // Set value in promise object
}

// Function to notify threads to start execution

void runSimulation() {
    unique_lock<mutex> lck(mtx);
    allReady = true;
    cv.notify_all();
}


// Main function

int main() {
    int N; //numOfThreads to create
    vector<thread> V;
    cout << "Enter a non-negative integer: ";
    cin >> N;
    while (N < 0) {
        cout << "Invalid input. Please enter a non-negative value: ";
        cin >> N;
    }

    for (int i = 0; i < N; ++i) {
        promise<int> P; // Create promise for each thread
        future<int> F = P.get_future(); // Get future from promise
        V.push_back(thread(doStuff, std::move(P), i)); // Create thread and add to vector
    }

    cout << "READY TO RELEASE THE THREADS" << endl; // Print message indicating threads are ready to be released
    runSimulation(); // Notify threads to start execution

    for (auto& thread : V) {
        thread.join(); // Wait for threads to finish execution
    }
    cout << "Program Execution Complete" << endl;
    return 0;
}
