/* etc
 * 1212 8진수 2진수
 * 8진수가 주어졌을 때, 2진수로 변환
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n, bi;
	cin >> n;
	
	string k[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
	string k_f[] = { "1", "10", "11", "100", "101", "110", "111" };

	if (n == "0") {
		cout << 0;
		return 0;
	}

	bi.append(k_f[n[0] - '0' - 1]);
	for (int i = 1; i < n.size(); i++) {
		bi.append(k[n[i] - '0']);
	}
	cout << bi;

	return 0;
}