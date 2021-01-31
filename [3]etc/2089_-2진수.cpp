/* etc
 * 2089 -2진수
 * -2진법은 부호 없는 2진수로 표현이 된다
 * 2진법에서는 2^0, 2^1, 2^2, 2^3이 표현되지만
 * -2진법에서는 (-2)^0 = 1, (-2)^1 = -2, (-2)^2 = 4, (-2)^3 = -8을 표현한다
 * 10진법의 수를 입력 받아서 -2진수 출력
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	string m_bi;
	while (n != 0) {
		if (n % -2 == 0) {
			m_bi.append("0");
			n /= -2;
		}
		else {
			m_bi.append("1");
			n = (n - 1) / -2;
		}
	}
	reverse(m_bi.begin(), m_bi.end());
	cout << m_bi;

	return 0;
}