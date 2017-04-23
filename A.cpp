#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
long long a[15];
long long init(){
    a[1]=1;
    for(int i=2;i<=10;i++){
        a[i]=a[i-1]*i;
    }
}
ll gcd(ll a,ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    int t;
    string s;
    scanf("%d",&t);
    init();
    while(t--){
        cin>>s;
        long long sum=0;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            long long Count = 0;
            for(int j=i+1;j<s.size();j++){
                if(s[j]<s[i]) Count++;
            }
            sum=sum+Count*a[s.size()-1-i];
        }
        ll p=a[s.size()]-sum-1;
        if(p==0){
            printf("0.000000000\n");
            continue;
        }
        double pp=1.0,s;
        pp/=a[n];
        s=pp;
        for(int i=0;i<p-1;i++){
            s=s*pp+s;
        }
        printf("%.9lf\n",s);



    }
    return 0;
}
