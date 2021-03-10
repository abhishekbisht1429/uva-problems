#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
bool isStack(vector<pair<int,int>> &commands) {
    stack<int> s;
    for(auto p : commands) {
        if(p.first == 1) {
            s.push(p.second);
        } else if(!s.empty()) {
            int val = s.top();
            s.pop();
            if(val != p.second) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}
bool isQueue(vector<pair<int, int>> &commands) {
    queue<int> q;
    for(auto p : commands) {
        if(p.first == 1) {
            q.push(p.second);
        } else if(!q.empty()) {
            int val = q.front();
            q.pop();
            if(val != p.second) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}
bool isPQueue(vector<pair<int, int>> &commands) {
    priority_queue<int, vector<int>> pq;
    for(auto p : commands) {
        if(p.first == 1) {
            pq.push(p.second);
        } else if(! pq.empty()) {
            int val = pq.top();
            pq.pop();
            if(val != p.second) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
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
        int n;
        cin>>n;

        if(cin.fail()) break;

        vector<pair<int, int>> commands;
        while(n--) {
            pair<int, int> command;
            cin>>command.first>>command.second;
            commands.push_back(command);
        }

        bool isS = isStack(commands);
        bool isQ = isQueue(commands);
        bool isPQ = isPQueue(commands);

        if(isS && !isQ && !isPQ) {
            cout<<"stack"<<endl;
        } else if(!isS && isQ && !isPQ) {
            cout<<"queue"<<endl;
        } else if(!isS && !isQ && isPQ) {
            cout<<"priority queue"<<endl;
        } else if(!isS && !isQ && !isPQ) {
            cout<<"impossible"<<endl;
        } else {
            cout<<"not sure"<<endl;
        }

    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}