#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        int len=s1.size();
        int n=s2.size();
        int i,j;
        i=j=0;
        while(i<len && j<n){
            if(s1[i]==s2[j]){
                i++;j++;
            }
            else j++;
        }
        if(i==len){
            printf("Yes\n");
        }else printf("No\n");


    }
    return 0;
}
