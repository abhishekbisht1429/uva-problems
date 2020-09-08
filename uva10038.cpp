//jolly jumpers
#include<bits/stdc++.h>
#define DEBUG

using namespace std;

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
        if(cin.fail()) break;

        int *arr = new int[n];
        int *bool_map = new int[n+1];
        for(int i=0;i<n;++i) {
            cin>>arr[i];
        }

        for(int i=1;i<n;++i) {
            int diff = abs(arr[i] - arr[i-1]);
            if(diff>=1 && diff<=n-1) bool_map[diff] = true;
        }

        bool ans = true;
        for(int i=1;i<=n-1;++i) {
            ans = ans && bool_map[i];
        }

        if(ans == true) {
            cout<<"Jolly"<<endl;
        } else {
            cout<<"Not jolly"<<endl;
        }

    }

    return 0;
}