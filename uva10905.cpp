#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
bool comp(string s1, string s2) {
    int i, j;
    i = j = 0;
    while(i < s1.size() && j < s2.size()) {
        if(s1[i] > s2[j]) {
            return true;
        } else if(s1[i] < s2[j]) {
            return false;
        }
        i++;
        j++;
    }
    if(i < s1.size()) { // s2 was shorter
        return comp(s1.substr(i), s2);
    } else if(j < s2.size()) {
        return comp(s1, s2.substr(j));
    }
    return false;
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

        vector<string> vec(n);
        for(int i=0;i<n;++i) {
            cin>>vec[i];
        }
        sort(vec.begin(), vec.end(), comp);
        for(string str : vec) {
            cout<<str;
        }
        cout<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}