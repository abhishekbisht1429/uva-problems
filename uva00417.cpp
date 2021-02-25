#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void generate(int len, string str, unordered_map<string,int> &index_map) {
    static int count = 0;
    if(len<1) {
        count++;
        // cout<<"h"<<str<<endl;
        index_map[str] = count;
        return;
    }

    char c = str.size()>0?str[str.size()-1]+1:'a';
    for(;c<='z';++c) {
        string temp = str + c;
        generate(len-1, temp, index_map);
    }

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

    unordered_map<string,int> index_map;
    for(int i=1;i<=5;++i) {
        generate(i, "", index_map);
    }

    while(1) {
        string str;
        cin>>str;

        if(cin.fail()) break;

        cout<<index_map[str]<<endl;
    }
    



    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}