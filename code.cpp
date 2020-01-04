#include <string>
#include <vector>
using namespace std;

long long factorial(int n) {
    if (!n)
        return 1;
    long long k = 1;
    for (int i=2; i<=n; i++)
        k *= i;
    return k;
}

vector<int> solution(int n, long long k) {
	vector<int> numbers(n);
	for (int i = 0; i < n; i++)
		numbers[i] = i + 1;

	int N = n;
	long long K = k;
	vector<int> answer;
	for (int i = 0; i < n; i++)
	{
		long long tmp = factorial(N - 1);
		int index = (K - 1) / tmp;
		answer.push_back(numbers[index]);
		numbers.erase(numbers.begin() + index);

		if (K == 0)
			K = 0;
		else if (K % tmp == 0)
			K = tmp;
		else
			K %= tmp;
		N--;
	}

	return answer;
}
