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
    int case_n = 0;
    while(1) {
        case_n++;
        size_t r, c, n;
        cin>>r>>c>>n;

        if(r==0 && c==0 && n==0) break;

        bitset<10001> bitset_x;
        bitset<10001> bitset_y;


        for(int i=0;i<n;++i) {
            int x, y;
            cin>>x>>y;
            bitset_x[x] = 1;
            bitset_y[y] = 1;
        }
        int x, y;
        cin>>x>>y;

        vector<pair<int, int>> esc_cells;
        esc_cells.push_back({x, y});
        esc_cells.push_back({x-1, y});
        esc_cells.push_back({x, y-1});
        esc_cells.push_back({x+1, y});
        esc_cells.push_back({x, y+1});

        bool esc_possible = false;
        for(auto p : esc_cells) {
            if(x >= 1 && x<=10000 && bitset_x[p.first] == 0 &&
                y >=1 && y<=10000 && bitset_y[p.second] == 0) {
                esc_possible = true;
                break;
            }
        }

        cout<<"Case "<<case_n<<": ";
        if(esc_possible) {
            cout<<"Escaped again! More 2D grid problems!"<<endl;
        } else {
            cout<<"Party time! Let's find a restaurant!"<<endl;
        }
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}