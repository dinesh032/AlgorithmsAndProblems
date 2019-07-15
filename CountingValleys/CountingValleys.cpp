/*https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
 * Problem statement in above link
 */
#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    if(n > 1000000 || n < 2 )
        exit(0);
    signed int count = 0, valley = 0;
    for(std::string::iterator itr = s.begin(); itr!=s.end();++itr)
    {
	if(*itr != 'U' && *itr != 'D') {
		cout<<"Char's other than U and D"<<endl;
		exit(0);
	}
	if(*itr == 'U') {
		count++;
		if(count == 0)
			valley++;
	}
        if(*itr == 'D')
		count--;
    }
    return valley;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cout<<"Enter no. of steps";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    cout<<endl<<"Enter string ";
    getline(cin, s);

    int result = countingValleys(n, s);
    n = result;
    cout<<endl<<endl<<"the number of valleys is:" ;
   // fout << result << "\n";
    cout<<n<<endl;
    fout.close();

    return 0;
}
   
