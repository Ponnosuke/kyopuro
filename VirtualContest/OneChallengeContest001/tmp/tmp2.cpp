/*
    WA
    written by tubotu
*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define brep(i,n) for(int i=n-1;i>=0;i--)
#define brep1(i,n) for(int i=n;i>=1;i--)
#define rep1(i,n) for(int i=1;i<n;i++)
#define cY cout<<"Yes"<<endl
#define cN cout<<"No"<<endl
#define ll long long

int main(void){
    int n;
    cin >> n;
    float t[n], l[n], r[n];
    int ans = 0;
    rep(i,n){
        cin >> t[i] >> l[i] >> r[i];
    }
    float l_i, r_i, l_j, r_j;
    rep(i,n){
        if(t[i] == 1){
            l_i=l[i];
            r_i=r[i];
        }
        else if(t[i] == 2){
            l_i=l[i];
            r_i=r[i]-0.1;
        }
        else if(t[i] == 3){
            l_i=l[i]+0.1;
            r_i=r[i];
        }
        else{
            l_i=l[i]+0.1;
            r_i=r[i]-0.1;
        }
        for(int j=i+1;j<n;j++){
            if(t[j] == 1){
                l_j=l[j];
                r_j=r[j];
            }
            else if(t[j] == 2){
                l_j=l[j];
                r_j=r[j]-0.1;
            }
            else if(t[j] == 3){
                l_j=l[j]+0.1;
                r_j=r[j];
            }
            else{
                l_j=l[j]+0.1;
                r_j=r[j]-0.1;
            }
            if(max(l_i,l_j) <= min(r_i,r_j))ans++;
        }
    }
    cout << ans << endl; 
    return 0;
}