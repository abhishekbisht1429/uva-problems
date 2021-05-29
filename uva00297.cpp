#include<bits/stdc++.h>
#define DEBUG
#define umap unordered_map
#define uset unordered_set
#define ll long long
#define vec vector

using namespace std;

void ignore_lines(int n) {
    while(n--)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void decode(string str, int *k, vec<bitset<32>> &image, int x, int y, int size) {
    ++(*k);
    // cout<<k<<" "<<str[k]<<endl;
    if(str[*k] == 'p') {
        decode(str, k, image, x, y + size/2, size/2);
        decode(str, k, image, x, y, size/2);
        decode(str, k, image, x + size/2, y, size/2);
        decode(str, k, image, x + size/2, y + size/2, size/2);
    } else {
        // cout<<"x "<<x<<" y "<<y<<" ";
        // cout<<size<<endl;
        // cout<<"else "<<k<<" "<<str[k]<<endl;
        for(int i=x; i< x + size; ++i) {
            for(int j=y; j< y + size; ++j) {
                // cout<<"i "<<i<<" : j "<<j<<endl;
                image[i][j] = (str[*k] == 'f');
            }
        }
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
        string t1, t2;
        cin>>t1>>t2;

        vector<bitset<32>> im1(32), im2(32);
        for(int i=0; i<32; ++i) {
            im1[i] = bitset<32>();
            im2[i] = bitset<32>();
        }
        int k1 = -1, k2 = -1;
        decode(t1, &k1, im1, 0, 0, 32);
        decode(t2, &k2, im2, 0, 0, 32);
        int count = 0;
        for(int i=0; i<32; ++i) {
            for(int j=0; j<32; ++j) {
                count += im1[i][j] | im2[i][j];
            }
        }
        cout<<"There are "<<count<<" black pixels.\n";
    }

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    cin.rdbuf(in_backup);
    cout.rdbuf(out_backup);
    #endif
    return 0;
}