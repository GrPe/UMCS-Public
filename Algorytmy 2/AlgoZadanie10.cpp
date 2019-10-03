#include <iostream>
#include <list>
#include <vector>
#include <string>

#define SIZE 419

using namespace std;


int func(string text, int mod)
{
	int h = 0;
	for (auto x : text)
	{
		h += x;
	}
	return h % mod;
}

auto main() -> int
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	vector<list<pair<string, string>>> hashTable(SIZE);

	char operation;
	string text, text2;
	for (int i = 0; i < t; i++)
	{
		cin >> operation;
		if (operation == 'A')
		{
			cin >> text >> text2;
			hashTable[func(text, SIZE)].push_back({ text, text2 });
		}
		else
		{
			bool isFound = false;
			cin >> text;
			int hs = func(text, SIZE);
			for (auto x : hashTable[hs])
			{
				if (x.first == text)
				{
					isFound = true;
					cout << x.second<<"\n";
					break;
				}
			}
			if (!isFound) cout << "-\n";
		}
	}

	return 0;
}