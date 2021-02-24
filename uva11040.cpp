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
        int triangle[10][10];
        for(int i=1;i<=9;i+=2) {
            for(int j=1;j<=i;j+=2) {
                cin>>triangle[i][j];
                // cout<<triangle[i][j]<<" ";    
            }
            // cout<<endl;
        }

        for(int j=2;j<=8;j+=2) {
            triangle[9][j] = (triangle[7][j-1] - (triangle[9][j-1] + triangle[9][j+1]))/2;
        }
        for(int i=8;i>=1;i--) {
            for(int j=1;j<=i;++j) {
                triangle[i][j] = triangle[i+1][j] + triangle[i+1][j+1];
            }
        }

        for(int i=1;i<=9;++i) {
            for(int j=1;j<=i;++j) {
                cout<<triangle[i][j];
                cout<<(j!=i?" ":"");
            }
            cout<<endl;
        }
    }

    return 0;
}