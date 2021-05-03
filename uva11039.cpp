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
    int p;
    cin>>p;
    while(p--) {
        int n;
        cin>>n;
        priority_queue<int, vector<int>> pq_blue, pq_red;

        while(n--) {
            int floor;
            cin>>floor;

            if(floor < 0) {
                pq_red.push(abs(floor));
            } else {
                pq_blue.push(floor);
            }
        }

        //process

        int count = 0;
        int top = INF;
        string turn;

        if(pq_blue.top() > pq_red.top()) {
            turn = "blue";
        } else {
            turn = "red";
        }

        while(!pq_blue.empty() && !pq_red.empty()) {
            if(turn == "blue") {
                while(!pq_blue.empty() && pq_blue.top() > top) {
                    pq_blue.pop();
                }
                if(!pq_blue.empty()) {
                    top = pq_blue.top();
                    turn = "red";
                    count++;
                }
            } else {
                while(!pq_red.empty() && pq_red.top() > top) {
                    pq_red.pop();
                }
                if(!pq_red.empty()) {
                    top = pq_red.top();
                    turn = "blue";
                    count++;
                }
            }
        }

        cout<<count<<endl;
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}