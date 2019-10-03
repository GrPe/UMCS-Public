#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Client
{
	string name;
	float priority;
	int visiting;

	Client(const string& name, float priority, int visiting)
	{
		this->name = name;
		this->priority = priority;
		this->visiting = visiting;
	}

	bool operator<(const Client& client) const
	{
		if (this->priority == client.priority)
		{
			return this->visiting < client.visiting;
		}
		return this->priority < client.priority;
	}

	bool operator==(const Client& client) const
	{
		return (this->priority == client.priority && this->visiting == client.visiting);
	}

	bool operator>(const Client& client) const
	{
		if (*this == client) return false;
		return !(*this < client);
	}
};

struct Leaf
{
	string key;
	priority_queue<Client, vector<Client>, less<Client>> clients;
	Leaf* father;
	Leaf* sons[2];

	Leaf()
	{
		sons[0] = nullptr;
		sons[1] = nullptr;
		father = nullptr;
	}
};

struct Result
{
	Leaf* leaf;
	bool isFound;

	Result(Leaf* leaf, bool isFound)
	{
		this->leaf = leaf;
		this->isFound = isFound;
	}
};

class Tree
{
	Leaf* root;

	Result Search(const string& key);
	void RotateLeft(Leaf* node);
	void RotateRight(Leaf* node);
	void Splay(Leaf* node);

public:
	Tree();
	~Tree();
	void Insert(Leaf* leaf);
	void Delete(string key);
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

Result Tree::Search(const string& key)
{
	Leaf* v = root;
	Leaf* last = nullptr;
	while (v != nullptr && v->key != key)
	{
		last = v;
		if (key < v->key)
			v = v->sons[0];
		else
			v = v->sons[1];
	}
	if (v == nullptr)
		return { last, false };
	return { v, true };
}

void Tree::Splay(Leaf* node)
{
	if (node == root)
	{
		return;
	}

	if (node->father == root) // zig
	{
		if (node->key > root->key) //right son
		{
			RotateLeft(root);
			root = node;
		}
		else //left son
		{
			RotateRight(root);
			root = node;
		}
	}
	else // node has a grandparent
	{
		if (node->father->father == root) root = node;
		if (node->father->father->key > node->father->key && node->father->key > node->key) //left son of left son (zig-zig)
		{
			RotateRight(node->father);
			RotateRight(node->father);
		}
		else if (node->father->father->key < node->father->key && node->father->key > node->key) //right son of left son (zig-zag)
		{
			RotateRight(node->father);
			RotateLeft(node->father);
		}
		else if (node->father->father->key < node->father->key && node->father->key < node->key) //right son of right son (zag-zag)
		{
			RotateLeft(node->father);
			RotateLeft(node->father);
		}
		else //left son of right son (zag-zig)
		{
			RotateLeft(node->father);
			RotateRight(node->father);
		}
		Splay(node);
	}
}

void Tree::RotateLeft(Leaf* node)
{
	Leaf* son = node->sons[1];
	Leaf* grand = node->father;

	node->sons[1] = son->sons[0];
	son->sons[0] = node;

	//fathers
	if (node->sons[1] != nullptr) node->sons[1]->father = node;
	node->father = son;
	son->father = grand;

	//grandfather
	if (grand != nullptr)
	{
		if (grand->sons[0] == node) grand->sons[0] = son;
		else grand->sons[1] = son;
	}
}

void Tree::RotateRight(Leaf* node)
{
	Leaf* son = node->sons[0];
	Leaf* grand = node->father;

	node->sons[0] = son->sons[1];
	son->sons[1] = node;

	//fathers
	if (node->sons[0] != nullptr) node->sons[0]->father = node;
	node->father = son;
	son->father = grand;

	//grandfather
	if (grand != nullptr)
	{
		if (grand->sons[0] == node) grand->sons[0] = son;
		else grand->sons[1] = son;
	}
}

void Tree::Insert(Leaf * leaf)
{
	if (root == nullptr)
	{
		root = leaf;
		return;
	}

	Result result = Search(leaf->key);
	Leaf* node = result.leaf;

	if (result.isFound) //node exists
	{
		node->clients.push(std::move(leaf->clients.top()));
		delete leaf;
		Splay(node);
		return;
	}
	else
	{
		if (leaf->key < node->key)
		{
			node->sons[0] = leaf;
			leaf->father = node;
		}
		else
		{
			node->sons[1] = leaf;
			leaf->father = node;
		}
		Splay(leaf);
	}

}

void Tree::Delete(string key)
{
	Result result = Search(key);
	Splay(result.leaf);

	if (!result.isFound || result.leaf->clients.empty())
	{
		cout << "BRAK\n";
		return;
	}

	Leaf* leaf = result.leaf;

	auto temp = leaf->clients.top();
	leaf->clients.pop();
	cout << temp.name << "\n";
	temp.visiting--;
	if (temp.visiting > 0)
		leaf->clients.push(temp);
}

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	Tree tree;
	char operation;
	string city, client;
	float priority;
	int counter;
	for (int i = 0; i < n; i++)
	{
		cin >> operation;

		if (operation == 'A')
		{
			Leaf* leaf = new Leaf;
			cin >> leaf->key >> client >> priority >> counter;
			leaf->clients.push({ client, priority, counter });
			tree.Insert(leaf);
		}
		else
		{
			cin >> city;
			tree.Delete(city);
		}
	}

	return 0;
}