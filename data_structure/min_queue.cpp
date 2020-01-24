#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

struct minqueue{
private:
    int add = 0;
    stack<pair<int, int>>sl, sr;

    void push(int x, stack<pair<int, int>>&s){
        if (s.size() > 0) s.push({x, std::min(x, s.top().second)});
        else s.push({x, x});
    }
    void move(){
        if (sl.size() == 0){
            while(sr.size()) {
                push(sr.top().first, sl);
                sr.pop();
            }
        }
    }

public:
    void push(int x){
        push(x-add, sr);
    }

    void pop(){
        move();
        if (sl.size()) sl.pop();
    }

    int top(){
        move();
        if (sl.size()) return sl.top().first+add;
        return 0;
    }

    int min(){
        move();
        int res = INF;
        if (sl.size()) res = std::min(res, sl.top().second+add);
        if (sr.size()) res = std::min(res, sr.top().second+add);
        return res;
    }

    int size(){
        return sl.size()+sr.size();
    }

    void increase(int x){
        add += x;
    }

};

int main(){

    minqueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.increase(100);
    q.push(7);

    while(q.size()){
        cout << q.top() << " " << q.min() << endl;
        q.pop();
    }

    return 0;
}
