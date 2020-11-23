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

    for(int x = 1;x<=t;++x) {
        int n;
        cin>>n;
        vector<int> p(n), q(n);
        for(int i=0;i<n;++i) {
            cin>>p[i];
        }
        for(int i=0;i<n;++i) {
            cin>>q[i];
        }

        int count = 0;
        int start = 0;
        int sum = 0;

        while(start < n) {
            int pos = (start + count) % n;
            if(p[pos] < q[pos] && sum + p[pos] < q[pos]) {
                start = start + count + 1;
                count = sum = 0;
            } else {
                sum += p[pos] - q[pos];
                count++;

                if(count == n) break;
            }
        }

        cout<<"Case "<<x<<": ";
        if(count == n) {
            cout<<"Possible from station "<<(start+1)<<endl;
        } else {
            cout<<"Not possible"<<endl;
        }
    }

    return 0;
}