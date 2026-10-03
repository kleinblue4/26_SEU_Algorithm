#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ; cin >> n ;
    vector <int> a(n+1), dp(n+1) ;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i] ;
    
    int cnt = 0 ;
    for(int i = 1 ; i <= n ; i ++){
        int l = 1 , r = cnt + 1, k = 1 ;
        while(l < r){
            int mid = (l+r) >> 1 ;
            if(dp[mid] <= a[i])
                l = mid+1 , k = mid+1;
            else
                r = mid ;
        }
        if(k > cnt)
            dp[++cnt] = a[i] ;
        else
            dp[k] = a[i] ;
    }
    cout << cnt << endl ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0) ;
    int t ; cin >> t ;
    while(t--)solve() ;
    return 0 ;
}