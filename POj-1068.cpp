#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 50;
int a[maxn],vis[maxn];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        int n;
        scanf("%d",&n);
        int index=1;
        int p=0;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            if(x>p){
                int tmp=x-p;
                p=x;
                while(tmp--){
                    a[index++]=0;
                }
            }
            a[index++]=1;
        }
        int num=index;
        for(int i=1;i<num;i++){
            if(a[i]==1){
                int ans=0;
                for(int j=i-1;j>=1;j--){

                    if(a[j]==0 && vis[j]){
                        ans++;
                    }
                    else if(a[j]==0 && !vis[j]){
                        ans++;
                        vis[j]=1;
                        printf("%d ",ans);
                        break;
                    }
                }
            }

        }
        printf("\n");
    }
    return 0;
}
