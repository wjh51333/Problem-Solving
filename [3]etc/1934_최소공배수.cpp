/* etc
 * 1934 최소공배수
 * 두 자연수 A와 B에 대해서, A의 배수이면서 B의 배수인 자연수를 A와 B의 공배수라고 한다
 * 이런 공배수 중에서 가장 작은 수를 최소공배수라고 한다
 * 두 자연수 A와 B가 주어졌을 때, A와 B의 최소공배수 출력
 */

#include <iostream>

using namespace std;

int gcd(int n, int m)
{
	if (m == 0)
		return n;
	else
		return gcd(m, n % m);
}

int lcm(int n, int m)
{
	int k = gcd(n, m);
	return k * (n / k) * (m / k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}

	return 0;
}