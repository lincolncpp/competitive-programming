#include <bits/stdc++.h>

using namespace std;

#define ll long long

const uint64_t mod = 2305843009213693951;
uint64_t modmul(uint64_t a, uint64_t b){
	uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
	uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
	uint64_t ret = (l&mod) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & mod) + (ret>>61);
	ret = (ret & mod) + (ret>>61);
	return ret-1;
}

int main(){

    long long a = 125462315651256000;
    long long b = 665232002331569800;

    cout << modmul(a, b) << endl;

    return 0;
}
