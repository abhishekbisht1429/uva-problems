#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_line() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    for(int set = 1; true; ++set){
        int n;
        cin>>n;

        if(n==0) break;
        vector<int> heights(n);
        int total = 0;
        for(int i=0;i<n;++i) {
            cin>>heights[i];
            total += heights[i];
        }

        int req_height = total/n;

        int min_moves = 0;
        for(int i=0;i<n;++i) {
            if(heights[i] > req_height) {
                min_moves += heights[i] - req_height;
            }
        }

        cout<<"Set #"<<set<<endl;
        cout<<"The minimum number of moves is "<<min_moves<<"."<<endl;
        cout<<endl;
    }
    
    return 0;
}