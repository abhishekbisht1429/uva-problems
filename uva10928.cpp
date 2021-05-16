#include<bits/stdc++.h>
#define DEBUG
#define INF numeric_limits<int>::max()

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
    int n;
    cin>>n;

    while(n--) {
        int p;
        cin>>p;

        vector<int> neighbour_count(p+1);

        int min_count = INF;
        ignore_lines(1);
        for(int i=1; i<=p; ++i) {
            string str;
            getline(cin, str);
            istringstream iss(str);

            neighbour_count[i] = 0;
            while(1) {
                int temp;
                iss>>temp;

                if(iss.fail()) break;

                neighbour_count[i]++;
            }
            min_count = min(min_count, neighbour_count[i]);
        }

        bool first = true;
        for(int i=1; i<=p; ++i) {
            if(neighbour_count[i] == min_count) {
                if(first) {
                    first = false;
                } else {
                    cout<<" ";
                }
                cout<<i;
            }
        }
        cout<<endl;
        ignore_lines(1);
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}