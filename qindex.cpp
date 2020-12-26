#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N, ans;
    scanf("%d",&N);
    vector<size_t> table(N);
    for (size_t i = 0 ; i< N ; i++) scanf("%d",&table[i]);
    sort(table.begin(), table.end());
	int l = 0, r = table[N-1];
	while ( l <= r ) {
		int k = (l+r)/2;
		int up = N - (lower_bound(table.begin(), table.end(), k) - table.begin());
		if ( up < k ) r = k-1;
		else {ans = k; l = k+1;}
		}
    printf("%d",ans);
    return 0;
}
