#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>
using namespace std;
map<string,string> mp;
string s1,s2;
int main(){
    while(1){
        cin>>s1>>s2;
        mp[s2]=s1;
        getchar();
        char c=getchar();
        if(c=='\n') break;
        ungetc(c,stdin);
    }
    while(cin>>s1){
        if(mp[s1]=="") cout<<"eh"<<endl;
        else cout<<mp[s1]<<endl;
    }
    return 0;
}
