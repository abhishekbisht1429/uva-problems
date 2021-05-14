#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    while(1) {
        int n;
        cin>>n;

        if(n==0) break;

        int a = 0x00000000;
        int b = 0x00000000;
        int mask = 0x00000001;

        int i=1;
        while(mask!=0) {
            int val = n & mask;
            if(val != 0) {
                if(i%2 != 0) {
                    a = a | val;
                } else {
                    b = b | val;
                }
                ++i;
            }
            mask = mask<<1;
        }

        cout<<a<<" "<<b<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}