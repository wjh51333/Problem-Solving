/* etc
 * 1373 2진수 8진수
 * 2진수가 주어졌을 때, 8진수로 변환
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, octal;
	cin >> s;

	string k[] = { "0", "1", "2", "3", "4", "5", "6", "7" };

	int start = s.size() % 3 - 1;
	if (start == -1)
		start = 2;

	for (int i = start; i < s.size(); i += 3) {
		int n = 0, m = 1;
		for (int j = i; j > i - 3 && j >= 0; j--) {
			if (s[j] == '1')
				n += m;
			m *= 2;
		}
		octal.append(k[n]);
	}
	cout << octal;

	return 0;
}