#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
vector<vector<int>> matrix;

bool isInRange(int i, int j, int x1, int y1, int x2, int y2) {
    if(x1>x2) {
        swap(x1, x2);
    }
    if(y1>y2) {
        swap(y1, y2);
    }
    return (i>=y1 && i<=y2) && (j>=x1 && j<=x2);
}

int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    while(1) {
        int w, h, n;
        cin>>w>>h>>n;
        if(w==0 && h==0 && n==0) {
            break;
        }
        int count = 0;
        // cout<<w<<h<<n<<endl;
        vector<vector<int>> points(n);
        for(int i=0;i<n;++i) {
            points[i] = vector<int>(4);
            for(int j=0;j<4;++j) {
                cin>>points[i][j];
            }
        }
        for(int i=0;i<h;++i) {
            for(int j=0;j<w;++j) {
                bool inRange = false;
                for(int k=0;k<n;++k) {
                    int x1, x2, y1, y2;
                    x1 = points[k][0]-1;
                    y1 = points[k][1]-1;
                    x2 = points[k][2]-1;
                    y2 = points[k][3]-1;

                    inRange = isInRange(i, j, x1, y1, x2, y2);
                    if(inRange) break;
                }
                if(!inRange) count++;
            }
        }
        cout<<"There ";
        if(count==0) {
            cout<<"is no empty spots.";
        } else if(count==1) {
            cout<<"is one empty spot.";
        } else {
            cout<<"are "<<count<<" empty spots.";
        }
        cout<<endl;
    }
    

    return 0;
}