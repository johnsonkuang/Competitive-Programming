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

    vector<char> num;

    int div = 0;
    string line;
    getline(cin, line);
    istringstream iss(line);
    char c;    
    while(iss >> c) {
        num.push_back(c);
    } //assumption: num.size() will be able to hold the 

    getline(cin, line);
    istringstream iss2(line);
    char i;
    while(iss2 >> i){            
        if(i == '0') {
            div++;            
        }
    }    //obtained number of decimal points we need to move 
    
    //negate all 0's at the back
    while(num.back() == '0' && div > 0){
        num.pop_back();
        div--;
    }

    //case 1
    if(num.size() > div){
        ll idx = 0;
        while(num.size() - idx > div){
            cout << num[idx];
            idx++;
        }
        //num len = div
        if(div != 0){
            cout << ".";
            for(;idx < num.size(); idx++){
                cout << num[idx];
            }
        }           
    } else {
        cout << 0 << ".";        
        if(num.size() < div){
            while(div > num.size()){
                cout << 0;
                div--;
            }            
        }        

        for(auto n : num){
            cout << n;
        }
        //num len = div
    }    
    return 0;
}