#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void reverse(string &s) {
    int len = s.size();
    for(int i=0;i<len/2;++i) {
        char temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
}
int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    while(1) {
        int g;
        cin>>g;

        if(g==0) break;

        string inp;
        cin>>inp;

        string out;
        int g_size = inp.size()/g;
        for(int i=0; i<inp.size(); i=i+g_size) {
            string sub = inp.substr(i, g_size);
            reverse(sub);
            out.append(sub);
        }
        cout<<out<<endl;

    }
    return 0;
}