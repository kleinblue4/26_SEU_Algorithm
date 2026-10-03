#include <bits/stdc++.h>
using namespace std;

string s1, s2 ;
int n , m ;
vector <vector<int>> dp(503, vector<int>(503, 0)) ;

int dfs(int i, int j){
    if(i == -1 || j == -1)return 0 ;
    if(dp[i][j] != -1)return dp[i][j] ;
    if(s1[i] == s2[j])
        return dp[i][j] = dfs(i-1, j-1)+1 ;
    else
        return dp[i][j] = max(dfs(i-1, j), dfs(i, j-1)) ;
}

void solve(){
    cin >> s1 >> s2 ;
    n = s1.size(), m = s2.size() ;
    for(int i = 0 ; i <= n ; i ++)
        for(int j = 0 ; j <= m ; j ++)
            dp[i][j] = -1 ;
    cout << dfs(n-1, m-1) << endl ;
    
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}