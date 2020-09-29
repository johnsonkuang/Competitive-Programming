#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int TC, a, b;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &a, &b);
        a -= 2;
        b -= 2;
        
        int width = (a % 3 == 0) ? a / 3 : a / 3 + 1;
        int length = (b % 3 == 0) ? b / 3 : b / 3 + 1;
        printf("%d\n", width * length);
    }
    return 0;
}
