#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

vector<int> solver1(int N, vector<int> P){
    vector<int> vec(N);
    for(int i = 1; i <= N; i++){
        vec.at(i-1) = i;
    }

    vector<int> pre;
    do{
        if(P == vec){
            break;
        }
        else{
            pre = vec;
        }
    }while(next_permutation(vec.begin(), vec.end()));

    // for(int i = 0; i < N; i++){
    //     cout << pre.at(i) << " ";
    // }
    // cout << '\n';

    return pre;
}

vector<int> solver2(int N, vector<int> P){
    set<int> seen, output;
    for(int i = 0; i < N; i++){
        seen.insert(P.at(i));
    }

    int th = -1;
    for(int i = N-1; i >= 0; i--){
        int now = P.at(i) - 1;
        if(now == 0){
            seen.erase(1);
            output.insert(1);
            continue;
        }

        if(seen.count(now)){
            seen.erase(now + 1);
            output.insert(now + 1);
        }
        else{
            P.at(i)--;
            output.erase(now);
            output.insert(now + 1);
            break;
        }
    }

    int index = N-1;
    for(auto ele : output){
        P.at(index) = ele;
        index--;
    }
    
    // for(int i = 0; i < N; i++){
    //     cout << P.at(i);
    //     if(i < N-1){
    //         cout << " ";
    //     }
    //     else{
    //         cout << '\n';
    //     }
    // }

    return P;
}

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++){
    vec.at(i) = i + 1;
  }
  
  bool first = true;
  
  do{
    if(first){
        first = false;
        continue;
    }

    vector<int> sol1 = solver1(N, vec);
    vector<int> sol2 = solver2(N, vec);

    if(sol1 == sol2){
        cout << "OK" << '\n';
    }
    else{
        cout << "False" << '\n';
        for(int i = 0; i < N; i++){
            cout << vec.at(i) << " ";
        }
        cout << '\n';
        for(int i = 0; i < N; i++){
            cout << sol1.at(i) << " ";
        }
        cout << '\n';
        for(int i = 0; i < N; i++){
            cout << sol2.at(i) << " ";
        }
        cout << '\n';
    }
  }while(next_permutation(vec.begin(), vec.end()));
}