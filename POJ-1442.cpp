#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,less<int> > left;
priority_queue<int,vector<int>,greater<int> > right;
const int M = 30000+10;
int a[M],c[M];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int get,k=1;
    for(int i=0;i<m;i++){
        scanf("%d",&get);
        while(k<=get){
            right.push(a[k]);
            while(!left.empty() && left.top()>right.top()){
                int t;
                t=left.top();
                left.pop();
                right.push(t);
                t=right.top();
                right.pop();
                left.push(t);
            }
            k++;
        }
        printf("%d\n",right.top());
        int t=right.top();
        right.pop();
        left.push(t);
    }
    return 0;
}
