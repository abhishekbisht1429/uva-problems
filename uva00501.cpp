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
    int t;
    cin>>t;
    ignore_lines(1);
    while(t--) {
        int m, n;
        cin>>m>>n;
        vector<int> vecA(m);
        vector<int> vecU(n);
        for(int i=0;i<m;++i) {
            cin>>vecA[i];
        }
        for(int i=0;i<n;++i) {
            cin>>vecU[i];
        }

        multiset<int> mset;
        multiset<int>::iterator itr;
        for(int i=0;i<n;++i) {
            int u = vecU[i];
            for(int j=mset.size(); j<u; ++j) {
                mset.insert(vecA[j]);
                if(i>0 && vecA[j] < *itr) {
                    --itr;
                }
            }
            if(i==0) {
                itr = mset.begin();
            } else {
                itr++;
            }
            cout<<*itr<<endl; 
        }
        if(t) cout<<endl;
    }


    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}