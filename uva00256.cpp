#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define umap unordered_map
#define uset unordered_set
#define ll long long
#define vec vector

#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

#define SIZE 10000

string s[9];
int square[SIZE];

string find(int n) {
    ostringstream oss;
    for(int i=0; i<pow(10, n/2); ++i) {
        int a = square[i] / (int)pow(10, n/2);
        int b = square[i] % (int)pow(10, n/2);
        if(pow(a+b,2) == square[i]) {
            oss<<setfill('0')<<setw(n)<<square[i]<<"\n";
        }
    }
    return oss.str();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");
    streambuf* in_backup = cin.rdbuf();
    streambuf* out_backup = cout.rdbuf();
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf()); 
    #endif

    /* ######################CODE_START################################ */
    for(int i=0; i<SIZE; ++i) {
        square[i] = i*i;
    }
    while(1) {
        int n;
        cin>>n;
        if(cin.fail()) break;

        if(s[n].size()==0) {
            s[n] = find(n);
        }
        cout<<s[n];
    }
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}