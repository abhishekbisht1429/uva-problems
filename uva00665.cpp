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

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    int m;
    cin>>m;
    ignore_lines(1);
    while(m--) {
        ignore_lines(1);
        int n, k;
        cin>>n>>k;
        vector<bool> vec(n+1, false);

        while(k--) {
            int p;
            cin>>p;
            vector<int> vals(2*p);
            for(int i=0;i<2*p;++i) {
                cin>>vals[i];
            }
            ignore_lines(1);
            string res;
            getline(cin, res);

            if(res == "=") {
                for(int i=0;i<2*p;++i) {
                    vec[vals[i]] = true;
                }
            } else {
                for(int i=1;i<=n;++i) {
                    bool found = true;
                    for(int j=0;j<2*p;++j) {
                        if(i == vals[j]) {
                            found = true;
                            break;
                        }
                    }
                    if(!found) {
                        vec[i] = true;
                    }
                }
            }
        }
        int falseCoin;
        int falseCount = 0;
        for(int i=1;i<=n;++i) {
            if(vec[i] == false) {
                falseCount++;
                falseCoin = i;
            }
        }
        if(falseCount == 1) {
            cout<<falseCoin<<endl;
        } else {
            cout<<0<<endl;
        }
        if(m!=0) cout<<endl;
    }

    return 0;
}