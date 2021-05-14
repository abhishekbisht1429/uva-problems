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
    int n;
    cin>>n;

    for(int i=0;i<n;++i) {
        bitset<26> acorn;
        acorn.set();
        int e = 0;

        while(1) {
            string str;
            cin>>str;

            if(str[0] == '*') break;

            int u = str[1] - 'A';
            int v = str[3] - 'A';

            acorn[u] = 0;
            acorn[v] = 0;
            e++;
        }
        string str;
        cin>>str;
        str += ",";

        int v = 0;
        int n_acorn = 0;
        for(int i=0; i<str.size(); i+=2) {
            v++;
            n_acorn += acorn[str[i] - 'A'];
        }

        int n_tree = max(1, v - e) - n_acorn;

        cout<<"There are "<<n_tree<<" tree(s) and "<<n_acorn<<" acorn(s)."<<endl;

    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}