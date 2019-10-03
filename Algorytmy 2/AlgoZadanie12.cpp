#include <iostream>
#include <vector>

using namespace std;

int Hash(vector<int> hash, int start, int end)
{
	int sum = 0;
	for (int i = start; i < end; i++)
	{
		sum = (sum + hash[i]*(i-start+1)) % 159951456;
	}

	return sum % 159951456;
}

unsigned FindSequence(vector<int>& data, vector<int>& sequence)
{
	vector<unsigned> indexes;

	int hash = Hash(sequence, 0, sequence.size());

	for (unsigned i = 0; i < data.size() - sequence.size() + 1; i++)
	{
		if (Hash(data, i, i + sequence.size()) == hash)
		{
			bool equal = true;
			for (unsigned j = 0; j < sequence.size(); j++)
			{
				if (sequence[j] != data[i + j])
				{
					equal = false;
					break;
				}
			}

			if (equal)
				indexes.push_back(i);
		}

		if (indexes.size() == 2) break;
	}

	long long int position = 0;

	while (data.size() > position)
	{
		position = indexes[0] + indexes[1];
		indexes[0] = indexes[1];
		indexes[1] = position;
	}

	return position;

}

auto main() -> int
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	vector<int> data(t);

	for (int i = 0; i < t; i++)
	{
		cin >> data[i];
	}

	int n;
	cin >> n;

	vector<int> sequence(n);

	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	unsigned s = FindSequence(data, sequence);

	cout << s - data.size() << "\n";

	return 0;
}