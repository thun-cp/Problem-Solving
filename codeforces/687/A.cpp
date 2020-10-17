// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")

#include "bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define endl '\n'
#define F first
#define S second
#define IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define cf ll testcases;cin>>testcases;while(testcases--)
#define prn(x) if(x) cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define minel(x) (*min_element(all(x)))
#define maxel(x) (*max_element(all(x)))
#define cou dbg=1;cout
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<pi> vp;
ll dbg=0;
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p);
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p);
template<typename A> istream& operator>>(istream& cin, vector<A> &v);
int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
vector<vi> arr;
vi vis;
ll loop=1;
void dfs(ll u,ll col=1){
    for(auto v:arr[u]){
        vis[u]=col;
        if(!vis[v]){
            ll ncol=(col==1)?2:1;
            dfs(v,ncol);
        }else if(vis[u]==vis[v]) loop=-1;
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    arr.resize(n+5);
    vis.resize(n+5,0);
    ll co=0;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        if(arr[a].empty()) co++;
        if(arr[b].empty()) co++;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    for(ll i=1;i<=n;i++) if(!vis[i]) dfs(i);
    if(loop==-1) cout<<-1<<endl;
    else{
        ll co1=count(all(vis),1);
        cout<<co1<<endl;
        for(ll i=1;i<=n;i++) if(vis[i]==1) cout<<i<<' ';
        cout<<endl;
        ll co2=count(all(vis),2);
        cout<<co2<<endl;
        for(ll i=1;i<=n;i++) if(vis[i]==2) cout<<i<<' ';
        cout<<endl;
    }
}

int main(){
    IO;
    // cf
    solve();
    return 0;
}


template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { 
    if(dbg){
        return cout << "(" << p.F << ", " << p.S << ")"; 
    }else{
        return cout<<p.F<<' '<<p.S;
    }
        dbg=0;}
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    if(dbg){
        cout << "["; for(ll i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
    }else{
        for(ll i=0;i<v.size()-1;i++) cout<<v[i]<<' ';
        return cout<<v[v.size()-1];
    dbg=0;}
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
   cin >> p.first;
   return cin >> p.second;
}
template<typename A> istream& operator>>(istream& cin, vector<A> &v) {
   for(ll i=0;i<v.size()-1;i++) cin>>v[i];
   return cin >> v[v.size()-1];
}