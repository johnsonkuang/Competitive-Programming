#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;

class SegmentTree {
    private:
        int n;              // n = (int) A.size()
        vi A, st, lazy;     // the arrays

        int l(int p) { return p << 1; }
        int r(int p) { return (p<<1) + 1; } //go to left and right children

        int conquer(int a, int b){
            if(a == -1) return b;
            if(b == -1) return a;               //corner cases
            return min(a,b);                    //RMQ
        }

        void build(int p, int L, int R) {       //O(n)
            if(L == R)
                st[p] = A[L];
            else {
                int m = (L+R)/2;
                build(l(p), L, m);
                build(r(p), m+1, R);
                st[p] = conquer(st[l(p)], st[r(p)]);
            }
        }

        void propagate(int p, int L, int R) {
            if(lazy[p] != -1) {
                st[p] = lazy[p];
                if(L != R)
                    lazy[l(p)] = lazy[r(p)] = lazy[p];
                else
                    A[L] = lazy[p];
                lazy[p] = -1;
            }
        }

        int RMQ(int p, int L, int R, int i, int j) {
            propagate(p, L, R);
            if(i > j) return -1;
            if((L >= i) && (R <= j)) return st[p];
            int m = (L+R)/2;
            return conquer(RMQ(l(p), L, m, i, min(m, j)),
                            RMQ(r(p), m+1, R, max(i, m+1), j));
        }

        void update(int p, int L, int R, int i, int j, int val) {
            propagate(p, L, R);
            if(i > j) return;
            if((L >= i) && (R <= j)) {
                lazy[p] = val;
                propagate(p, L, R);
            }
            else {
                int m = (L+R)/2;
                update(l(p), L, m, i, min(m,j), val);
                update(r(p), m+1, R, max(i, m+1), j, val);
                int lsub = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
                int rsub = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
                st[p] = (lsub <= rsub) ? st[l(p)] : st[r(p)];
            }
        }

    public:
        SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}

        SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
            A = initialA;
            build(1, 0, n-1);
        }

        void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }
        int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};

int main() {
  vi A = {18, 17, 13, 19, 15, 11, 20, 99};       // make n a power of 2
  SegmentTree st(A);

  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("              A is {18,17,13,19,15,11,20,oo}\n");
  printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3));      // 13
  printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7));      // 11
  printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4));      // 15

  st.update(5, 5, 77);                           // update A[5] to 77
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {18,17,13,19,15,77,20,oo}\n");
  printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3));      // remains 13
  printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7));      // now 15
  printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4));      // remains 15

  st.update(0, 3, 30);                           // update A[0..3] to 30
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {30,30,30,30,15,77,20,oo}\n");
  printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3));      // now 30
  printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7));      // remains 15
  printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4));      // remains 15

  st.update(3, 3, 7);                            // update A[3] to 7
  printf("              idx    0, 1, 2, 3, 4, 5, 6, 7\n");
  printf("Now, modify A into {30,30,30, 7,15,77,20,oo}\n");
  printf("RMQ(1, 3) = %d\n", st.RMQ(1, 3));      // now 7
  printf("RMQ(4, 7) = %d\n", st.RMQ(4, 7));      // remains 15
  printf("RMQ(3, 4) = %d\n", st.RMQ(3, 4));      // now 7

  return 0;
}