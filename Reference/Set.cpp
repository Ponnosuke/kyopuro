#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    /*
    map<int, set<int>> mp;

    0   {}
    1   {2, 5, 7}
    2   {3, 5, 6, 8}
    3   {}
    4   {3}
    5   {2}
    */
    map<int ,set<int>> mp;
    mp[1].insert(5);
    mp[1].insert(2);
    mp[1].insert(7);
    mp[2].insert(5);
    mp[2].insert(3);
    mp[2].insert(8);
    mp[2].insert(6);
    mp[4].insert(3);
    mp[5].insert(2);

    cout << "lower_bound(3)" << "\n";
    for(int i = 0; i < 6; i++){
        cout << "i = " << i << "\n";
        auto itr = mp[i].lower_bound(3);
        if(itr == mp[i].begin()){
            cout << "itr == mp[" << i << "].begin()" << "\n";
        }
        else{
            cout << "*prev(itr) = " << *prev(itr) << "\n"; 
        }
        if(itr == mp[i].end()){
            cout << "itr == mp[" << i << "].end()" << "\n";
        }
        else{
            cout << "*itr = " << *itr << "\n";
        }
    }

    cout << "\n";
    cout << "mp.at(0).count(1) = ";
    if(mp.at(0).count(1)){
        cout << "True" << "\n";
    }
    else{
        cout << "false" << "\n";
    }
    cout << "mp.at(0).count(0) = ";
    if(mp.at(0).count(0)){
        cout << "True" << "\n";
    }
    else{
        cout << "false" << "\n";
    }
    cout << "mp.at(0)\n";
    for(auto value : mp.at(0)){
        cout << "value = " << value << "\n";
    }
    cout << "\n";
    cout << "mp.at(1)\n";
    for(auto value : mp.at(1)){
        cout << "value = " << value << "\n";
    }
    cout << "\n";

    cout << "lower_bound(8)" << "\n";
    for(int i = 0; i < 6; i++){
        cout << "i = " << i << "\n";
        auto itr = mp[i].lower_bound(8);
        if(itr == mp[i].begin()){
            cout << "itr == mp[" << i << "].begin()" << "\n";
        }
        else{
            cout << "*prev(itr) = " << *prev(itr) << "\n"; 
        }
        if(itr == mp[i].end()){
            cout << "itr == mp[" << i << "].end()" << "\n";
        }
        else{
            cout << "*itr = " << *itr << "\n";
        }
    }

    cout << "vector<set<int>> vecSet(5)" << "\n";
    vector<set<int>> vecSet(5);
    vecSet.at(3).insert(4);
    vecSet.at(4).insert(7);
    vecSet.at(4).insert(4);

    for(int i = 0; i < 5; i++){
        cout << "i = " << i << "\n";
        if(vecSet.at(i).empty()){
            cout << "vecSet.at(" << i << ") is empty" << "\n";
        }
        else{
            for(auto ele : vecSet.at(i)){
                cout << "ele = " << ele << "\n";
            }
        }
    }

}
/*
    INPUT:

    map<int, set<int>> mp;

    0   {}
    1   {2, 5, 7}
    2   {3, 5, 6, 8}
    3   {}
    4   {3}
    5   {2}



*/

/*
    OUTPUT:
    
    lower_bound(3)
    i = 0
    itr == mp[0].begin()
    itr == mp[0].end()
    i = 1
    *prev(itr) = 2
    *itr = 5
    i = 2
    itr == mp[2].begin()
    *itr = 3
    i = 3
    itr == mp[3].begin()
    itr == mp[3].end()
    i = 4
    itr == mp[4].begin()
    *itr = 3
    i = 5
    *prev(itr) = 2
    itr == mp[5].end()

    mp.at(0).count(1) = false
    mp.at(0).count(0) = false
    mp.at(0)

    mp.at(1)
    value = 2
    value = 5
    value = 7

    lower_bound(8)
    i = 0
    itr == mp[0].begin()
    itr == mp[0].end()
    i = 1
    *prev(itr) = 7
    itr == mp[1].end()
    i = 2
    *prev(itr) = 6
    *itr = 8
    i = 3
    itr == mp[3].begin()
    itr == mp[3].end()
    i = 4
    *prev(itr) = 3
    itr == mp[4].end()
    i = 5
    *prev(itr) = 2
    itr == mp[5].end()
*/