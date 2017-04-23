#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10000+10;
int a[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    printf("%d\n",a[n/2]);
    return 0;
}
