#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
    string s;
    cin>>s;
    ll ans=0;
    reverse(s.begin(),s.end());
    ll found=0;
    for(ll i=0;i<s.length();i++){
        if(i%2==0){
        if(i==s.length()-1&&!found) continue;
        ans++;
        }
        if(s[i]=='1') found=1;
    }
    cout<<ans<<endl;
}

int main(){
    solve();
}
