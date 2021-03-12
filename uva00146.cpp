#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
char findAndReplaceSucc(string &sub, char c) {
    sort(sub.begin(), sub.end());
    auto itr = sub.begin();
    while(*itr <= c) {
        ++itr;
    }
    swap(c, *itr);

    return c;
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
        string str;
        cin>>str;

        if(str == "#") break;

        int i = str.size() - 2;
        while(i>=0 && str[i] >= str[i+1]) {
            --i;
        }
        if(i >=0) {
            string pre = str.substr(0, i);
            string suf = str.substr(i+1, str.size());
            char succ = findAndReplaceSucc(suf, str[i]);
            sort(suf.begin(), suf.end());
            cout<<pre<<succ<<suf<<endl;
        } else {
            cout<<"No Successor"<<endl;
        }
        
    }    

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}