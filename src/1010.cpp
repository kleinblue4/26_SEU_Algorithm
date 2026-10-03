#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n , k ;
    cin >> n >> k ;
    vector <int> a(n+3) ;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i] ;

    int low = 0 , high = n-1 , mid, pre_mid = n ;
    while(low <= high){
        pre_mid = mid ;
        mid = (low + high) >> 1 ;
        if(a[mid] == k)break ;
        else if(a[mid] < k){
            low = mid+1 ;
        }else{
            high = mid-1 ;
        }
    }
    if(a[mid] == k){
        cout << "success, father is " << a[pre_mid] << endl ;
    }else{
        cout << "not found, father is " << a[mid] << endl ;
    }
}

int main(){
    int n ; cin >> n ;
    while(n --)
        solve() ;
}

/*
3
7 10 1 3 5 7 9 11 13
7 14 2 4 6 8 10 12 14
7 10 2 4 6 8 10 12 14
*/