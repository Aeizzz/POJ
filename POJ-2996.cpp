//
// Created by hong-ll on 2017/4/17.
//
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const double pi= acos(-1.0);
const double esp=1e-6;
char str[40][40];
int main()
{
    for(int i=0; i<17; i++)
        scanf("%s",&str[i]);
    printf("White: ");
    for(int i=15; i>=1; i-=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='K')
                printf("K%c%d",'a'+j/4,8-i/2);
    for(int i=15; i>=1; i-=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='Q')
                printf(",Q%c%d",'a'+j/4,8-i/2);
    for(int i=15; i>=1; i-=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='R')
                printf(",R%c%d",'a'+j/4,8-i/2);
    for(int i=15; i>=1; i-=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='B')
                printf(",B%c%d",'a'+j/4,8-i/2);
    for(int i=15; i>=1; i-=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='N')
                printf(",N%c%d",'a'+j/4,8-i/2);
    for(int i=15; i>=1; i-=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='P')
                printf(",%c%d",'a'+j/4,8-i/2);
    puts("");

    printf("Black: ");
    for(int i=1; i<=15; i+=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='k')
                printf("K%c%d",'a'+j/4,8-i/2);
    for(int i=1; i<=15; i+=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='q')
                printf(",Q%c%d",'a'+j/4,8-i/2);
    for(int i=1; i<=15; i+=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='r')
                printf(",R%c%d",'a'+j/4,8-i/2);
    for(int i=1; i<=15; i+=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='b')
                printf(",B%c%d",'a'+j/4,8-i/2);
    for(int i=1; i<=15; i+=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='n')
                printf(",N%c%d",'a'+j/4,8-i/2);
    for(int i=1; i<=15; i+=2)
        for(int j=2; j<=30; j+=4)
            if(str[i][j]=='p')
                printf(",%c%d",'a'+j/4,8-i/2);
    puts("");
    return 0;

}
