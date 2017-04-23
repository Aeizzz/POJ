#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 100;
string s[maxn];
int nxt[maxn];
void getnxt( string a)
{
    int i = 0 ;
    int j = -1;
    int n = a.length();
    nxt[0] = -1;
    while (i<n)
        if (j==-1||a[i]==a[j]) nxt[++i]=++j;
        else j = nxt[j];
}
bool kmp(string a,string b)
{
    int m = a.length();
    int n = b.length();
    getnxt(a);
    int i = 0;
    int j = 0;
    while (i<n)
    {
        if (j==-1||a[j]==b[i]) i++,j++;
        else j=nxt[j];
        if (j==m) return true;
    }
    return false;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        string ans="";
        for(int i=0;i<n;i++) cin>>s[i];
        for(int i=0;i<s[0].size();i++){
            for(int j=1;j+i-1<s[0].size();j++){
                string tmp=s[0].substr(i,j);
                bool match=true;
                for(int k=1;k<n;k++){
                    if(!kmp(tmp,s[k])){
                        match=false;
                        break;
                    }
                }
                 if(match){
                    if(tmp.length()>ans.length()){
                        ans=tmp;
                    }else if(tmp.length()==ans.length() && tmp<ans){
                        ans=tmp;
                    }
                }
            }
        }
        if(ans.length()<3) printf("no significant commonalities\n");
        else cout<<ans<<endl;

    }






    return 0;
}
