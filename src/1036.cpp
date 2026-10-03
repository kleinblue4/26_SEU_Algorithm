#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n , m ;
    cin >> n >> m ;
    string s1 , s2 ;
    cin >> s1 >> s2 ;
    int k = 0 ;
    vector <int> next(m+10 , 0) ;
    
    for(int i = 1 ; i < m ; i ++){
        while(k && s2[i] != s2[k])
            k = next[k] ;
        if(s2[i] == s2[k])k ++ ;
        next[i+1] = k;
    }
    k = 0 ;
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i ++){
        while(k && s1[i] != s2[k])
            k = next[k] ;
        if(s1[i] == s2[k]) k ++ ;
        if(k == m){
            cnt ++ ;
        }
    }
    cout << cnt << endl ;
}

int main(){
    int t ;cin >> t ;
    while(t--)solve() ;
    return 0 ;
}