/* etc
 * 2609 최대공약수와 최소공배수
 * 두 개의 자연수를 입력받아 최대 공약수와 최소공배수 출력
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
	cout << k << "\n";
	return k * (n / k) * (m / k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	cout << lcm(a, b);

	return 0;
}