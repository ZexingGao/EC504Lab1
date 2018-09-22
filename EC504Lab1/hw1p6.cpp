// Copyright 2018 Zexing Gao zexing@bu.edu

#include <iostream>
#include <fstream>
#include <chrono>


using namespace std;

/***********************************************************
Exercise: Given two sorted arrays: A and B find
the median of the combined sorted  array: C = A + B.
This out actual constructing C this can be done in order
 log(smaller of the A and B array). Assume the size of the A and B
is oded
************************************************************/

int find_median(int *a, int n, int *b, int m);

int main(int argc, char *argv[]) {

	chrono::time_point<chrono::steady_clock> start, stop;
	chrono::duration<double> difference_in_time;
	double difference_in_seconds; // Holds the final run time

	ifstream infile1;
	int n;
	int m;
	int median = 0;

	infile1.open(argv[1]);
	if (!infile1) {
		cout << "Error opening file " << endl;
		return -1;
	}

	infile1 >> n;
	int *A = new int[n];
	for (int i = 0; i < n; i++)
		infile1 >> A[i];

	infile1 >> m;
	int *B = new int[m];
	for (int i = 0; i < m; i++)
		infile1 >> B[i];

	infile1.close();

	/* Find the median \  */
	start = chrono::steady_clock::now();
	median = find_median(A, n, B, m);
	stop = chrono::steady_clock::now();
	difference_in_time = stop - start;
	difference_in_seconds = double(difference_in_time.count());

	cout << median << endl;
	cout << difference_in_seconds << endl;

	return 0;
}


int find_median(int *a, int n, int *b, int m) {
	
	int min = 0;
	int max = n;
	int i, j, mid;
	//explain:
	//the worst case for this while loop is O(log[min(n,m)]) 
	//others are just constants
	while (min <= max){
		i = (max + min) / 2;
		j = ((n + m + 1) / 2) - i;

		if (j > 0 and j < m and b[j] < a[i - 1]) {
			max = i - 1;
		}
		else if (i < n and j > 0 and b[j-1] > a[i]) {
			min = i + 1;
		}
		else
		{
			if (j == 0) {
				mid = a[i - 1];
			}
			else if (i == 0) {
				mid = b[j - 1];
			}	
			else if (b[j - 1] < a[j - 1]) {
				mid = a[i - 1];
			}		
			else {
				mid = b[j - 1];
			}	
			break;
		}
		
	}
	return mid;
}