#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int TC;
    scanf("%d", &TC);

    int c = 1;
    while(TC--){
        vector<int> workers;
        for(int i = 0; i < 3; i++) {
            int pay;
            scanf("%d", &pay);
            workers.push_back(pay);
        }
        sort(workers.begin(), workers.end());
        printf("Case %d: %d\n", c++, workers[1]);
    }    
    return 0;
}
