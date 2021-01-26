/* etc
 * 11656 접미사 배열
 * 접미사 배열은 문자열 S의 모든 접미사를 사전순으로 정렬해 놓은 배열
 * baekjoon의 접미사는 baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n 총 8가지
 * 이를 사전순으로 정렬하면 aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon
 * 문자열 S가 주어졌을 때, 모든 접미사를 사전순으로 정렬한 다음 출력
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

	string s, suffix[1001];
	cin >> s;
	int n = s.size();

	for (int i = 0; i < n; i++)
		suffix[i] = &s[i];

	sort(suffix, suffix + n);
	for (int i = 0; i < n; i++)
		cout << suffix[i] << "\n";

	return 0;
}