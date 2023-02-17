#include <bits/stdc++.h>
#include <fstream>
#include <time.h>

using namespace std;

//改善思路为想法2，使用A*算法，改善性能

const size_t MAX_Point_Number = 87575;
const size_t MAX_Edge_Number = 125000;
const double eps = 1e-6;
class Point {
private:
	int x;
	int y;
	int num;
public:
	Point() {}
	Point(int xa, int ya, int numa) :x(xa), y(ya), num(numa) {
	}
	int getx() const { return x; }
	int gety() const { return y; }
	int getnum() const { return num; }
	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }
	void setnum(int num) { this->num = num; }
	double dist(Point p1) {
		int x2 = (p1.getx() - x) * (p1.getx() - x);
		int y2 = (p1.gety() - y) * (p1.gety() - y);
		return sqrt(x2 + y2);
	}
};
//创建边的数据结构
/*class Edge {
private:
	int from;
	int to;
public:
	Edge(int f, int t) :from(f), to(t) {};
	int getfrom() const { return from; }
	int getto() const { return to; }
	double dist(Point p1, Point p2) {
		int x2 = (p1.getx() - p2.getx()) * (p1.getx() - p2.getx());
		int y2 = (p1.gety() - p2.gety()) * (p1.gety() - p2.gety());
		return sqrt(x2 + y2);
	}
};*/

//定义一些必要的数据结构

typedef struct LI {
	Point p;
	struct LI* next;
}ListNode;

class MyDist {
public:
	int number;
	double dist;
};

//用于优先队列的比价函数
struct cmp
{
	bool operator()(MyDist a, MyDist b) {
		return a.dist > b.dist;
	}
};

void ChangeDist(priority_queue<MyDist, vector<MyDist>, cmp>& pq, MyDist md) {
	vector<MyDist> vec;
	bool flag = false;
	while (!pq.empty()) {
		if (md.number != pq.top().number) {
			vec.push_back(pq.top());
			pq.pop();
		}
		else {
			flag = true;
			pq.pop();
			vec.push_back(md);
			break;
		}
	}
	if (!flag) {
		vec.push_back(md);
	}
	for (int i = 0; i < vec.size(); i++) {
		pq.push(vec[i]);
	}
}



ListNode* L[MAX_Point_Number];
double dist[MAX_Point_Number];
bool used[MAX_Point_Number];


void calculate(int start, int x) {
	set<int> myset;		//用于结果路径的输出
	double sum = 0;
	int i = start;
	int cnt = 0;
	//创建优队列
	priority_queue<MyDist, vector<MyDist>, cmp> pq;
	MyDist md;
	md.dist = 0.0;
	md.number = start;
	pq.push(md);
	while (!pq.empty()) {
		MyDist disttmp = pq.top();
		pq.pop();
		i = disttmp.number;
		used[i] = true;
		if (i == x) break;
		ListNode* tmp;
		for (tmp = L[i]->next; tmp != NULL; tmp = tmp->next) {
			int n = tmp->p.getnum();
			if (used[n]) continue;

			//下面使用A*算法来进行优化
			MyDist disttmp1;
			dist[n] = min(dist[i] + L[i]->p.dist(tmp->p), dist[n]);
			if (dist[n] > dist[i] + L[i]->p.dist(tmp->p))
				//如果需要更新距离，就将优先队列中的距离数据更新为如下内容
				disttmp1.dist = dist[i] + L[i]->p.dist(tmp->p);
				//disttmp1.dist = dist[i] + L[i]->p.dist(tmp->p) + L[n]->p.dist(L[x]->p) - L[i]->p.dist(L[i]->p);
			else
				disttmp1.dist = dist[n];
			disttmp1.number = n;
			ChangeDist(pq, disttmp1);
		}
	}
	cout << "最短路径为：" << dist[x] << endl;
}

int main()
{
	int ex;
	cout << "请输入：" << endl;
	while (1) {
		memset(dist, 0x42, sizeof(dist));
		memset(used, false, sizeof(used));
		int n, v, e, x, y, num, m;
		/*
		输入文件中的内容
		*/
		ifstream in("C:\\Users\\lenovo\\Desktop\\usa.txt", ios::in);
		if (!in.is_open())
		{
			cerr << "open error!" << endl;
			exit(0);
		}
		in >> v >> e;
		for (int i = 0; i < v; i++) {
			in >> num >> x >> y;
			L[i] = new ListNode;
			L[i]->next = NULL;
			L[i]->p.setnum(num);
			L[i]->p.setx(x);
			L[i]->p.sety(y);
		}
		for (int i = 0; i < e; i++) {
			in >> x >> y;
			ListNode* tmp1 = new ListNode;
			ListNode* tmp2;
			tmp1->next = NULL;
			tmp1->p = L[y]->p;
			for (tmp2 = L[x]; tmp2->next != NULL; tmp2 = tmp2->next) {
			}
			tmp2->next = tmp1;
			ListNode* tmp3 = new ListNode;
			ListNode* tmp4;
			tmp3->next = NULL;
			tmp3->p = L[x]->p;
			for (tmp4 = L[y]; tmp4->next != NULL; tmp4 = tmp4->next) {
			}
			tmp4->next = tmp3;
		}
		vector<int> a;
		cout << "请输入起点和终点：" << endl;
		cin >> m >> n;
		dist[m] = 0.0;
		clock_t time_start, time_end;
		time_start = clock();
		calculate(m, n);
		time_end = clock();
		/*cout << "最短路径顺序为：" << endl;
		for (int i = a.size() - 1; i >= 0; i--) {
			cout << a[i];
			if (i > 0)
				cout << "-->";
			else
				cout << endl;
		}*/
		cout << "本次最短路径计算耗时为：" << (time_end - time_start) * 1000 / CLOCKS_PER_SEC <<"ms" << endl;
		cout << "输入0以结束输入，输入1继续" << endl;
		cin >> ex;
		if (ex == 0) {
			cout << "结束输入！" << endl;
			return 0;
		}
		else {
			cout << "请继续输入:" << endl;
		}
	}
	return 0;
}
