#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<long long> pq;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        long long x;
        scanf("%lld",&x);
        pq.push(-x);
    }
    int sum=0;
    while(pq.size()>=2){
        long long a=pq.top();pq.pop();
        long long b=pq.top();pq.pop();
        long long Sum=-(a+b);
        //printf("%d\n",sum);
        sum+=Sum;
        pq.push(-Sum);
    }
    printf("%lld\n",sum);
    return 0;
}
