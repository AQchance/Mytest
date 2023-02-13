#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 10000;

int main()
{
	//读取数据文件
	ifstream in("simulate.txt", ios::in);
	if (!in.is_open())
	{
		cout << "open error!" << endl;
		exit(0);
	}
	//将数据文件数据存入数组
	int i = 0;
	vector<double> a(N);
	while (!in.eof() && i < N)
	{
		in >> a[i];
		i++;
	}
	double sum = 0;
	for (i = 0; i < N; i++) {
		sum += a[i];
	}
	double average = sum / N;
	double σ2 = 0;
	for (i = 0; i < N; i++) {
		σ2 += (a[i] - average) * (a[i] - average);
	}
	σ2 = σ2 / (N - 1);
	double σ = sqrt(σ2);
	cout << "平均值：" << average << endl;
	cout << "方差：" << σ2 << endl;
	cout << "标准差: " << σ << endl;
	cout << "置信区间: " << "[" << average - 1.96 * σ / sqrt(N) << ", "
		<< average + 1.96 * σ / sqrt(N) << "]" << endl;
	return 0;
}
