#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;


void solve(){
    int n ; cin >> n ;
    vector <int> a(n*2+10, 0) ;
    for(int i = 1 ; i <= 2*n ; i ++)
        cin >> a[i] ;
    
    ll ans = 0 ;
    stack <int> st0, st1 ;
    for(int i = 1 ; i <= 2*n ; i ++){
        if(a[i] == 0)
            st0.push(i) ;
        else
            st1.push(i) ;
        
        if(!st0.empty() && !st1.empty()){
            ans += abs(st0.top() - st1.top()) ;
            st0.pop(), st1.pop() ;
        }
    }
    cout << ans << endl ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}