#include<cstdio>
#include<algorithm>
#include<stack>
#include<iostream>
using namespace std;
string s1;
int len=0;
int p,q,r,s,t;
int fun(){
    stack<int> ss;
    for(int i=len-1;i>=0;i--){
        if(s1[i]=='q'){
            ss.push(q);
        }else if(s1[i]=='p'){
            ss.push(p);
        }else if(s1[i]=='r'){
            ss.push(r);
        }else if(s1[i]=='s'){
            ss.push(s);
        }else if(s1[i]=='t'){
            ss.push(t);
        }else if(s1[i]=='K'){
            int t1=ss.top();
            ss.pop();
            int t2=ss.top();
            ss.pop();
            if(t1==1&&t2==1)
                ss.push(1);
            else ss.push(0);
        }else if(s1[i]=='A'){
            int t1=ss.top();
            ss.pop();
            int t2=ss.top();
            ss.pop();
            if(t1==1||t2==1)
                ss.push(1);
            else ss.push(0);
        }else if(s1[i]=='N'){
            int t1=ss.top();
            ss.pop();
            ss.push(!t1);
        }else if(s1[i]=='C'){
            int t1=ss.top();
            ss.pop();
            int t2=ss.top();
            ss.pop();
            if(t1==1&&t2==0)
                ss.push(0);
            else ss.push(1);
        }else if(s1[i]=='E'){
            int t1=ss.top();
            ss.pop();
            int t2=ss.top();
            ss.pop();
            if(t1==t2)
                ss.push(1);
            else ss.push(0);
        }
    }
    return ss.top();
}


bool solve(){
    for(p=0;p<2;p++){
        for(q=0;q<2;q++){
            for(r=0;r<2;r++){
                for(s=0;s<2;s++){
                    for(t=0;t<2;t++){
                        int tmp=fun();
                        if(tmp==0) return false;
                    }
                }
            }
        }
    }
    return true;
}



int main(){
    while(cin>>s1 && s1[0]!='0'){
        len=s1.size();
        bool ans=solve();
        if(ans) printf("tautology\n");
        else printf("not\n");
    }
    return 0;
}

