#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
char s[70];
int l;
int get(){
    int i=l-1;
    while(i>0&&s[i-1]>=s[i]) i--;
    if(!i) return 0;
    int mp=i;
    for(int j=i+1;j<l;j++){
        if(s[j]<=s[i-1]) continue;
        if(s[j]<s[mp]) mp=j;
    }
    swap(s[mp],s[i-1]);
    sort(s+i,s+l);
    return 1;
}
int main(){
    while(~scanf("%s",s)&&s[0]!='#'){
        l=strlen(s);
        if(get()) printf("%s\n",s);
        else printf("No Successor\n");
    }
    return 0;
}
