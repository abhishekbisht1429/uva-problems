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
        int n, m;
        cin>>n>>m;

        if(n==0 && m == 0) break;

        unordered_set<int> set_Jack;
        for(int i=0;i<n;++i) {
            int temp;
            cin>>temp;
            set_Jack.insert(temp);
        }
        int count = 0;
        for(int i=0;i<m;++i) {
            int temp;
            cin>>temp;
            if(set_Jack.find(temp) != set_Jack.end()) {
                count++;
            }
        }
        cout<<count<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}