/*https://www.hackerrank.com/challenges/repeated-string/problem?h_l=interview&h_r=next-challenge&h_v=zen&isFullScreen=false&playlist_slugs%5B%5D%5B%5D%5B%5D%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D%5B%5D%5B%5D%5B%5D=warmup
 */

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
long count = 0;
    long len = s.length();

    if(len < 1 && len > 100) 
        exit(0);
    if(n < 1 && n > 1000000000000)
        exit(0);
    if(len == 1 && s.front() == 'a') 
        return n;

    for(long i = 0; i < len; i++) { //caclculate no. of 'a's in s
        if(s[i] == 'a')
            count++;
    }
    if(len >= n) {  //if len>n, search for 'a' and increment count
        count = 0;
        for(long i = 0; i < n; i++) {
            if(s[i] == 'a')
                count++;
        }
    }
    else {
        //n = n - len;
        long a = (long)n/len;
        count = count * a;
        long b = (long)n % len; //reamining substring
     
        for(long i = 0; i < b; i++) { //concat the remaining substring of reduced n
            if(s[i] == 'a')
                count++;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    //fout << result << "\n";

    fout.close();

    return 0;
}
