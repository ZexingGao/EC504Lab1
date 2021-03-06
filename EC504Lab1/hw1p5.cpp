// Copyright 2018 Zexing Gao zexing@bu.edu
#include <iostream>
#include <fstream>
#include <chrono>

//#include <stdio.h>
using namespace std;

/***********************************************************
Main progam template for find by bisecton and dictonaruy
************************************************************/

int findBisection(int key, int *a, int n);
int findDictionary(int key, int *a, int n);

int main(int argc, char *argv[])
{
	/* Timeing and IO setup */
	chrono::time_point<chrono::steady_clock> start, stop;
	chrono::duration<double> difference_in_time;
	double difference_in_seconds; // Holds the final run time
	double difference_in_seconds_dictionary; // Holds the final run time
	ifstream infile;

	/* Local data */
	int n;
	int key;
	int find_index = -1;
	int find_index_dictionary = -1;

	/* Input Data: To not change */
	infile.open(argv[1]);
	if (!infile) {
		cout << "Error opening file " << endl;
		return -1;
	}
	infile >> key;
	infile >> n;

	int *A = new int[n];

	for (int i = 0; i < n; i++)
		infile >> A[i];
	infile.close();


	/* Find Key by Dictionary Search  */
	start = chrono::steady_clock::now();
	find_index_dictionary = findDictionary(key, A, n);
	stop = chrono::steady_clock::now();
	difference_in_time = stop - start;
	difference_in_seconds_dictionary = double(difference_in_time.count());

	/* Check against Key by Bisection  */
	find_index = findBisection(key, A, n);

	//cout<< find_index <<endl;

	
	//Begin output file : DO NOT CHANGE
	ofstream outfile(strcat(argv[1], "_out"));
	outfile << difference_in_seconds_dictionary << endl;

	outfile << find_index_dictionary << endl;
	if (find_index_dictionary != -1)  outfile << A[find_index_dictionary] << endl;

	outfile << find_index << endl;
	if (find_index != -1)  outfile << A[find_index] << endl;
	//End output file
	
	
	
	
	//system("pause");
	return 0;
	
}

int findBisection(int key, int *a, int N)
{
	int left = 0;
	int right = N - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid]>key) {
			right = mid-1;
		}
		else if (a[mid] < key) {
			left = mid + 1;
		}
		else if (a[mid] == key) {
			return mid;
		}
	}
	int index = -1;
	return index;
}

int findDictionary(int key, int *a, int N)
{
	int left = 0;
	int right = N - 1;
	double x;
	int m;

	
	while (left <= right) {
		x = double(key - a[left]) / (double(a[right]) - a[left]);
		m = int(left + x * (right - left));
		if (a[m] < key) {
			left = m + 1;
		}
		else if (a[m] > key) {
			right = m - 1;
		}
		else if (a[m] == key) {
			return m;
		}
	}

	int index = -1;

	return index;
}