#include<cstdio>
#include<algorithm>
#include<map>
#include<iostream>
#include<string>
using namespace std;
map<string,int> mp;
const int maxn = 40;
double m[maxn][maxn];
const double inf = 9999999.0;
int main(){
    int n;
    int Case=1;
    while(~scanf("%d",&n) && n){
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            mp[s]=i+1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) m[i][j]=1;
                else m[i][j]=-inf;
            }
        }
        int t;scanf("%d",&t);
        for(int i=0;i<t;i++){
            string s1,s2;
            double p;
            cin>>s1>>p>>s2;
            m[mp[s1]][mp[s2]]=p;
        }

        for(int k=1;k<=n;k++){
            for(int j=1;j<=n;j++){
                for(int i=1;i<=n;i++){
                    //m[i][j]==max(m[i][j],m[i][k]*m[k][j]);
                    if(m[i][j]<m[i][k]*m[k][j]){
                        m[i][j]=m[i][k]*m[k][j];
                    }
                }
            }
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if(m[i][i]>1.0) flag=1;
        }
        if(flag) printf("Case %d: Yes\n",Case++);
        else printf("Case %d: No\n",Case++);
    }





    return 0;
}
