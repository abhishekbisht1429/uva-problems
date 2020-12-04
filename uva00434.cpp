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
        int k;
        cin>>k;
        vector<int> front(k), right(k);
        int max_pos_right = 0;
        int max_pos_front = 0;
        for(int i=0;i<k;++i) {
            cin>>front[i];
            max_pos_front = front[i] > front[max_pos_front]?i:max_pos_front;
        }
        for(int i=k-1;i>=0;--i) {
            cin>>right[i];
            max_pos_right = right[i] > right[max_pos_right]?i:max_pos_right;
        }
        int matrix[k][k];
        for(int i=0;i<k;++i) {
            for(int j=0;j<k;++j) {
                matrix[i][j] = 0;
            }
        }

        int min_blks = 0, max_blks = 0;
        vector<bool> right_placed(k);
        for(int j=0;j<k;++j) {
            bool placed = false;
            for(int i=k-1;i>=0;--i) {
                if(!right_placed[i] && front[j] == right[i]) {
                    matrix[i][j] = front[j];
                    placed = right_placed[i] = true;
                    break;
                }
            }
            if(!placed) {
                matrix[max_pos_right][j] = front[j];
            }
            min_blks += front[j];
        }

        for(int i=0;i<k;++i) {
            if(!right_placed[i]) {
                matrix[i][max_pos_front] = right[i];
                right_placed[i] = true;
                min_blks += right[i];
            }
            for(int j=0;j<k;++j) {
                max_blks += min(front[j], right[i]);
            }
        }

        cout<<"Matty needs at least "<<min_blks<<" blocks, and can"
                " add at most "<<(max_blks-min_blks)<<" extra blocks."<<endl;
    }
    

    return 0;
}