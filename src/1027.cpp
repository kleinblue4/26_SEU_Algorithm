#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

int n ;
struct Node{
    int s, f, val;

    bool operator<(const Node& other) const{
        return f < other.f ; 
    }
}node[10006] ;


void solve(){
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++)
        cin >> node[i].s >> node[i].f >> node[i].val ;
    sort(node+1, node+1+n) ;

    vector <int> dp(n+3, 0) ;
    for(int i = 1 ; i <= n ; i++){
        dp[i] = dp[i-1] ;
        int l = 1 , r = i-1 , ans = 0;
        while(l <= r){
            int mid = l + (r-l) / 2 ;
            if(node[mid].f <= node[i].s){
                l = mid+1 , ans = mid ;
            }else{
                r = mid-1 ;
            }
        }
        
        dp[i] = max(dp[i] , dp[ans]+node[i].val) ;
    }

    cout << dp[n] << endl ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}