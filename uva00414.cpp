#include<bits/stdc++.h>
#define DEBUG

using namespace std;

int count_blanks(string &s) {
    int count = 0;
    for(int i=0;i<s.length();++i) {
        if(s.at(i) == ' ')
            count++;
    }
    return count;
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
        if(n == 0) break;

        int blank_count[n];
        // cout<<"n : "<<n<<endl;
        cin.ignore(numeric_limits<int>::max(), '\n');
        for(int i=0;i<n;++i) {
            string row;
            getline(cin, row);
            blank_count[i] = count_blanks(row);
        }
        int min_count = blank_count[0];
        for(int i=1;i<n;++i) {
            if(blank_count[i] < min_count) {
                min_count = blank_count[i];
            }
        }

        int ans = 0;
        for(int i=0;i<n;++i) {
            ans += blank_count[i] - min_count;
        }

        cout<<ans<<endl;
    }


    

    return 0;
}