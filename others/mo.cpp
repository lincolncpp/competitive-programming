#include <bits/stdc++.h>

using namespace std;

/*
    Runtime: O((n+q)*sqrt(n))
    Runtime w/ hilbert: O(n*sqrt(q))
*/

const int maxn = 2e5+123;
const int logmaxn = 20;

// https://codeforces.com/blog/entry/61203
inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t res = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	res += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return res;
}

struct Query{
    int l, r, id, block;
    long long ord;

    bool operator<(const Query &b){

        // hilbert curve
        return ord < b.ord;

        // sqrt decomposition
        // if (block == b.block){
        //     if (block%2 == 0) return r < b.r;
        //     else return r > b.r;
        // }
        // else return block < b.block;
    }
};

int a[maxn];
Query qry[maxn];
int curr = 0;
int ans[maxn];

void add(int pos){
    curr += a[pos];
}

void remove(int pos){
    curr -= a[pos];
}

void process(int q){
    int currentl = 0;
    int currentr = -1;

    for(int i = 0;i < q;i++){
        int l = qry[i].l;
        int r = qry[i].r;

        while (currentl < l) remove(currentl++);
        while (currentl > l) add(--currentl);
        while (currentr < r) add(++currentr);
        while (currentr > r) remove(currentr--);

        ans[qry[i].id] = curr;
    }
}

int main(){

    int n, q;cin>>n>>q;
    for(int i = 0;i < n;i++) cin>>a[i];

    int len = (int)sqrt(n)+1;

    for(int i = 0;i < q;i++){
        int l, r;cin>>l>>r;
        l--;r--;

        qry[i].l = l;
        qry[i].r = r;
        qry[i].id = i;
        qry[i].block = l/len;
        qry[i].ord = hilbertOrder(qry[i].l, qry[i].r, logmaxn, 0);
    }

    sort(qry, qry+q);
    process(q);

    for(int i = 0;i < q;i++) cout << ans[i] << endl;

    return 0;
}
