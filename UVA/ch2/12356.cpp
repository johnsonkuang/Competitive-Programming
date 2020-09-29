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
    int s, b;

    while (scanf("%d %d", &s, &b), (s||b)) {
        int l, r;
        int soldiers[s+1]; //1 - index
        clr(soldiers); //set all to 0 - alive
                       //1 - dead
        while(b--){
            scanf("%d %d", &l, &r);
            int i;
            for(i = l; i <= r; i++){
                soldiers[i] |= 1;
            }
            int idx = l;
            while(soldiers[idx]){
                idx--;
            }

            if(idx == 0){
                printf("* ");
            } else {
                printf("%d ", idx);
            }

            idx = r;
            while(soldiers[idx] && idx <= s){
                idx++;
            }
            
            if(idx == s + 1){
                printf("*\n");
            } else {
                printf("%d\n", idx);
            }
        }
        printf("-\n");
    }

    return 0;
}