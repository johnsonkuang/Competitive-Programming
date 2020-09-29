#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char line[1024]; //C style string
    bool odd = true;
    while(gets(line)){ //gets the entire line of input up to \n
        int len = strlen(line);
        
        for(int i = 0; i < len; i++){
            if(line[i] == '"'){
                if(odd){
                    printf("``");
                } else {
                    printf("''");
                }
                odd = !odd;
            } else 
                printf("%c", line[i]); //print character if line[i] isn't quote
        }
        printf("\n"); //reinput the new-line
    }

    return 0;
}
