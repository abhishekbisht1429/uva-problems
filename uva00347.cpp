#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define umap unordered_map
#define uset unordered_set
#define ll long long
#define vec vector

#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define isSetI(n, i) (0x00000001<<i) & n
#define setI(n, i) n = (0x00000001<<i) | n

bool check(int n) {
    int used = 0x00000000;
    int len = 0, temp = n;
    while(temp>0) {
        len++;
        temp /= 10;
    }
    int i=0;
    for(int count=0; count<len; ++count) {
        int digit = (n/(int)pow(10, len-i-1))%10;
        if(digit == 0 || isSetI(used, digit)) {
            return false;
        }
        setI(used, digit);
        i = (i+(digit%len))%len;
    }
    return (i==0);
}

// int vecToInt(vec<int> p) {
//     int p_val = 1;
//     int num = 0;
//     for(int i=p.size()-1; i>=0; --i) {
//         num += p_val*p[i];
//         p_val *= 10;
//     }
//     return num;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
    ifstream _in("input.txt");
    ofstream _out("output.txt");
    streambuf* _in_backup = cin.rdbuf();
    streambuf* _out_backup = cout.rdbuf();
    cin.rdbuf(_in.rdbuf());
    cout.rdbuf(_out.rdbuf());
    auto _start = chrono::system_clock::now();
    #endif

    /* ######################CODE_START################################ */
    vec<int> ra;
    for(int i=11; i<10000000; ++i) {
        if(check(i)) {
            ra.push_back(i);
        }
    }
    int count = 1;
    while(1) {
        if(count!=1) cout<<"\n";
        int n;
        cin>>n;
        if(n==0) break;

        int l = 0, r = ra.size()-1;
        int mid;
        while(l<r) {
            mid = (l+r)/2;
            if(n <= ra[mid]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        cout<<"Case "<<count<<": ";
        cout<<ra[r];
        count++;
    }
    
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    auto _end = chrono::system_clock::now();
    auto _duration = chrono::duration_cast<chrono::nanoseconds>(_end - _start);
    ll _ns = _duration.count();
    double _s = _ns / 1e9;
    cout<<"Duration: "<<_s<<" sec\n";
    cin.rdbuf(_in_backup);
    cout.rdbuf(_out_backup);
    #endif
    return 0;
}