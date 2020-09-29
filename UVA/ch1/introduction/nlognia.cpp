#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int TC, x, y;
    while(scanf("%d", &TC), TC){
        scanf("%d %d", &x, &y);
        int a, b;
        while(TC--){
            scanf("%d %d", &a, &b);
            if(a == x || b == y){
                printf("divisa");
                
            }
            else if(a > x){
                if(b > y){
                    printf("NE");
                } else {
                    printf("SE");
                }
            } else {
                if(b > y){
                    printf("NO");
                } else {
                    printf("SO");
                }
            }

            printf("\n");
        }
    }    
    
    return 0;
}
