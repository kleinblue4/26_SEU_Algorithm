#include <bits/stdc++.h>
using namespace std;

int din[303] ;
vector <int> v[303] ;
void solve(){
    int n , m ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i ++)
        din[i] = 0 , v[i].clear() ;
    
    for(int i = 0 ; i < m ; i ++){
        int a , b ;
        cin >> a >> b ;
        v[a].push_back(b) ;
        din[b] ++ ;
    }
    vector <int> ans ;
    queue <int> q ;
    for(int i = 1 ; i <= n ; i ++){
        if(din[i] == 0)
            q.push(i) , ans.emplace_back(i) ;
    }

    while(!q.empty()) {
        int x = q.front() ; q.pop() ;
        for(auto to: v[x]){
            din[to] -- ;
            if(din[to] == 0){
                q.push(to) , ans.emplace_back(to) ;
            }
        }
    }
    if(ans.size() != n){
        cout << 0 << endl ;
        return ;
    }
    for(auto x : ans)
        cout << x << ' ' ;
    cout << endl ;
}

int main(){
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    int n ; cin >> n ;
    while(n--)
        solve() ;
    return 0 ;
}