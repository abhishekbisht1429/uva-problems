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
        int n;
        cin>>n;

        if(cin.fail()) break;

        int n_corner = (int)pow(2, n);

        unordered_map<int, vector<int>> adj_map;
        for(int i=0;i<n_corner; ++i) {
            int mask = 0x00000001;
            for(int j=0;j<n;++j) {
                adj_map[i].push_back(i ^ mask);
                mask = mask<<1;
            }
        }

        unordered_map<int, int> weight_map;
        for(int i=0; i<(int)pow(2,n); ++i) {
            cin>>weight_map[i];
        }

        unordered_map<int, int> potent_map;
        for(int i = 0; i < n_corner; ++i) {
            for(int adj_corner : adj_map[i]) {
                if(potent_map.find(i) == potent_map.end()) {
                    potent_map[i] = 0;
                }
                potent_map[i] += weight_map[adj_corner];
            }
        }

        int max_sum = 0;
        for(int i=0; i<n_corner; ++i) {
            for(int adj_corner : adj_map[i]) {
                max_sum = max(max_sum, potent_map[i] + potent_map[adj_corner]);
            }
        }

        cout<<max_sum<<endl;

    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}