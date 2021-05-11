#include<bits/stdc++.h>
#define DEBUG
#define SIZE 1000005

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
bool checkAndSet(bitset<SIZE> &time_intervals, int start, int end) {
    for(int i = start; i<end; ++i) {
        if(time_intervals[i] == 1) {
            return true;
        } else {
            time_intervals[i] = 1;
        }
    }
    return false;
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
    while(1) {
        int n, m;
        cin>>n>>m;

        if(n==0 && m==0) break;

        bitset<SIZE> time_intervals;

        bool conflict = false;
        for(int i=0; i<n; ++i) {
            int start, end;
            cin>>start>>end;

            if(!conflict) {
                conflict = checkAndSet(time_intervals, start, end);
            }
        }

        for(int i=0; i<m; ++i) {
            int start, end, period;
            cin>>start>>end>>period;

            while(start < 1000000) {
                if(!conflict) {
                    conflict = checkAndSet(time_intervals, start, end);
                }
                start += period;
                end = min(1000000, end + period);
            }
        }

        if(conflict) {
            cout<<"CONFLICT"<<endl;
        } else {
            cout<<"NO CONFLICT"<<endl;
        }
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}