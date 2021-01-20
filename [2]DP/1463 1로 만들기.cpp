/* Dynamic Programming 
 * 1463 1로 만들기 
 * 정수 X에 사용할 수 있는 연산은 3가지
 * X가 3으로 나누어 떨어지면, 3으로 나눈다
 * X가 2로 나누어 떨어지면, 2로 나눈다
 * 1을 뺀다
 * 위와 같은 연산 세개를 적절히 사용해서 N을 1로 만들려고 할 때
 * 연산을 사용하는 횟수의 최솟값
 */

#include <iostream>

using namespace std;

int cache[1000001] = { 0, };

void calc(int n)
{
	// 1일 때는 연산 횟수 0
	cache[1] = 0;
	
	for (int i = 2; i <= n; i++) {
		// 규칙 3. 1을 뺀다
		cache[i] = cache[i - 1] + 1;

		// 규칙 2. X가 2로 나누어 떨어지면 2로 나눈다
		if (i % 2 == 0)
			cache[i] = min(cache[i], cache[i / 2] + 1);

		// 규칙 1. X가 3으로 나누어 떨어지면 3으로 나눈다
		if (i % 3 == 0)
			cache[i] = min(cache[i], cache[i / 3] + 1);
	}
}

int main()
{
	int N;
	cin >> N;
	calc(N);
	cout << cache[N] << endl;
	return 0;
}