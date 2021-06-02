#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define umap unordered_map
#define uset unordered_set
#define ll long long
#define vec vector
#define pi pair<int, int>
#define pll pair<ll, ll>

#define INF numeric_limits<int>::max()
#define MIN_INF numeric_limits<int>::min()

#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define ignore_lines(n) while(n--) cin.ignore(numeric_limits<streamsize>::max(), '\n')


pll find(string str, pll l, pll mid, pll r) {
    if(str.size() == 0) {
        return mid;
    }
    if(str[0] == 'L') {
        pll new_mid;
        new_mid.first = l.first + mid.first;
        new_mid.second = l.second + mid.second;
        return find(str.substr(1), l, new_mid, mid);
    } else {
        pll new_mid;
        new_mid.first = mid.first + r.first;
        new_mid.second = mid.second + r.second;
        return find(str.substr(1), mid, new_mid, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
    ifstream in("input.txt");
    ofstream out("output.txt");
    streambuf* in_backup = cin.rdbuf();
    streambuf* out_backup = cout.rdbuf();
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf()); 
    #endif

    /* ######################CODE_START################################ */
    int n;
    cin>>n;
    while(n--) {
        string str;
        cin>>str;

        pll res = find(str, {0, 1}, {1, 1}, {1, 0});
        cout<<res.first<<"/"<<res.second<<"\n";
    }
    
    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}