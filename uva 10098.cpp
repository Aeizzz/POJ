#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char s[15];
        scanf("%s",s);
        int l=strlen(s);
        sort(s,s+l);
        do{
           printf("%s\n",s);

        }while(next_permutation(s,s+l));
        printf("\n");
    }





    return 0;
}
