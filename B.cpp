#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn = 100+10;
bool A[maxn];
bool C[maxn][4];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(C,true, sizeof(C));
        memset(A,false,sizeof(A));
        int q,m;
        char a,b;
        scanf("%d%d",&q,&m);
        for(int x=0; x<m; x++){
            for(int i=0; i<q; i++){
                cin >> a >> b;
                if(A[i] == true)
                    continue;

                if(b == 'F'){
                    C[i][a-'A'] = false;
                }
                else{
                    A[i] = true;
                    memset(C[i], false, sizeof(C[i]));
                    C[i][a-'A'] = true;

                }

            }
        }
        for(int i=0; i<q; i++){
            int flag = 0;
            for(int j=0; j<4; j++){
                if(C[i][j] == true){
                    flag++;
                }
            }
            if(flag==1){
                for(int j=0; j<4; j++){
                    if(C[i][j] == true){
                        printf("%c%c",j+'A',i==q-1?'\n':' ');
                        break;
                    }
                }
            }else printf("?%c",i==q-1?'\n':' ');
        }
    }



    return 0;
}
