#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Answer;
vector<int> a, b;

int main()
{
	int T, test_case;
	int n, t;
	string tmp;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		a.clear();
		b.clear();
		cin >> n >> t >> tmp;
		for (int i = 0; i < n; i++) {
			b.push_back(tmp[i] - '0');
			a.push_back(0);
		}

		for (int i = 0; i < n; i++) {
			if (b[i] == 1) {
				if (i > t - 1) {
					if (a[i - t] == 0)
						if (i < n - t) {
							if (i < n - t - t - 1 && b[i + t + t] == 0)
								a[i - t] = 1;
							else a[i + t] = 1;
						}
						else
							a[i - t] = 1;
				}
				else
					a[i + t] = 1;
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		for (int i = 0; i < n; i++) cout << a[i];
		cout << '\n';
	}

	return 0;//Your program should return 0 on normal termination.
}