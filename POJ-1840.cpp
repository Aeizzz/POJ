#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
map<int,int> mp;
int pow(int x){
    return x*x*x;
}
int main(){
    int a1,a2,a3,a4,a5;
    scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
    mp.clear();
    for(int i=-50;i<=50;i++){
        if(!i) continue;
        for(int j=-50;j<=50;j++){
            if(!j) continue;
            int sum=a1*pow(i)+a2*pow(j);
            mp[sum]++;
        }
    }
    int ans=0;
    for(int i=-50;i<=50;i++){
        if(!i) continue;
        for(int j=-50;j<=50;j++){
            if(!j) continue;
            for(int k=-50;k<=50;k++){
                if(!k) continue;
                int sum=a3*pow(i)+a4*pow(j)+a5*pow(k);
                if(mp.count(-sum)) ans+=mp[-sum];
            }
        }
    }
    printf("%d\n",ans);





    return 0;
}
