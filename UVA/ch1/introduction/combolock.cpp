#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int pos, a, b, c;
    while(scanf("%d %d %d %d", &pos, &a, &b, &c), (pos || a || b || c)){
        int degrees = 1080;
        if(pos >= a){
            degrees += (pos - a) * 9;
        } else {
            degrees += (40 - a + pos) * 9;
        }

        if(b >= a){
            degrees += (b - a) * 9;
        } else {
            degrees += (40 - a + b) * 9;
        }

        if(b >= c){
            degrees += (b - c) * 9;
        } else {
            degrees += (40 - c + b) * 9;
        }
        printf("%d\n", degrees);
    }

    return 0;
}
