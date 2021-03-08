#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int countSetDiff(unordered_multiset<int> &s1, unordered_multiset<int> &s2) {
    int count = 0;
    auto itr1 = s1.begin();
    while(itr1 != s1.end()) {
        auto itr2 = s2.find(*itr1);

        if(itr2 != s2.end()) {
            auto temp_itr = itr1++;
            s1.erase(temp_itr);
            s2.erase(itr2);
        } else {
            itr1++;
        }
    }
    return s1.size() + s2.size();
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
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        unordered_multiset<int> s1, s2;
        for(int i=0;i<n;++i) {
            int temp;
            cin>>temp;
            s1.insert(temp);
        }

        for(int i=0;i<m;++i) {
            int temp;
            cin>>temp;
            s2.insert(temp);
        }

        cout<<countSetDiff(s1, s2)<<endl;
    }
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}