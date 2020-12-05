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

    while(1) {
        int n;
        cin>>n;

        if(n==0) break;

        vector<int> vec(n);
        for(int i=0;i<n;++i) {
            cin>>vec[i];
        }
        int count = 0;
        for(int i=0;i<n;++i) {
            int prev = (i-1)<0?(n-1):(i-1);
            int next = (i+1)%n;

            if( (vec[i]>vec[prev] && vec[i]>vec[next]) ||
                (vec[i]<vec[prev] && vec[i]< vec[next])) {
                    count++;
                }
        }
        cout<<count<<endl;
    }
    

    return 0;
}