/*
    written by tubotu.
    This is a Wrong Answer of ABC207-C.

    float 桁落ち
    浮動小数で情報が消える過程。
    1. 情報落ち
        めちゃでかい数字にめちゃ小さい数字を足すとき。
        回避するにはなるべく小さい数から順に足し算を行う等
    (ex)
        double x = 1000000000;
        double y = 0.000000001;

        // 1000000000.000000001 を表現するには19桁分必要 → 扱えない
        // double 型は 約16桁の並び (数字の並び と 小数点の位置) を保持できる。
        double z = x + y;  // yの分が消えてしまう

    2. 桁落ち
        差がめちゃくちゃ小さい2の数を引き算するとき。
        回避するにはなるべく差が大きくなるように計算順序を工夫する等
    (ex)
        x, y を無限少数。double 型が扱える桁を 6 桁として
            実際の値                コンピュータ上での値
        x   0.1234567890123...      0.123456
        y   0.1233456789012...      0.123345

      z=x-y  0.0001111111111...     0.000111

    5桁までの精度で計算をしたが計算結果の精度は3桁に落ちてしまっている。


    reference: "https://www.cc.kyoto-su.ac.jp/~yamada/programming/float.html"

    float 型
        float 型は 4byte = 32bit のサイズをもつ。1bit を符号部、8bit を指数部、23bitを仮数部に用いる。
        精度 (有効桁数) は 10進数で約 7 桁 。 2進数で 24(23 + 1)桁。

    double 型
        double 型は 8byte = 64bit のサイズをもつ。 1bit を符号部、11bit を指数部、52bit を仮数部に用いる。
        精度 (有効桁数) は 10進数で約 15 桁。 2進数で 53(=52+1) 桁。
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