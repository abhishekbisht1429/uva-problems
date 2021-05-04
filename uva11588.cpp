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
    int x;
    cin>>x;
    for(int case_n = 1; case_n <= x; ++case_n) {
        int r, c, m, n;
        cin>>r>>c>>m>>n;

        vector<string> vec(r);
        for(int i=0;i<r;++i) {
            cin>>vec[i];
        }

        unordered_map<char, int> freq_map;
        for(string str : vec) {
            for(char c : str) {
                if(freq_map.find(c) == freq_map.end()) {
                    freq_map[c] = 0;
                }
                freq_map[c]++;
            }
        }

        int max_freq = 0;
        for(auto &p : freq_map) {
            max_freq = max(max_freq, p.second);
        }

        int total_bytes = 0;
        for(auto &p : freq_map) {
            int freq = p.second;
            total_bytes += ((freq == max_freq)?m:n) * freq;
        }

        cout<<"Case "<<case_n<<": "<<total_bytes<<endl;

    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}