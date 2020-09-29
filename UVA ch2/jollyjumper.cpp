#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int k, v;
    while(scanf("%d", &k) != EOF){        
        vector<int> diff;            
        int prev;
        scanf("%d", &prev);
        k--;

        while(k--){
            scanf("%d", &v);
            diff.push_back(abs(prev - v));
            prev = v;
        }
        
        sort(diff.begin(), diff.end());
        int difference = 1;
        bool isJolly = 1;        
        for(auto i : diff){            
            if(i != difference++){
                isJolly = 0;
            }
        }

        printf(isJolly || diff.size() == 0 ? "Jolly\n":"Not jolly\n");
    }
    return 0;
}