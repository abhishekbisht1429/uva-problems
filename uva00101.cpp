#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int **matrix;
int *top;
unordered_map<int, pair<int, int>> pos_map;

void init(int n) {
    matrix = new int*[n];
    for(int i=0;i<n;++i) {
        matrix[i] = new int[n];
        matrix[i][0] = i;
    }

    top = new int[n];

    for(int i=0;i<n;++i) {
        pos_map[i] = {i, 0};
    }
}

void move_to_initialpos(int pos, int j) {
    // cout<<pos<<" "<<j<<endl;
    while(top[pos] > j) {
        int b_no = matrix[pos][top[pos]];
        top[b_no]++;
        matrix[b_no][top[b_no]] = b_no;
        top[pos]--;

        //update position
        pos_map[b_no].first = b_no;
        pos_map[b_no].second = top[b_no];
    }
    // cout<<"move_to_initial"<<endl;
}

void stack_up(int a, int b) {
    int pos_a = pos_map[a].first;
    int pos_b = pos_map[b].first;

    // cout<<pos_a<<" "<<pos_b<<endl;
    int count = 0;
    for(int i=pos_map[a].second; i<=top[pos_a]; ++i) {
        int b_no = matrix[pos_a][i];
        matrix[pos_b][++top[pos_b]] = b_no;

        //update position map
        pos_map[b_no].first = pos_b;
        pos_map[b_no].second = top[pos_b];

        count++;
    }
    top[pos_a] -= count;
}

void execute_command(vector<string> command) {
    int a = stoi(command[1]);
    int b = stoi(command[3]);
    if(pos_map[a].first != pos_map[b].first) {
        if(command[0] == "move") {
            if(command[2] == "onto") {
                // cout<<"move onto "<<a<<" "<<b<<endl;
                move_to_initialpos(pos_map[a].first, pos_map[a].second);
                move_to_initialpos(pos_map[b].first, pos_map[b].second);
                stack_up(a,b);
            } else {
                // cout<<"move over "<<a<<" "<<b<<endl;
                move_to_initialpos(pos_map[a].first, pos_map[a].second);
                stack_up(a,b);
            }
        } else {
            if(command[2] == "onto") {
                // cout<<"pile onto "<<a<<" "<<b<<endl;
                move_to_initialpos(pos_map[b].first, pos_map[b].second);
                stack_up(a, b);
            } else {
                // cout<<"pile over "<<a<<" "<<b<<endl;
                stack_up(a,b);
            }
        }
    }
    // else {
    //     cout<<"skip"<<endl;
    // }
}

void print_output(int n) {
    for(int i=0;i<n;++i) {
        cout<<i<<":";
        for(int j=0;j<=top[i];++j) {
            cout<<" "<<matrix[i][j];
        }
        cout<<endl;
    }
}
int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    int n;
    cin>>n;
    init(n);
    while(1) {
        vector<string> command(4);
        cin>>command[0];
        if(command[0] == "quit") break;

        cin>>command[1];
        cin>>command[2];
        cin>>command[3];

        execute_command(command);
    }
    print_output(n);
    
    

    return 0;
}