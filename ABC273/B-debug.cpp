#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;


i64  solver1(i64  X, i64  K){
    vector<i64> nums(17, 0);
 
    i64 tmp = X, keta = 0;
    for(i64  i = 0; i < 16; i++){
        nums.at(i) = (tmp % 10);
        tmp /= 10;
        if(tmp == 0){
            break;
        }
        else{
            keta++;
        }
    }
 
    for(i64  i = 0; i < K; i++){
        if(nums.at(i) >= 5){
            nums.at(i) = 0;
            nums.at(i+1)++;
        }
        else{
            nums.at(i) = 0;
        }
    }

    if(nums.at(keta + 1) >= 1){
        keta++;
    }

    i64  ret = 0;
    for(i64  i = keta; i >= 0; i--){
        ret += nums.at(i);
        if(i > 0) ret *= 10;
    }

    return ret;
}

i64  solver2(i64  X, i64  K){
    for(i64  i = 0; i < K; i++){
        i64 tmp = 1;
        for(i64  j = 0; j < i; j++){
            tmp *= 10;
        }
 
        X += 5*tmp;
        X = (X / (tmp * 10)) * (tmp * 10);
    }

    return X;
}

string solver3(i64 X, i64 K){
    vector<i64> nums(17, 0);

    i64 tmp = X, keta = 0;
    for(int i = 0; i < 16; i++){
        nums.at(i) = (tmp % 10);
        tmp /= 10;
        if(tmp == 0){
            break;
        }
        else{
            keta++;
        }
    }

    for(int i = 0; i < K; i++){
        if(nums.at(i) >= 5){
            nums.at(i) = 0;
            nums.at(i+1)++;
        }
        else{
            nums.at(i) = 0;
        }
    }

    int tmpK = K;
    while(nums.at(tmpK) > 9){
        nums.at(tmpK + 1)++;
        nums.at(tmpK) = 0;
        tmpK++;
    }

    if(nums.at(keta + 1) >= 1){
        keta++;
    }

    string ret = "";
 
    if(nums.at(keta) == 0){
        return "0";
    }
    else{
        for(int i = keta; i >= 0; i--){
            ret += '0' + nums.at(i);
        }
    }
 
    return ret;
}


int  main() {
    random_device seedGen;
    mt19937_64 rd(seedGen());

    for(int i = 0; i < 100; i++){
        i64 X = rd() % 1000000000000000, K = rd() % 15 + 1;

        cout << "i = " << i << endl;
        cout << "X = " << X << ", K = " << K << endl;
        cout << "solver1() = " << solver1(X, K) << endl;
        cout << "solver3() = " << solver3(X, K) << endl;

        string ret = ((to_string(solver1(X, K)) == solver3(X, K)) ? "Correct" : "Wrong");
        cout << ret << "\n";
        if(ret == "Wrong")  break;
        cout << "\n";
    }

    cerr << "Hello!!" << endl;

    return 0;
}