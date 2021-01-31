/* etc
 * 6588 골드바흐의 추측
 * 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다
 * 이 추측은 아직도 해결되지 않은 문제이다
 * 백만 이하의 모든 짝수에 대해서, 이 추측을 검증
 */

#include <iostream>
#include <cmath>
#define MAX 1000000
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool* prime = new bool[MAX + 1];
	fill_n(prime, MAX + 1, 1);
	prime[0] = prime[1] = false;

	// 에라토스테네스의 체 활용
	// 2부터 시작해서 특정 수의 배수에 해당사는 수를 모두 지운다
	// 지울 때 자시자신은 지우지 않고 이미 지워진 수는 건너뛴다
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (prime[i]) {
			// 지워진 숫자가 아니라면, 그 배수부터 출발하여 가능한 모든 숫자 지우기
			for (int j = i * 2; j <= MAX; j += i)
				prime[j] = false;
		}
	}

	int n;
	while (cin >> n) {
		if (n == 0)
			break;

		for (int i = 3; i <= n; i++) {
			// 3부터 시작하여 두 홀수 소수의 합으로 표현할 수 있으면 출력
			if (prime[i] && prime[n - i]) {
				cout << n << " = " << i << " + " << n - i << "\n";
				break;
			}
		}
	}

	return 0;
}