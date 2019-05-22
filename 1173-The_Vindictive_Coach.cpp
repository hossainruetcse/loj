#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll g(int a, int b);

ll dp1[55][55];
ll dp2[55][55];

ll f(int a, int b){
    // cout<<"f "<<a<<" "<<b<<endl;
    if(a==1 and b==0)
        return 1;
    if(a == 0 ) 
        return 0;
    ll &ret = dp1[a][b];
    // cout<<"f "<<a<<" "<<b<<" "<<ret<<endl;  
    if(ret != -1 )
        return ret ;
    // cout<<"f1 "<<a<<" "<<b<<" "<<ret<<endl; 
    ret =0;
    for(int i=1;i<=a;i++){
        ret+=g(a-i,b+i-1);
    }
    return ret;
}

ll g(int a, int b){
    // cout<<"g "<<a<<" "<<b<<endl;
     if(a==0 and b==1)
        return 1;
    if(b == 0 ) 
        return 0;
    ll &ret = dp2[a][b];
      // cout<<"g "<<a<<" "<<b<<" "<<ret<<endl;  
    if(ret != -1 )
        return ret ;
    // cout<<"g1 "<<a<<" "<<b<<" "<<ret<<endl; 
    ret =0;

    for(int i=1;i<=b;i++){
        ret+=f(a+i-1,b-i);
    }

    return ret;

}

void init(){
    for(int i=0;i<=50;i++){
        for(int j=0;j<=50;j++){
            dp1[i][j]=-1;
            dp2[i][j]=-1;
        }
    }
}

int main(){
    int n,m,T,cased=0;
    freopen("a.txt","r",stdin);
    scanf("%d",&T);

    init();
    while(T--){
        scanf("%d",&n);
        scanf("%d",&m);
        ll ans;
        if( m==1){
            if(n<=2)
                ans =1;
            else
                ans = g(n-3,1);
        }
        else 
            ans = g(n-m, m-1);
        printf("Case %d: %llu\n",++cased,ans);
        
       }
    }