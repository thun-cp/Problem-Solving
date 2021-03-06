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

void solve(){
    ll n,m;
    cin>>n>>m;
    vd a(n),b(n);
    cin>>a;
    cin>>b;
    for(auto i:a){
        //sum+=i;
        if(i==1){
            cout<<-1<<endl;
            return;
        }
    }
    for(auto i:b){
        //sum+=i;
        if(i==1){
            cout<<-1<<endl;
            return;
        }
    }
    ld l=0.0,r=ld(1e9+5);
    ll ite=200;
    ld ans;
    while(ite--){
        ld mid=(l+r)/2.0;
        auto temp=mid;
        ld nsum=ld(m)+mid;
        for(ll i=0;i<n;i++){
            if(i==n-1){
                mid-=nsum/a[i];
                nsum=m+mid;
                mid-=nsum/b[0];
                nsum=m+mid;
                continue;
            }
            mid-=nsum/a[i];
            nsum=mid+m;
            mid-=nsum/b[i+1];
            nsum=mid+m;
        }
        //cout<<fixed<<temp<<' '<<mid<<endl;
        if(mid>0) r=temp;
        else if(mid<0) l=temp;
        else break;
    }    
    cout.precision(15);
    cout<<fixed<<(l+r)/2.0<<endl;
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