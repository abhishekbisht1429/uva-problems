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

        vector<int> vec(pow(2, n));

        for(int i=0;i<vec.size();++i) {
            vec[i] = 1;
        }

        for(int i=0;i<m;++i) {
            int temp;
            cin>>temp;
            vec[temp-1] = 0;
        }

        int end = vec.size() - 1;
        int count = 0;
        while(end > 0) {
            int j = 0;
            for(int i=0; i<end; i+=2) {
                count += vec[i] != vec[i+1];
                vec[j] = vec[i] | vec[i+1];
                j++;
            }
            end = ((end+1)/2 - 1);
        }

        cout<<count<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}