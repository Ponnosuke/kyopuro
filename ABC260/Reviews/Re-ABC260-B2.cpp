#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<int> A(N), B(N);
    for(auto &x : A)  cin >> x;
    for(auto &x : B)  cin >> x;

    // (score, 受験生番号)  受験生番号は -1 ずれてる
    vector<pair<int, int>> Eng(N), Mat(N), Sum(N);

    vector<bool> flag(N + 1, false); // 合格したら true . 数字はそのまま受験生番号に対応

    for(int i = 0; i < N; i++){
        Mat.at(i).first = A.at(i);
        Eng.at(i).first = B.at(i);
        Sum.at(i).first = A.at(i) + B.at(i);

        Mat.at(i).second = i + 1;  // 1 からスタートに注意して +1
        Eng.at(i).second = i + 1;
        Sum.at(i).second = i + 1;
    }

    // first ->  降順
    // second -> 昇順
    // ここにソート用の自作関数
    auto myGreater = [](pair<int, int> p1, pair<int, int> p2){
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        else{
            return p1.first > p2.first;
        }
    };  // セミコロン忘れずに

    sort(Mat.begin(), Mat.end(), myGreater);
    sort(Eng.begin(), Eng.end(), myGreater);
    sort(Sum.begin(), Sum.end(), myGreater);

    // debug
    /*
    cout << "Math" << endl;
    for(auto [l, r] : Mat){
        cout << l << " " << r << endl;
    }
    cout << "English" << endl;
    for(auto [l, r] : Eng){
        cout << l << " " << r << endl;
    }
    cout << "Sum" << endl;
    for(auto [l, r] : Sum){
        cout << l << " " << r << endl;
    }
    */

    for(int i = 0; i < X; i++){
        flag.at(Mat.at(i).second) = true;
    }
    int j = 0, index = 0;
    while(j < Y){
        if(flag.at(Eng.at(index).second)){
            index++;
            continue;
        }
        
        flag.at(Eng.at(index).second) = true;
        j++;
        index++;
    }
    j = 0, index = 0;
    while(j < Z){
        if(flag.at(Sum.at(index).second)){
            index++;
            continue;
        }
        
        flag.at(Sum.at(index).second) = true;
        j++;
        index++;
    }


    for(int i = 1; i <= N; i++){
        if(flag.at(i)){
            cout << i << endl;
        }
    }
}