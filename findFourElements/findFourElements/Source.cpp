/*Given an array of integers, find a combination of four elements in the array whose sum is equal to a given value X.

Input:
First line consists of T test cases.First line of every test case consists of an integer N, denoting the number of elements in an array.Second line consists of N spaced array elements.Third line of every test case X.

Output:
	Single line output, print 1 if combination is found else 0.

		Constraints :
		1 <= T <= 100
		1 <= N <= 100

		Example :
		Input :
		1
		6
		1 5 1 0 6 0
		7
		Output :
		1
*/

#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//Efficeincy O(n3). Idea is to sort and apply the logic as given below
void findFourElements(vector<int> vec, int sum) {
	sort(vec.begin(), vec.end());
	for (vector<int>::iterator i = vec.begin(); i != vec.end() - 3; i++) {
		for (vector<int>::iterator j = i + 1; j != vec.end() - 2; j++) {
			vector<int>::iterator l = j + 1;
			vector<int>::iterator r = vec.end() - 1;
			while (l < r) {
				if (*i + *j + *l + *r == sum) {
					cout << endl << "Four elements exist!!. ";
					cout << "Those elements are " << *i << " " << *j << " " << *l << " and " << *r;
					return;
				}
				else if (*i + *j + *l + *r < sum)
					l++;
				else
					r--;
			}
		}
	}
	cout << endl << "NO four elements.";
}
//hash based in O(n2). Uses unoredered_maps which is basically hash map.
//create pairs using unordered_map and find the other pair whose sum is equal to X
void hashBasedFindFourElements(vector<int>vec, int X) {
	unordered_map<int, pair<int, int>> mymap;
	int sum;
	for (int i = 0; i < vec.size() - 1; i++) 
		for (int j = i + 1; j < vec.size(); j++)
			mymap[vec[i]+vec[j]] = { i, j };

	for (int i = 0; i < vec.size() - 1; i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			sum = vec[i] + vec[j];
			if (mymap.find(X - sum) != mymap.end()) {
				pair<int, int> pr = mymap[X-sum];
				//Check that all four elements are unique entries(indices) in vector
				if (pr.first != i && pr.first != j &&
					pr.second != i && pr.second != j) {
					cout << "Four elements exist whose sum is " << X;
					cout << endl << vec[i] << vec[j] << vec[pr.first] << vec[pr.second];
					return;
				}
			}
		}
	}
	cout << endl<< "Four elements don't exist whose sum is " << X;
}
int main() {
	int N, sum;
	vector<int> vec;
	cout << "Enter the number of elemnts: ";
	cin >> N;
	cout << endl << "Enter " << N << " elements: ";
	for (int i = 0; i < N; i++) {
		cin >> sum;
		vec.push_back(sum);
	}
	cout << endl << "Enter the sum element: ";
	cin >> sum;
	
	//findFourElements(vec, sum); //Naive approach
	hashBasedFindFourElements(vec, sum);
	_getch();
	return 0;
}