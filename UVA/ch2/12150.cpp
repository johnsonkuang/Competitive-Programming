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


int main()
{
    int n;
    while(scanf("%d", &n) == 1 && n){
        int rank[10005] = {}, err = 0;
        int x, v, i;
        for(i = 0; i < n; i++){
            scanf("%d %d", &x, &v);
            if(i + v < 0) err = 1;
            if(i + v >= n) err = 1;
            if(rank[i+v]) err = 1;
            if(err) continue;
            rank[i+v] = x;
        }
        if(err) {
            puts("-1");
            continue;
        }
        printf("%d", rank[0]);
        for(i = 1; i < n; i++){
            printf(" %d", rank[i]);
        }
        puts("");
    }
    

    return 0;
}