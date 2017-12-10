//Pythagorean Triplet in an array.
//Given an array of integers, write a function that returns true if there is a triplet(a, b, c) that satisfies a2 + b2 = c2.
#include<iostream>
#include<conio.h>
#include<algorithm>

using namespace std;

bool isTriplet(int a[], int n) {
	for (int i = 0; i < n; i++)
		a[i] = a[i] * a[i];
	sort(a, a + n);
	
	for (int i = n - 1; i >= 2; i--) {
		int l = 0;
		int r = i - 1;
		while (l < r) {
			if (a[l] + a[r] == a[i]) {
				cout << "Triplets are present, they are " << sqrt(a[l]) << ", " << sqrt(a[r]) << " & " << sqrt(a[i]) << endl;
				return true;
			}
			(a[l] + a[r] < a[i]) ? l++ : r--;
		}
	}
	return false;
}
int main() {

	int a[] = {3, 1, 4, 6, 5};
	int n = 5;
	bool result = isTriplet(a, n);
	if (result)
		cout << "Triplets present" << endl;
	else
		cout << "Triplets NOT present" << endl;
	_getch();
	return 0;
}