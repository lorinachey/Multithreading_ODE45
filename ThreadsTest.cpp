// ThreadsTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include "functions.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdio>
#include <thread>
#include <time.h>
#include <chrono> 

using namespace std;
using namespace std::chrono;


int main() {

	double x = 0.0, y = 3.0;         //initial values
	double y_1, y_2;                 //results variables for threads 1 and 2

	thread prethread(ode45, &x, &y, &y_1, 0.05);
	prethread.join();

	// Use auto keyword to avoid typing long 
	// type definitions to get the timepoint 
	// at this instant use function now() 
	auto start = high_resolution_clock::now();
	thread first(ode45, &x, &y, &y_1, 0.25);
	auto stop = high_resolution_clock::now();
	auto duration_1 = duration_cast<microseconds>(stop - start);

	auto start_2 = high_resolution_clock::now();
	thread second(ode45, &x, &y, &y_2, 0.5);
	auto stop_2 = high_resolution_clock::now();
	auto duration_2 = duration_cast<microseconds>(stop_2 - start_2);

	//normally would want to check if these are joinable
	first.join();
	second.join();

	printf("y_1: %f \n", y_1);
	printf("y_2: %f \n", y_2);
	cout << "Duration thread 1: " << duration_1.count() << endl;
	cout << "Duration thread 2: " << duration_2.count() << endl;

	return 0;
}

// double x_values_array[] = {0.0, 0.25, 0.5, 0.75, 1.0};
// double y_results_array[] = {0.0, 0.0, 0.0, 0.0, 0.0};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
