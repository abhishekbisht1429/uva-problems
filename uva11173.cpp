#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int b2g(int b, int n) {
    int mask = 0x00000001;
    mask = mask<<(n-1);
    int g = 0x00000000;

    g = g | (mask & b);
    mask = mask>>1;
    while(mask !=0) {
        g = g | (((b & (mask<<1))>>1) ^ (b & mask));
        mask = mask>>1;
    }
    return g;
}
int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");
    streambuf* in_backup = cin.rdbuf();
    streambuf* out_backup = cout.rdbuf();
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf()); 
    #endif
    /* ######################CODE_START################################ */
    int n_cases;
    cin>>n_cases;
    while(n_cases--) {
        int n, k;
        cin>>n>>k;

        cout<<b2g(k, n)<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}