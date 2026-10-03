#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9+10 ;
vector <pair<int,int>> v[503] ;
int b[503];

struct Node{
    int dis, u, cost ;
    bool operator>(const Node& other) const {
        return dis > other.dis ;
    }
};

void solve(){
    int n, e, s, t, m ;
    cin >> n >> e >> s >> t >> m ;
    vector <vector<int>> dis(n+3, vector<int>(m+3, MAX)) ;
    for(int i = 1 ; i <= n ; i ++){
        v[i].clear() ;
        b[i] = 0;
    }
    
    for(int i = 1 ; i <= n ; i ++)
        cin >> b[i] ;
    for(int i = 0 ; i < e ; i ++){
        int a , b , w ;
        cin >> a >> b >> w ;
        v[a].push_back({b, w}) ;
        v[b].push_back({a, w}) ;
    }

    priority_queue <Node, vector<Node>, greater<Node>> q ;
    dis[s][0] = 0 ;
    q.push({0,s,0}) ;
    int ans = -1 ;
    while(!q.empty()){
        Node node = q.top() ;
        q.pop() ;
        int d = node.dis, to = node.u, c = node.cost ;
        

        if(to == t){
            ans = d ; break ;
        }
        for(auto [x, val] : v[to]){
            int c0 = c + ((x == s) ? 0 : b[x]) ;
            if(c0 <= m){
                if(dis[x][c0] > d + val){
                    dis[x][c0] = d + val ;
                    q.push({dis[x][c0], x, c0}) ;
                }
            }
        }
    }
    cout << ans << endl ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}