#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){

    ordered_set<int>s;
    s.insert(10);
    s.insert(9);
    s.insert(50);
    s.insert(1);

    cout << s.order_of_key(50) << endl;
    cout << *s.find_by_order(0) << endl;

    return 0;
}
