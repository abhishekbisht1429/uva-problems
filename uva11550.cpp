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
        int n, m;
        cin>>n>>m;

        vector<bitset<30>> edge_bitset(m);

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                int bit;
                cin>>bit;
                edge_bitset[j][i] = bit;
            }
        }

        //check
        bool isGraph = true;
        for(int j=0; j<m; ++j) {
            if(edge_bitset[j].count() != 2) {
                isGraph = false;
                break;
            }
        }

        if(isGraph) {
            for(int i=0; i<m; ++i) {
                for(int j=i+1; j<m; ++j) {
                    if((edge_bitset[i] ^ edge_bitset[j]).none()) {
                        isGraph = false;
                        break;
                    }
                }
                if(!isGraph) {
                    break;
                }
            }
        }

        if(isGraph) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }

    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}