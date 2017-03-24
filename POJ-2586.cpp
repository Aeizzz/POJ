#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int s,d;
    while(scanf("%d%d",&s,&d)!=EOF){
        int val=0;
        if(s*4-d<0){
            val=s*10-d*2;
        }else if(s*3-d*2<0){
            val=s*8-4*d;
        }else if(s*2-3*d<0){
            val=s*6-d*6;
        }else if(s-d*4<0){
            val=s*3-d*9;
        }else{
            val=-d*12;
        }
        if(val<=0) printf("Deficit\n");
        else printf("%d\n",val);
    }
    return 0;
}
