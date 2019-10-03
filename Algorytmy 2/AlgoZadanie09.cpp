#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

struct Node
{
	bool exists;
	vector<Node*> tab;

	Node() : tab(26, nullptr)
	{
		exists = false;
	}
};

class TrieTree
{
	Node* root;

public:
	TrieTree()
	{
		root = new Node();
	}

	void Add(const string& text)
	{
		Node* current = root;

		int i = 0;
		for (; i < text.size(); i++)
		{
			if (current->tab[text[i] - 'a'] != nullptr)
			{
				current = current->tab[text[i] - 'a'];
			}
			else
			{
				current->tab[text[i] - 'a'] = new Node;
				current = current->tab[text[i] - 'a'];
			}
		}
		current->exists = true;
	}

	void FindAndDisplay(const string& text)
	{
		Node* current = root;
		string currenttext;

		int i = 0;
		for ( ;i < text.size(); i++)
		{
			if (current->tab[text[i] - 'a'] != nullptr)
			{
				current = current->tab[text[i] - 'a'];
			}
			else
			{
				cout << "-\n";
				break;
			}
		}

		if (i == text.size())
		{
			DisplayAll(current, text);
		}

	}

	void DisplayAll(Node* node, string prefix)
	{
		if (node == nullptr) return;
		
		vector<string> strings;

		if(node->exists)
			strings.push_back(prefix);

		AddAllWord(strings, prefix, node);

		sort(strings.begin(), strings.end());

		for (auto s : strings)
		{
			cout << s << "\n";
		}
	}

	void AddAllWord(vector<string>& strings, const string& current, Node* node)
	{
		for (int i = 0; i < node->tab.size(); i++)
		{
			if (node->tab[i] != nullptr)
			{
				if (node->tab[i]->exists)
					strings.push_back(current + static_cast<char>('a' + i));
				AddAllWord(strings, current + static_cast<char>('a' + i), node->tab[i]);
			}
		}
	}

};


auto main() -> int
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	char c;
	string text;
	TrieTree trieTree;
	for (int i = 0; i < t; i++)
	{
		cin >> c >> text;

		if (c == 'A')
		{
			trieTree.Add(text);
		}
		else
		{
			trieTree.FindAndDisplay(text);
		}
	}

	return 0;
}
