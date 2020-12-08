#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void display(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
vector<vector<int>> rotate90(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<vector<int>> temp;
    for(int i=0;i<n;++i) {
        temp.push_back(vector<int>(n));
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            temp[j][n-i-1] = matrix[i][j];
        }
    }
    return temp;
}
vector<vector<int>> rotate180(vector<vector<int>> &matrix) {
    auto r90 = rotate90(matrix);
    auto r180 = rotate90(r90);
    return r180;
}
vector<vector<int>> rotate270(vector<vector<int>> &matrix) {
    auto r90 = rotate90(matrix);
    auto r180 = rotate90(r90);
    auto r270 = rotate90(r180);
    return r270;
}

vector<vector<int>> reflectv(vector<vector<int>> &matrix) {
    int n = matrix.size();
    // cout<<"n : "<<n<<endl;
    vector<vector<int>> temp;
    for(int i=0;i<n;++i) {
        temp.push_back(vector<int>(n));
    }
    for(int j=0;j<n;++j) {
        for(int i=0;i<n;++i) {
            temp[n-i-1][j] = matrix[i][j];
        }
    }
    // display(temp);
    return temp;
}



bool mat_equal(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    int n = matrix1.size();
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            if(matrix1[i][j] != matrix2[i][j])
                return false;
        }
    }
    return true;
}
string check(vector<vector<int>> &org_mat, vector<vector<int>> &trans_mat) {
    if(mat_equal(org_mat, trans_mat)) {
        return "preserved";
    }
    auto r90 = rotate90(org_mat);
    if(mat_equal(r90, trans_mat)) {
        return "rotated 90 degrees";
    }
    auto r180 = rotate90(r90);
    if(mat_equal(r180, trans_mat)) {
        return "rotated 180 degrees";
    }
    auto r270 = rotate90(r180);
    if(mat_equal(r270, trans_mat)) {
        return "rotated 270 degrees";
    }

    auto rflct = reflectv(org_mat);
    if(mat_equal(rflct, trans_mat)) {
        return "reflected vertically";
    }

    r90 = rotate90(rflct);
    if(mat_equal(r90, trans_mat)) {
        return "reflected vertically and rotated 90 degrees";
    }
    r180 = rotate90(r90);
    if(mat_equal(r180, trans_mat)) {
        return "reflected vertically and rotated 180 degrees";
    }
    r270 = rotate90(r180);
    if(mat_equal(r270, trans_mat)) {
        return "reflected vertically and rotated 270 degrees";
    }

    return "improperly transformed";
}
int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    // int n = 4;
    // vector<vector<int>> matrix;
    // for(int i=0;i<n;++i) {
    //     matrix.push_back(vector<int>(n));
    // }
    // for(int i=0;i<n;++i) {
    //     for(int j=0;j<n;++j) {
    //         matrix[i][j] = i*j;
    //     }
    // }

    // display(matrix);
    // auto t = rotate180(matrix);
    // display(t);

    int count = 0;
    while(1) {
        int n;
        cin>>n;

        if(cin.fail()) break;

        vector<vector<int>> org_mat, trans_mat;
        for(int i=0;i<n;++i) {
            org_mat.push_back(vector<int>(n));
            trans_mat.push_back(vector<int>(n));
        }

        for(int i=0;i<n;++i) {
            string s_org, s_trans;
            cin>>s_org>>s_trans;
            for(int j=0;j<n;++j) {
                org_mat[i][j] = s_org[j]=='X'?1:0;
                trans_mat[i][j] = s_trans[j]=='X'?1:0;
            }
        }

        // display(org_mat);
        // display(trans_mat);
        cout<<"Pattern "<<(++count)<<" was "<<check(org_mat, trans_mat)<<"."<<endl;

    }    

    return 0;
}