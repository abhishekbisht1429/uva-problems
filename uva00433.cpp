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
#define _reset(n, i) n = (n & (~(1u<<(i))))
#define _flip(n, i) n = (n ^ (1u<<(i)))
#define _rset(n, i, cnt) n = n | (((1u<<(cnt))-1)<<i)
#define _rreset(n, i, cnt) n = n & ~(((1u<<(cnt))-1)<<i)
#define _ffzi(n, i) __builtin_ffs(~(((1u<<i+1)-1) | n))

#define _isSetl(n, i) ((n) & (1ull<<(i)))
#define _setl(n, i) n = ((n) | (1ull<<(i))) 
#define _resetl(n, i) n = (n & (~(1ull<<(i))))
#define _flipl(n, i) n = ((n) ^ (1ull<<(i)))
#define _rsetl(n, i, cnt) n = n | (((1ull<<(cnt))-1)<<i)
#define _rresetl(n, i, cnt) n = n & ~(((1ull<<(cnt))-1)<<i)
#define _ffzil(n, i) __builtin_ffs(~(((1ull<<i+1)-1) | n))

#define AMBG 0
#define VALID 1

_umap<int, int> valid_code_map;
_vec<int> codes(10);
_vec<_vec<int>> possible_codes(9);
_vec<int> valid_num;
int status;

void encode(_vec<string> &inp) {
    for(int k=0; k<inp[0].size()/3; ++k) {
        for(int i=1; i<3; ++i)
            for(int j=3*k; j<3*k + 3; ++j)
                if(inp[i][j] != ' ') 
                    _set(codes[k], 3*(i-1)+(j-3*k));
        if(inp[0][3*k+1] != ' ')
            _set(codes[k], 6);
    }
}

void init_tc() {
    codes.clear();
    codes.resize(9);

    possible_codes.clear();
    possible_codes.resize(9);
    
    valid_num.clear();

    status = 0;
}

void genPossibleCode(_vec<int> &possible_code, int code, int i=0) {
    if(i==7) {
        if(valid_code_map.find(code) != valid_code_map.end()) {
            possible_code.push_back(code);
        }
        return;
    }

    if(!_isSet(code, i)) {
        _set(code, i);
        genPossibleCode(possible_code, code, i+1);
        _reset(code, i);
    }
    genPossibleCode(possible_code, code, i+1);
}

bool is_valid(_vec<int> &num) {
    int sum = 0;
    for(int i=0; i<9; ++i)
        sum += num[8-i]*(i+1);
    return sum%11 == 0;
}

void findValidNum(_vec<int> &num, int i=0) {
    for(int k=0; k<9; ++k) {
        if(_isSet(status, AMBG)) break;

        int temp = num[k];
        for(int possible_code : possible_codes[k]) {
            if(_isSet(status, AMBG)) break;

            num[k] = valid_code_map[possible_code];
            if(is_valid(num)) {
                valid_num = num;
                if(_isSet(status, VALID)) {
                    _set(status, AMBG);
                } else {
                    _set(status, VALID);
                }
            }
        }
        num[k] = temp;
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
    _vec<string> temp = {" _     _  _     _  _  _  _  _ ",
                         "| |  | _| _||_||_ |_   ||_||_|",
                         "|_|  ||_  _|  | _||_|  ||_| _|"};
    encode(temp);
    for(int k=0; k<10; ++k) {
        valid_code_map[codes[k]] = k;
    }

    int tc;
    cin>>tc;
    _vec<string> inp(3);
    _ignore_lines(1);

    while(tc--) {
        for(int i=0; i<3; ++i)
            getline(cin, inp[i]);
        init_tc();
        encode(inp);

        /* Find Garbled index */
        int gi = -1;
        for(int k=0; k<9; ++k) {
            if(valid_code_map.find(codes[k]) == valid_code_map.end()) {
                gi = k;
                break;
            }
        }

        /* 
            Generate possible codes for each position 
            and find valid account number.
        */
        _vec<int> num(9);
        if(gi==-1) {
            for(int k=0; k<9; ++k)
                num[k] = valid_code_map[codes[k]];
            if(is_valid(num)) {
                valid_num = num;
                _set(status, VALID);
            } else {
                for(int k=0; k<9; ++k) 
                    genPossibleCode(possible_codes[k], codes[k]);
                findValidNum(num);
            }
        } else {
            genPossibleCode(possible_codes[gi], codes[gi]);
            for(int k=0; k<9; ++k)
                if(k!=gi)
                    num[k] = valid_code_map[codes[k]];
            findValidNum(num);
        }

        /* Output */
        if(_isSet(status, AMBG)) {
            cout<<"ambiguous\n";
        } else {
            if(_isSet(status, VALID)) {
                for(int k=0; k<9; ++k)
                    cout<<valid_num[k];
                cout<<"\n";
            } else {
                cout<<"failure\n";
            }
        }
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