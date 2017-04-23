#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 2200;
int a[maxn];
int b[maxn];
 priority_queue<int> q;

void fun(int a[],int b[]){

}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        while(!q.empty()) q.pop();
        int n,m;
        scanf("%d%d",&n,&m);
        for(int j=0;j<m;j++){
                scanf("%d",&a[j]);
        }
        sort(a,a+m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&b[j]);
                q.push(a[0]+b[j]);
            }
            sort(b,b+m);
            for(int j=1;j<m;j++){
                for(int k=0;k<m;k++){
                    if(a[j]+b[k]<q.top()){
                        q.pop();
                        q.push(a[j]+b[k]);
                    }
                }
            }
            for(int j=m-1;j>=0;j--){
                a[j]=q.top();
                q.pop();
            }
        }
        for(int i=0;i<m;i++){
            printf("%d%c",a[i],i==m-1?'\n':' ');
        }
    }

    return 0;
}
