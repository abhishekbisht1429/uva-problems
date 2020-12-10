#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void display(vector<int> &vec) {
    for(int i=0;i<vec.size();++i) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
pair<int, int> check_parity(vector<int> &row_parity, vector<int> &col_parity) {
    int n = row_parity.size();
    int rp_count=0, cp_count=0;
    for(int i=0;i<n;++i) {
        rp_count += row_parity[i];
        cp_count += col_parity[i];
    }
    if(rp_count == 0) {
        if(cp_count == 0) {
            return {-1, -1}; //ok
        } 
    } else if(rp_count == 1) {
        if(cp_count == 1) { //change bit
            int i = 0, j=0;
            for(i=0;i<n;++i) {
                if(row_parity[i]==1) break;
            }
            for(j=0;j<n;++j) {
                if(col_parity[j] == 1) break;
            }
            return {i+1, j+1};
        } 
    }

    return {-2, -2}; // corrupt
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

        vector<vector<int>> matrix(n);
        for(int i=0;i<n;++i) {
            matrix[i] = vector<int>(n);
            for(int j=0;j<n;++j) {
                cin>>matrix[i][j];
            }
        }

        vector<int> row_parity(n), col_parity(n);
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                row_parity[i] ^= matrix[i][j]; 
            }
        }
        for(int j=0;j<n;++j) {
            for(int i=0;i<n;++i) {
                col_parity[j] ^= matrix[i][j];
            }
        }
        pair<int, int> pos = check_parity(row_parity, col_parity);

        if(pos.first == -1) {
            cout<<"OK";
        } else if(pos.first == -2) {
            cout<<"Corrupt";
        } else {
            cout<<"Change bit ("<<pos.first<<","<<pos.second<<")";
        }
        cout<<endl;

    }


    return 0;
}