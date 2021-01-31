/* etc
 * 1850 최대공약수
 * 모든 자리가 1로만 이루어져 있는 두 자연수 A와 B가 주어진다
 * 이때, A와 B의 최대공약수 출력
 * ex) A가 111이고 B가 1111인 경우 A와 B의 최대공약수는 1
 */

#include <iostream>

using namespace std;

long long gcd(long long n, long long m)
{
	if (m == 0)
		return n;

	return gcd(m, n % m);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b;
	cin >> a >> b;
	
	if (a == 0 || b == 0) {
		cout << 0;
		return 0;
	}

	long long res = gcd(a, b);
	for (int i = 0; i < res; i++)
		cout << "1";

	return 0;
}