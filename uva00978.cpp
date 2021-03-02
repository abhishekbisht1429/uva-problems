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
    while(t--) {
        int b, sg, sb;
        cin>>b>>sg>>sb;
        multiset<int, greater<int>> msetG, msetB;
        for(int i=0;i<sg;++i) {
            int temp;
            cin>>temp;
            msetG.insert(temp);
        }
        for(int i=0;i<sb;++i) {
            int temp;
            cin>>temp;
            msetB.insert(temp);
        }

        while(!msetG.empty() && !msetB.empty()) {
            int bf_size = min((size_t)b, min(msetG.size(), msetB.size()));
            vector<int> res_vec(bf_size);
            for(int i=0; i<bf_size; ++i) {
                int g = *(msetG.begin());
                int b = *(msetB.begin());

                msetG.erase(msetG.begin());
                msetB.erase(msetB.begin());

                res_vec[i] = g - b;
            }
            for(auto res : res_vec) {
                if(res > 0) {
                    msetG.insert(res);
                } else if(res < 0) {
                    msetB.insert(-res);
                }
            }
        }
        if(!msetG.empty()) {
            cout<<"green wins"<<endl;
            for(auto i : msetG) {
                cout<<i<<endl;
            }
        } else if(!msetB.empty()) {
            cout<<"blue wins"<<endl;
            for(auto i : msetB) {
                cout<<i<<endl;
            }
        } else {
            cout<<"green and blue died"<<endl;
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