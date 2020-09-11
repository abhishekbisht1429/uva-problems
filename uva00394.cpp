#include<bits/stdc++.h>
#define DEBUG

using namespace std;

struct Arr {
    int b;
    int d;
    int *l;
    int *u;
    int *c;

    Arr(int b, int d, int c_d) {
        this->b = b;
        this->d = d;
        l = new int[d+1];
        u = new int[d+1];
        c = new int[d+1];
        c[d] = c_d;
    }
};

int main() {
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    #endif

    int n,r;
    cin>>n>>r;
    map<string, Arr*> arr_map;
    for(int i = 0;i<n;++i) {
        string name;
        int b, d, c_d;
        cin>>name>>b>>c_d>>d;
        Arr *a = new Arr(b, d, c_d);
        for(int i=1;i<=d; ++i) {
            cin>>a->l[i]>>a->u[i];
        }

        arr_map[name] = a;
        // cout<<name<<" "<<arr_map[name]->b<<" "<<arr_map[name]->d<<" "<<endl;
    }
    // cout<<"hello "<<arr_map["ONE"]->d<<endl;
    for(int x=0;x<r;++x) {
        string name;
        cin>>name;
        Arr *arr = arr_map[name];
        // cout<<name<<arr->d<<endl;
        int dims[arr->d+1];
        // cout<<"dims ";
        for(int i=1;i<=arr->d;++i) {
            cin>>dims[i];
            // cout<<dims[i]<<" ";
        }
        // cout<<endl;
        // cout<<"step 0"<<endl;
        for(int i = arr->d-1; i>=1; --i) {
            arr->c[i] = arr->c[i+1] *(arr->u[i+1] - arr->l[i+1] + 1);
        }
        // cout<<"step 1"<<endl;
        arr->c[0] = arr->b;
        for(int i = 1; i<=arr->d; ++i) {
            arr->c[0] -= arr->c[i] * arr->l[i];
        }
        // cout<<"step 2"<<endl;
        int address = arr->c[0];
        for(int i = 1; i<=arr->d;++i) {
            address += arr->c[i] * dims[i];
        }
        cout<<name<<"[";
        for(int i=1;i<=arr->d-1;++i) {
            cout<<dims[i]<<", ";
        }
        cout<<dims[arr->d]<<"] = "<<address<<endl;
    }
    return 0;
}