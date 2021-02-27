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
        vector<string> fragments;
        int sum = 0;
        while(1) {
            string frag;
            getline(cin, frag);
            // cout<<"frag"<<frag<<endl;

            if(frag.size() == 0) {
                break;
            }
            fragments.push_back(frag);
            sum += frag.size();
        }
        int n = fragments.size();
        int b = 2 * sum / n;

        unordered_map<string, int> freq_map;
        for(int i=0;i<n; ++i) {
            for(int j=0;j<n;++j) {
                if(i!=j) {
                    string orig_pattern = fragments[i] + fragments[j];
                    freq_map[orig_pattern] = freq_map[orig_pattern] + 1;
                }
            }
        }

        string ans;
        int max_count = 0;
        for(auto entry : freq_map) {
            if(entry.second > max_count) {
                ans = entry.first;
                max_count = entry.second;
            }
        }

        cout<<ans<<((t!=0)?"\n":"")<<endl;
    }


    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}