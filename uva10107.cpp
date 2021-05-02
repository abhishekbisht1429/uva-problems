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
    priority_queue<int, vector<int>, less<int>> left_heap;
    priority_queue<int, vector<int>, greater<int>> right_heap;
    int median = 0; 
    while(1) {
        int n;
        cin>>n;

        if(cin.fail()) break;

        if(n > median) {
            right_heap.push(n);
            if(right_heap.size() - left_heap.size() > 1) {
                int temp = right_heap.top();
                right_heap.pop();
                left_heap.push(temp);
            }
        } else {
            left_heap.push(n);
            if(left_heap.size() - right_heap.size() > 1) {
                int temp = left_heap.top();
                left_heap.pop();
                right_heap.push(temp);
            }
        }
        if(left_heap.size() > right_heap.size()) {
            median = left_heap.top();
        } else if(left_heap.size() < right_heap.size()) {
            median = right_heap.top();
        } else {
            median = (left_heap.top() + right_heap.top()) / 2;
        }

        cout<<median<<endl;
    }
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}