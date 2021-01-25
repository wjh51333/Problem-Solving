/* etc
 * 10825 국영수
 * 도현이네 반 학생 N명의 이름과 국어, 영어, 수학 점수가 주어진다
 * 이때, 다음과 같은 조건으로 학생의 성적 정렬
 * 1. 국어 점수가 감소하는 순서로
 * 2. 국어 점수가 같으면 영어 점수가 증가하는 순서로
 * 3. 국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
 * 4. 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로
 *    (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다)
 * 문제에 나와있는 정렬 기준으로 정렬한 후 학생의 이름 출력
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct grade {
	string name;
	int ko;
	int en;
	int math;
};

bool compare(const grade& a, const grade& b)
{
	if (a.ko == b.ko) {
		if (a.en == b.en) {
			if (a.math == b.math)
				return a.name < b.name; // 모든 점수가 같으면 이름이 사전순으로 증가하는 순서
			return a.math > b.math; // 국어, 영어 점수가 같으면 수학 점수가 감소하는 순서
		}
		return a.en < b.en; // 국어 점수가 같으면 영어 점수가 증가하는 순서
	}
	return a.ko > b.ko; // 국어 점수가 감소하는 순서
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<grade> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].name >> arr[i].ko >> arr[i].en >> arr[i].math;

	// sort (시작주소, 종료주소, [비교함수])
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < n; i++)
		cout << arr[i].name << "\n";

	return 0;
}