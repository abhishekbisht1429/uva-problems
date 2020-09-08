#include<bits/stdc++.h>
#define DEBUG

using namespace std;

int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    while(1) {
        int s, b;
        cin>>s>>b;
        if(s == 0 && b == 0) {
            break;
        }
        int *left = new int[s];
        int *right = new int[s];
        for(int i=0;i<s;++i) {
            left[i] = i-1;
            right[i] = i+1;
        }

        while(b--) {
            int l,r;
            cin>>l>>r;
            l--;
            r--;

            int a = left[l];
            int b = right[r];

            if(left[l] >=0) right[left[l]] = right[r];
            if(right[r] <=s-1) left[right[r]] = left[l];

            a++;
            b++;

            if(a == 0) {
                cout<<"*";
            } else {
                cout<<a;
            }
            cout<<" ";

            if(b == s+1) {
                cout<<"*";
            }else{
                cout<<b;
            }
            cout<<endl;
        }
        cout<<"-"<<endl;
        delete[] left;
        delete[] right;
    }

    return 0;
}