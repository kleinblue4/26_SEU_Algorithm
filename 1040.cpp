#include <bits/stdc++.h>
using namespace std;


void solve(){
    int m , n , st ;
    cin >> m >> n >> st ;
    int a[m+3][n+3] = {0} ;
    for(int i = 1 ; i <= m ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            cin >> a[i][j] ;
    
    for(int i = 1 ; i <= m ; i ++){
        int l = 1 , r = n , ans = n ;
        while(l <= r){
            int mid = (l+r) >> 1 ;
            if(a[i][mid] <= st)
                l = mid+1 , ans = mid ;
            else
                r = mid-1 ;
        }
        if(a[i][ans] == st){
            cout << "true\n" ;
            return ;
        }
    }
    cout << "false\n" ;
    // if(a[row][col] == st)cout << "true\n" ;
    // else cout << "false\n" ;
}

int main(){
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    int n ; cin >> n ;
    while(n--)
        solve() ;
    return 0 ;
}


