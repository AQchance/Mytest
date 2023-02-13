#include <iostream>
#include <utility>
#include <random>
#include <array>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <time.h>
#include<memory>

using namespace std;

const size_t blocks_size = 200;						   // 用200*200的网格模拟渗透
array<array<bool, blocks_size>, blocks_size> blocks{};
unsigned seed = 0x89e351ef534eu;					   // 固定的随机数种子，以便于复现结果
default_random_engine random_engine{ seed };
uniform_int_distribution<int> random_generator{ 0, blocks_size - 1 };	//采取均匀分布的随机方式

class union_find_set
{
	unique_ptr<int[]> parents;		//使用智能指针定义数组表示网格
	unique_ptr<int[]> treesize;
public:
	union_find_set(size_t size)
		: parents(new int[size]),treesize(new int[size])
	{
		for (size_t i = 0; i < size; i++)
			parents[i] = i;
		for (size_t i = 0; i < size; i++) {
			treesize[i] = 1;
		}
	}
	int find(int i)
	{
		while (i != parents[i]) {
			i = parents[i];
		}
		return i;
	}
	void connect(int i, int j)
	{
		int x = find(i);
		int y = find(j);
		if (treesize[x] < treesize[y]) {
			parents[x] = parents[y];
			treesize[y] += treesize[x];
		}
		else {
			parents[y] = parents[x];
			treesize[x] += treesize[y];
		}
		
	}
	bool is_connected(int i, int j)
	{
		return find(i) == find(j);
	}
};
double simulate()
{
	auto calculate_index = [](int row, int col)
	{ return row * blocks_size + col; };
	blocks.fill(array<bool, blocks_size>{});		//填充网格
	union_find_set ufs{ blocks_size * blocks_size + 2 };
	int first = blocks_size * blocks_size;
	int last = first + 1;
	for (size_t i = 0; i < blocks_size; i++)
	{
		ufs.connect(first, calculate_index(0, i));
		ufs.connect(last, calculate_index(blocks_size - 1, i));
	}

	size_t space_count = 0;
	while (!ufs.is_connected(first, last))
	{
		bool flag = true;
		do
		{
			int row = random_generator(random_engine);
			int col = random_generator(random_engine);
			if (!blocks[row][col])
			{
				flag = false;
				space_count++;
				blocks[row][col] = true;
				if (row > 0 && blocks[row - 1][col])
					ufs.connect(calculate_index(row, col), calculate_index(row - 1, col));
				if (col > 0 && blocks[row][col - 1])
					ufs.connect(calculate_index(row, col), calculate_index(row, col - 1));
				if (row < blocks_size - 1 && blocks[row + 1][col])
					ufs.connect(calculate_index(row, col), calculate_index(row + 1, col));
				if (col < blocks_size - 1 && blocks[row][col + 1])
					ufs.connect(calculate_index(row, col), calculate_index(row, col + 1));
			}
		} while (flag);
	}
	return static_cast<double>(space_count) / (200 * 200);
}
int main(void)
{
	const size_t n = 200;
	clock_t start, end;
	start = clock();
	for (size_t i = 0; i < n; i++) {
		cout << simulate() << endl;
	}
	end = clock();
	cout << "总耗时：" << (end - start) / CLOCKS_PER_SEC << "秒" << endl;
	return 0;
}