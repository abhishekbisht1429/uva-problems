#include<bits/stdc++.h>
#define DEBUG

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
pair<int,int> find_ring(int s_tap) {
    if(s_tap == 1) return {1, 0};

    int r_no = 1;
    int s = 2;
    int e = (r_no)*8 + s;
    while(1) {


        if(s_tap >= s && s_tap < e) {
            return {s, r_no};
        }
        ++r_no;
        s = (r_no-1)*8 + s;
        e = (r_no)*8 + s;
    }
}
int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    while(1) {
        int sz, p;
        cin>>sz>>p;
        if(sz==0 && p == 0) break;

        int mid = (sz+1)/2;
        pair<int,int> ring = find_ring(p);
        int start = ring.first;
        int r_no = ring.second;

        // cout<<"start "<<start<<", r_no "<<r_no<<endl;
        
        int n = 2*r_no + 1;
        int x, y;
        if(r_no == 0) {
            x = y = mid;
        } else {
            x = mid + r_no;
            y = mid + r_no-1;
            bool found = false;
            // cout<<"start: "<<start<<", x "<<x<<", y "<<y<<endl;
            while(y > mid - r_no) {
                if(start == p) break;
                --y;
                ++start;
            }
            // cout<<"start: "<<start<<", x "<<x<<", y "<<y<<endl;
            while(x>mid - r_no) {
                if(start == p) break;
                --x;
                ++start;
            }
            // cout<<"start: "<<start<<", x "<<x<<", y "<<y<<endl;
            while(y < mid + r_no) {
                if(start == p) break;
                ++y;
                ++start;
            }
            // cout<<"start: "<<start<<", x "<<x<<", y "<<y<<endl;
            while(x < mid + r_no) {
                if(start == p) break;
                ++x;
                ++start;
            }
            // cout<<"start: "<<start<<", x "<<x<<", y "<<y<<endl;
        }


        cout<<"Line = "<<(x)<<", column = "<<(y)<<"."<<endl;//<<endl;
    }
    


    return 0;
}
/*NOTE: - could have used some mathematical solution */