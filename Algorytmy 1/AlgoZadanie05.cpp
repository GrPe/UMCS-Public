#include <iostream>
#include <cstdint>
#include <memory>
#include <algorithm>
#include <vector>
#include <unordered_map>

//Global
uint32_t n, m;

std::vector<uint32_t> results;

class Tree
{
	public:
	uint32_t i;
	std::vector<Tree*> sons;
};

void Check(Tree* leaf, uint32_t hop = 0)
{
	hop++;
	if (leaf->i == 1)
	{
		hop = 0;
		results.push_back(leaf->i);
	}
	else if (leaf->sons.size() >= m - 1 && hop > 1)
	{
		hop = 0;
		results.push_back(leaf->i);
	}
	else if (hop > 3)
	{
		hop = 0;
		results.push_back(leaf->i);
	}
	if (leaf->sons.size() == 0) return;
	for (auto iter : leaf->sons)
	{
		Check(iter, hop);
	}
}

int main()
{

	std::ios_base::sync_with_stdio(false);

	std::cin >> n >> m;

	//std::shared_ptr<Tree> root = std::make_shared<Tree>();
	Tree* root = new Tree;
	root->i = 1;

	{
		std::unordered_map<uint32_t,Tree*> leafs;

		//std::shared_ptr<Tree> currectLeaf = root;
		Tree* currectLeaf = root;
		uint32_t currectNumberOfLeaf = 1;


		uint32_t father, son;
		for (uint32_t i = 0; i < n - 1; i++)
		{
			std::cin >> father >> son;
			while (father != currectNumberOfLeaf)
			{
				currectLeaf = leafs[father];
				currectNumberOfLeaf = father;
				leafs.erase(father);
			}

			//std::shared_ptr<Tree> tmp = std::make_shared<Tree>();
			Tree* tmp = new Tree;
			tmp->i = son;
			currectLeaf->sons.push_back(tmp);
			leafs[son] = tmp;
		}
	}


	Check(root);
	std::sort(results.begin(), results.end());
	std::for_each(results.begin(), results.end(), [](uint32_t i) {std::cout << i << " "; });


	return 0;
}