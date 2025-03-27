#include<set>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define N 105
#define R register
#define maxn 1<<15
#define INF 2147483647


set<int> _set[105];

int t,n,mid,w[N],ans;

int f1[maxn],f2[maxn],cnt1[maxn],cnt2[maxn];

inline void solve(){
    cin>>n;
    for(R int i=1;i<=n;++i) cin>>w[i];
    mid=(1+n)>>1;
    for(R int i=0;i<=100;++i) _set[i].clear();
    for(R int i=0;i<(1<<mid);++i){
        cnt1[i]=f1[i]=0;
        for(R int j=1;j<=mid;++j){
            if(i&(1<<(j-1))) f1[i]+=w[j],++cnt1[i];
            else f1[i]-=w[j],--cnt1[i];
        }
        _set[cnt1[i]+n].insert(f1[i]);
    }
    ans=INF;
    for(R int i=0;i<(1<<(n-mid));++i){
        cnt2[i]=f2[i]=0;
        for(R int j=1;j<=n-mid;++j){
            if(i&(1<<(j-1))) f2[i]+=w[j+mid],++cnt2[i];
            else f2[i]-=w[j+mid],--cnt2[i];
        }
        if(((n&1)^1)&&(_set[n-cnt2[i]].size())){
            set<int>::iterator it1=_set[n-cnt2[i]].lower_bound(-f2[i]);
            set<int>::iterator it2=_set[n-cnt2[i]].upper_bound(-f2[i]);
            if(it1!=_set[n-cnt2[i]].end()) ans=min(ans,abs(*it1+f2[i]));
            if(it2!=_set[n-cnt2[i]].end()) ans=min(ans,abs(*it2+f2[i]));
        }
        if((n&1)&&(_set[n-cnt2[i]+1].size())){
            set<int>::iterator it1=_set[n-cnt2[i]+1].lower_bound(-f2[i]);
            set<int>::iterator it2=_set[n-cnt2[i]+1].upper_bound(-f2[i]);
            if(it1!=_set[n-cnt2[i]+1].end()) ans=min(ans,abs(*it1+f2[i]));
            if(it2!=_set[n-cnt2[i]+1].end()) ans=min(ans,abs(*it2+f2[i]));
        }
        if((n&1)&&(_set[n-cnt2[i]-1].size())){
            set<int>::iterator it1=_set[n-cnt2[i]-1].lower_bound(-f2[i]);
            set<int>::iterator it2=_set[n-cnt2[i]-1].upper_bound(-f2[i]);
            if(it1!=_set[n-cnt2[i]-1].end()) ans=min(ans,abs(*it1+f2[i]));
            if(it2!=_set[n-cnt2[i]-1].end()) ans=min(ans,abs(*it2+f2[i]));
        }
    }
    cout<<ans<<endl;
}


int main() {
	freopen ("10.in", "r", stdin);
	freopen ("10.out", "w", stdout);

	cin.tie(0); cout.tie(0);
	    cin>>t;
	    while(t--) solve();
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
