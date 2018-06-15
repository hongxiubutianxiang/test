#include<cstdio>
#include<cstring>
using namespace std;
int n,k,t,ans;
int a[12][12],c[12][12],d[12][12];
int mi(int x){
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++) c[i][i]=1;
    while(x>0){
        if((x/2)*2!=x){
            memset(d,0,sizeof(d));
            for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            for(int h=1;h<=n;h++) d[i][j]+=((a[i][h]*c[h][j])%9973);
            for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) c[i][j]=d[i][j]%9973;
        }
        x/=2;
        memset(d,0,sizeof(d));
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        for(int h=1;h<=n;h++) d[i][j]+=((a[i][h]*a[h][j])%9973);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) a[i][j]=d[i][j]%9973;
    }
    int sum=0;
    for(int i=1;i<=n;i++) sum+=c[i][i];
    sum%=9973;
    return sum;
}
int main() {
    scanf("%d",&t);
    for(int q=1;q<=t;q++){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
        ans=mi(k);
        printf("%d\n",ans);
    }
    return 0;
}