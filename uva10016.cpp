#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void display(vector<vector<int>> &matrix) {
    for(int i=0;i<matrix.size();++i) {
        for(int j=0;j<matrix.size();++j) {
            cout<<matrix[i][j];
            if(j!=matrix.size()-1) {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    // cout<<endl;
}
void reverse_row(vector<vector<int>> &matrix, int row, int j_start, int j_end) {
    int i = row;
    for(int j=j_start;j<=(j_start + j_end)/2;++j) {
        swap(matrix[i][j], matrix[i][j_start + j_end - j]);
    }
}
void reverse_col(vector<vector<int>> &matrix, int col, int i_start, int i_end) {
    int j = col;
    for(int i=i_start;i<=(i_start + i_end)/2;++i) {
        swap(matrix[i][j], matrix[i_start + i_end - i][j]);
    }
}
void up_down_flip(vector<vector<int>> &matrix, int ring) {
    // cout<<"up down "<<ring<<endl;
    int r_start = ring-1;
    int r_end = matrix.size() - r_start - 1;
    // cout<<r_start<<" "<<r_end<<endl;

    reverse_col(matrix, r_start, r_start, r_end);

    reverse_col(matrix, r_end, r_start, r_end);

    for(int j=r_start+1;j<=r_end-1;++j) {
        swap(matrix[r_start][j], matrix[r_end][j]);
    }
}

void left_right_flip(vector<vector<int>> &matrix, int ring) {
    // cout<<"left_right "<<ring<<endl;
    int r_start = ring-1;
    int r_end = matrix.size() - r_start - 1;
    // cout<<r_start<<" "<<r_end<<endl;

    reverse_row(matrix, r_start, r_start, r_end);

    reverse_row(matrix, r_end, r_start, r_end);

    for(int i=r_start+1;i<=r_end-1;++i) {
        swap(matrix[i][r_start], matrix[i][r_end]);
    }
}

void main_d_flip(vector<vector<int>> &matrix, int ring) {
    // cout<<"main_d "<<ring<<endl;

    int r_start = ring-1;
    int r_end = matrix.size() - r_start - 1;

    int i = r_start;
    for(int j=r_start;j<=r_end;++j) {
        swap(matrix[i][j], matrix[j][i]);
    }

    int j = r_end;
    for(i=r_start+1; i<=r_end;++i) {
        swap(matrix[i][j], matrix[j][i]);
    }

}
void inverse_d_flip(vector<vector<int>> &matrix, int ring) {
    // cout<<"inverse_d "<<ring<<endl;

    int r_start = ring-1;
    int r_end = matrix.size() - r_start - 1;

    int i = r_start;
    for(int j=r_start;j<=r_end;++j) {
        swap(matrix[i][j], matrix[r_end - (j - r_start)][r_end]);
    }

    int j = r_start;
    for(i=r_start+1; i<=r_end;++i) {
        swap(matrix[i][j], matrix[r_end][r_end - (i - r_start)]);
    }
}
void flip(vector<vector<int>> &matrix, int ring, int c) {
    // display(matrix);
    switch(c) {
        case 1: {
            up_down_flip(matrix, ring);
            // display(matrix);
            break;
        }
        case 2: {
            left_right_flip(matrix, ring);
            //display(matrix);
            break;
        }
        case 3: {
            main_d_flip(matrix, ring);
            //display(matrix);
            break;
        }
        case 4: {
            inverse_d_flip(matrix, ring);
            //display(matrix);
            break;
        }
        default: break;
    }
}
int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    int m;
    cin>>m;
    while(m--) {
        int n;
        cin>>n;
        vector<vector<int>> matrix(n);
        for(int i=0;i<n;++i) {
            matrix[i] = vector<int>(n);
            for(int j=0;j<n;++j) {
                cin>>matrix[i][j];
            }
        }
        int n_ring = (n+1)/2;

        for(int i=1;i<=n_ring;++i) {
            int t;
            cin>>t;
            for(int j=0;j<t;++j) {
                int c;
                cin>>c;
                flip(matrix, i, c);
            }
        }
        display(matrix);
    }
    

    return 0;
}