#include<bits/stdc++.h>

using namespace std;

#define DEBUG

#define _umap unordered_map
#define _uset unordered_set
#define _uint unsigned int
#define _ll long long
#define _ull unsigned _ll
#define _vec vector
#define _tp tuple
#define _p pair

#define _ignore_lines(n) for(int i=0;i<n;++i) cin.ignore(numeric_limits<streamsize>::max(), '\n')

/* Bit Manipulation */
#define _isSet(n, i) ((n) & (1u<<(i)))
#define _set(n, i) n = (n | (1u<<(i))) 
#define _reset(n, i) n = (n & ((-1u<<1)<<(i)))
#define _flip(n, i) n = (n ^ (1u<<(i)))
#define _rset(n, i, cnt) n = n | (((1u<<(cnt))-1)<<i)
#define _rreset(n, i, cnt) n = n & ~(((1u<<(cnt))-1)<<i)
#define _ffzi(n, i) __builtin_ffs(~(((1u<<i+1)-1) | n))

#define _isSetl(n, i) ((n) & (1ull<<(i)))
#define _setl(n, i) n = ((n) | (1ull<<(i))) 
#define _resetl(n, i) n = ((n) & ((-1ull<<1)<<(i)))
#define _flipl(n, i) n = ((n) ^ (1ull<<(i)))
#define _rsetl(n, i, cnt) n = n | (((1ull<<(cnt))-1)<<i)
#define _rresetl(n, i, cnt) n = n & ~(((1ull<<(cnt))-1)<<i)
#define _ffzil(n, i) __builtin_ffs(~(((1ull<<i+1)-1) | n))

struct vehicle {
    double cap;
    double milage;
    double fuel;
};

struct station {
    double dist;
    double price;

    station(): dist(0), price(0) {}
};

double minCost(_vec<station> &stations, vehicle &vh, int st = 0) {
    int next_st = st+1;
    if(next_st == stations.size()) {
        return 0;
    }

    double dist = stations[next_st].dist - stations[st].dist;
    double req_f = dist/vh.milage;
    double cost = (vh.cap - vh.fuel)*stations[st].price + 2;

    if(vh.fuel < req_f) { //necessary to refill
        vh.fuel = vh.cap - req_f;
        return  cost + minCost(stations, vh, st+1);    
    } else if(vh.fuel <= vh.cap/2) { //optional refill
        double temp = vh.fuel;
        vh.fuel -= req_f;
        double c1 = minCost(stations, vh, st+1); //do not refill
        vh.fuel = temp;

        vh.fuel = vh.cap - req_f; //refill
        double c2 = cost + minCost(stations, vh, st+1);

        return min(c1, c2);
    } else { //do not refill
        vh.fuel -= req_f;
        return minCost(stations, vh, st+1);
    }
}
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
    auto _start = chrono::high_resolution_clock::now();
    #endif

    /* ######################CODE_START################################ */
    int tc = 0;
    while(1) {
        station dest;
        cin>>dest.dist;

        if(dest.dist < 0) break;

        vehicle vh;
        double orig_cost;
        cin>>vh.cap>>vh.milage>>orig_cost;
        vh.fuel = vh.cap; //full tank;

        int n_stations;
        cin>>n_stations;
        _vec<station> stations(n_stations+1);
        stations[0] = station();
        for(int i=1; i<=n_stations; ++i) {
            cin>>stations[i].dist>>stations[i].price;
            stations[i].price /= 100;
        }
        stations.push_back(dest);

        double min_cost = orig_cost + minCost(stations, vh);
        min_cost = round(min_cost * 100)/100;
        
        cout<<"Data Set #"<<(++tc)<<"\n";
        cout<<"minimum cost = $"<<fixed<<setprecision(2)<<min_cost<<"\n";
    }    

    /* #######################CODE_END############################### */
    #ifdef DEBUG
    auto _end = chrono::high_resolution_clock::now();
    auto _duration = chrono::duration_cast<chrono::nanoseconds>(_end - _start);
    _ll _ns = _duration.count();
    double _s = _ns / 1e9;
    cout<<"\nDuration: "<<_s<<" sec\n";
    cin.rdbuf(_in_backup);
    cout.rdbuf(_out_backup);
    #endif
    return 0;
}