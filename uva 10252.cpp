#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
int a[30],b[30];
int main(){
    char s1[1010],s2[1010];
    while(gets(s1)!=NULL && gets(s2)!=NULL){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<strlen(s1);i++){
            a[s1[i]-'a']++;
        }
        for(int i=0;i<strlen(s2);i++){
            b[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(a[i]!=0 && b[i]!=0){
                int k=min(a[i],b[i]);
                for(int j=0;j<k;j++){
                    printf("%c",'a'+i);
                }
            }
        }
    printf("\n");
    }
    return 0;
}
