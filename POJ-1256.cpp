#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
bool cmd(char a,char b){
    if(tolower(a)==tolower(b)){
        return a<b;
    }else{
        return tolower(a)<tolower(b);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        sort(s.begin(),s.end(),cmd);
        do{
            cout<<s<<endl;
        }while(next_permutation(s.begin(),s.end(),cmd));
    }





    return 0;
}
