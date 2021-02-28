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
    ignore_lines(2);

    while(t--) {

        unordered_map<string, int> treeToFreq;
        int total = 0;
        while(1) {
            string tree;
            getline(cin, tree);

            if(tree.size() == 0) break;

            treeToFreq[tree] += 1;
            total++;
        }

        vector<pair<string,int>> treeFreq(treeToFreq.begin(), treeToFreq.end());
        sort(treeFreq.begin(), treeFreq.end());

        for(auto &p : treeFreq) {
            cout<<p.first<<" "<<fixed<<setprecision(4)<<round((p.second * 100.0 / total) * 10000) / 10000<<endl;
        }
        cout<<(t?"\n":"");
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}