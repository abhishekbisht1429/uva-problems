#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

class Compare {
    public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        if(p1.second != p2.second) {
            return p1.second > p2.second;
        } else {
            return p1.first > p2.first;
        }
    }
};

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
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    unordered_map<int, int> periodMap;
    while(1) {
        string str;
        cin>>str;
        if(str == "#") break;

        int q_num, period;
        cin>>q_num>>period;

        pq.push({q_num, period}); 
        periodMap[q_num] = period;
    }

    int k;
    cin>>k;
    while(k--) {
        pair<int, int> p = pq.top();
        pq.pop();

        cout<<p.first<<endl;

        p.second += periodMap[p.first];
        pq.push(p);
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}