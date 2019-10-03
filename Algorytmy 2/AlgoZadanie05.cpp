#include <iostream>
#include <string>

using namespace std;

struct Leaf
{
	int key;
	string value;
	Leaf* father;
	Leaf* sons[2];

	Leaf()
	{
		father = nullptr;
		for (int i = 0; i < 2; ++i) sons[i] = nullptr;
	}

	Leaf(Leaf* father)
	{
		this->father = father;
		for (int i = 0; i < 2; ++i) sons[i] = nullptr;
	}
};

class Tree
{
	Leaf* root;

	Leaf* Search(int key);
	Leaf* Erase(Leaf* leaf);
	Leaf* MaxNode(Leaf* leaf);

public:
	Tree();
	~Tree();
	void Insert(Leaf* leaf);
	void EraseAndDisplay(int key);
};

Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
	if (root != nullptr)
		delete root;
}

Leaf* Tree::Search(int key)
{
	Leaf* v = root;
	while (v != nullptr && v->key != key)
	{
		if (key < v->key)
			v = v->sons[0];
		else
			v = v->sons[1];
	}
	return v;
}

Leaf* Tree::MaxNode(Leaf* leaf)
{
	Leaf* result = leaf;
	while (result->sons[0] != nullptr)
	{
		result = result->sons[0];
	}
	return result;
}

void Tree::Insert(Leaf* leaf)
{
	if (root == nullptr)
	{
		root = leaf;
		return;
	}

	Leaf* father = root;
	while (true)
	{
		int i = (leaf->key < father->key) ? 0 : 1;

		if (father->sons[i] == nullptr)
		{
			father->sons[i] = leaf;
			leaf->father = father;
			return;
		}
		else
		{
			father = father->sons[i];
		}
	}
}

Leaf* Tree::Erase(Leaf* leaf)
{
	if (leaf->sons[0] == nullptr && leaf->sons[1] == nullptr) // doesn't have children
	{
		if (leaf->father == nullptr) //doesn't have father 
		{
			delete leaf;
			root = nullptr;
			return nullptr;
		}

		if (leaf->father->sons[0] == leaf)
			leaf->father->sons[0] = nullptr;
		else
			leaf->father->sons[1] = nullptr;

		Leaf* father = leaf->father;
		delete leaf;
		return father;
	}
	else if (leaf->sons[0] != nullptr && leaf->sons[1] != nullptr)
	{
		Leaf* replacer = MaxNode(leaf->sons[1]);
		leaf->key = replacer->key;
		leaf->value = replacer->value;
		Erase(replacer);
		return leaf->father;
	}
	else //have one child
	{
		int i = (leaf->sons[1] == nullptr) ? 1 : 0;

		if (leaf->father == nullptr) //doesn't have father
		{
			root = leaf->sons[1 - i];
			root->father = nullptr;
			delete leaf;
			return nullptr;
		}

		Leaf* father = leaf->father;
		Leaf* son = leaf->sons[1- i];
		if (father->sons[0] == leaf)
		{
			father->sons[0] = son;
			son->father = father;
		}
		else
		{
			father->sons[1] = son;
			son->father = father;
		}
		delete leaf;
		return father;
	}

}

void Tree::EraseAndDisplay(int key)
{
	Leaf* leaf = Search(key);

	if (leaf == nullptr)
	{
		cout << "NIE\n";
		return;
	}

	while (leaf != nullptr)
	{
		cout << leaf->value;
		leaf = Erase(leaf);
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);

	int edges, n;
	cin >> edges >> n;

	Tree tree;

	for (int i = 0; i < edges; i++)
	{
		Leaf* temp = new Leaf;
		cin >> temp->key >> temp->value;
		tree.Insert(temp);
	}


	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		tree.EraseAndDisplay(x);
	}

	return 0;
}