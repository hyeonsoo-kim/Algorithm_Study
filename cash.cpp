#include <iostream>
using namespace std;

int main() {
	int amount;
	cin >> amount;
	int res = (amount /500);
	amount %= 500;
	res+=amount /100;
	amount /= 100
	res += amount/50;
	amount = res %50;
	res += amount /10;
	cout << res << endl;
	return 0;
}
