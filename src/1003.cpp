#include <bits/stdc++.h>
using namespace std ;


int main(){
    ios::sync_with_stdio(0) ;
    int n ; 
    cin >> n ;
    for(int i = 0 ; i < n ; i ++){
        int m ;
        cin >> m ;
        vector <int> v ;
        for(int j = 0 ; j < m ; j ++){
            int x ; cin >> x ;
            v.emplace_back(x) ;
        }
        
        for(int j = 0 ; j < m-1 ; j ++){
            if(v[j] > v[j+1])
                swap(v[j],v[j+1]);
        }
        

        for(auto x : v)
            cout << x << ' ' ;
        cout << endl ;
    }
    return 0 ;
}