/* etc
 * 1158 요세푸스 문제
 * 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(<= N)가 주어진다
 * 이제 순서대로 K번째 사람을 제거한다
 * 한 사람이 제거되면 남은 사람들로 이루어진 월을 따라 이 과정을 계속해 나간다
 * 이 과정은 N명의 사람이 모두 제거될 떄까지 계속된다
 * 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다
 * ex) (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>
 * N과 K가 주어지면 (N, K)-요세푸스 순열 출력
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, cur = 0;
	cin >> n >> k;

	vector<int> arr(n);
	vector<int> ans;
	for (int i = 0; i < arr.size(); i++)
		arr[i] = i + 1;

	for (int i = 0; i < n; i++) {
		cur = (cur + k - 1) % arr.size();
		ans.push_back(arr[cur]);
		arr.erase(arr.begin() + cur, arr.begin() + cur + 1);
	}

	cout << "<";
	for (int i = 0; i < ans.size() - 1; i++)
		cout << ans[i] << ", ";
	cout << ans[ans.size() - 1] << ">";

	return 0;
}