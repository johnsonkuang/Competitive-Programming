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
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int n;

    while (scanf("%d", &n) == 1 && n) {
        unordered_map<int, string> map;
        int order[n] = {};
        int i;
        
        char card[20];
        char count[20];

        int ptr = 0;

        for(i=1; i <= n; i++){
            scanf("%s %s", &card, &count);        
            map[i] = card;         
            int len = strlen(count) - 1;
            while(order[ptr] != 0 || len){
                if(order[ptr] == 0) len--;
                ptr++;                
                ptr %= n;
            }            
            order[ptr] = i;
        }
        
        int c = 0;
        for(auto j : order) {
            if(c > 0) cout << " ";
            c++;
            cout << map[j];        
        }
        cout << endl;
    }
}