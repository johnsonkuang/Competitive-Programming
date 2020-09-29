#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S)) //must define key operation
using namespace std; 

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {
    private:
        vll ft;
    public:
        FenwickTree(int m) { ft.assign(m+1, 0); }

        void build(const vll &f){
            int m = (int) f.size() - 1;
            ft.assign(m+1, 0);
            for (int i = 1; i <= m; ++i){           //O(m)
                ft[i] += f[i];                      //add this value
                if(i + LSOne(i) <= m)               //i has parent
                    ft[i+LSOne(i)] += ft[i];        //add to that parent
            }
        }

        FenwickTree(const vll &f) { build(f); }     //create FT based on f

        FenwickTree(int m, const vi &s) {           //create FT based on s
            vll f(m+1, 0);
            for(int i = 0; i < (int) s.size(); ++i){
                ++f[s[i]];
            }
            build(f);
        }

        ll rsq(int j) {
            ll sum = 0;
            for(; j; j -= LSOne(j)){
                sum += ft[j];
            }
            return sum;
        }

        ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } //inc/exclusion

        //updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
        void update(int i, ll v){
            for(; i < (int) ft.size(); i += LSOne(i))
                ft[i] += v;
        }

        int select(ll k){
            int lo = 1, hi = ft.size() - 1;
            for(int i = 0; i < 30; ++i){
                int mid = (lo + hi) / 2;
                (rsq(1, mid) < k) ? lo = mid : hi = mid;
            }
            return hi;
        }
};

class RUPQ {
    private: FenwickTree ft;                    //internally use PURQ FT
    public:
        RUPQ(int m) : ft(FenwickTree(m)) {}
        void range_update(int ui, int uj, int v) {
            ft.update(ui, v);
            ft.update(uj+1, -v);
        }
        ll point_query(int i) { return ft.rsq(i); }
};

class RURQ {
    private: 
        RUPQ rupq;
        FenwickTree purq;
    
    public:
        RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {} //init
        void range_update(int ui, int uj, int v){
            rupq.range_update(ui, uj, v);       //[ui, ui+1, ..., uj] +v
            purq.update(ui, v * (ui - 1));          // -(ui-1) * v before ui
            purq.update(uj+1, -v*uj);               // +(uj-ui+1)*v after uj
        }
        ll rsq(int j){
            return rupq.point_query(j)*j - 
                   purq.rsq(j);
        }

        ll rsq(int i, int j){ return rsq(j) - rsq(i-1); } //standard
};