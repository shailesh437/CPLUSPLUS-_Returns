using namespace std;
 
typedef long long ll;
typedef vector<ll> v64;
typedef vector<vector<ll> > vv64; 
#define MODD 1000000007  

vv64 dp[1000006];
int calc[1000006];

 vv64 multiplyMatrix(vv64 A,vv64 B,int TS){
    vv64 C(3,v64(3,0));
     for(int i=1;i<=TS;i++){
         for(int j=1;j<=TS;j++){
             for(int k=1;k<=TS;k++){
                 C[i][j]+=( (A[i][k]%MODD) * (B[k][j]%MODD))%MODD;
             }
         }
     }
     return C;
 }


vv64 powerMatrix(vv64 TM,ll b){
    if(b==1){
        return TM;
    }
    if(calc[b]==1){
        return dp[b];
    }
    if(b & 1){
            return multiplyMatrix(TM,powerMatrix(TM,b-1),2);
    }
    vv64 ANS = powerMatrix(TM,b/2);
    calc[b/2]=1;
    dp[b/2]= ANS;   
    calc[b]=1;
    return dp[b]=multiplyMatrix(ANS,ANS,2);
}


ll compute(ll n){
    if(n<=1){
        return n;
    }
    vv64 TM(3,vector<ll>(3,0));
    TM[1][1]=0;
    TM[1][2]=1;
    TM[2][1]=1;
    TM[2][2]=1;
     vv64  ResultM = powerMatrix(TM,n-1);
    return ResultM[2][2]%MODD;
}



int main()
{
 int TC;
 cin>>TC;
 ll N;
 memset(calc,0,sizeof(calc));
 while(TC--){
     cin>>N;
     ll x = compute(N);
     cout<<x<<endl; 
 }
 return 0;
}
