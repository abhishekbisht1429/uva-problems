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

    int t;
    cin>>t;
    while(t--) {
        int n, p;
        cin>>n>>p;
        int h[p];

        for(int i=0;i<p;++i) {
            cin>>h[i];
        }

        bool h_possible[n];
        for(int i=0;i<n;++i) {
            h_possible[i] = false;
        }

        for(int i=0;i<p;++i) {
            for(int j=h[i]-1;j<n; j+=h[i]) {
                if(j%7 != 5 && j%7 != 6) {
                    h_possible[j] = true;
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;++i) {
            if(h_possible[i]) count++;
        }
        cout<<count<<endl;
    }
    return 0;
}