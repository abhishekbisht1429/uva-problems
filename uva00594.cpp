#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int convert(int n) {
    unsigned int mask = 0x000000ff;
    unsigned int out = 0x00000000;

    for(int i=0;i<4;++i) {
        unsigned int val = n & mask;
        val = val>>8*i;
        val = val<<8*(3-i);
        out = out | val;
        mask = mask<<8;
    }
    return out;
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

        if(cin.fail()) break;
        cout<<n<<" converts to "<<convert(n)<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}