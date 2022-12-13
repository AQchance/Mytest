//找位置
//hash表+拉链法
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
struct Node{
    char element;
    int positon;
};
vector<Node> Hash[125];  
//hash表，拉链法处理冲突（实现类似图的邻接矩阵）
//hash函数为直接定址：每个字符c对应的ASCII码，大小写字母的ASCII不超过125
//hash表的每个元素是一个变长数组(vector)，vector中存储结点Node（包含字符c以及对应的下标位置position）
bool Vis[125] = {false}; 
//标记数组：Vis[i] = true 表示在哈希表中映射为i的值已经被打印过，无需再打印
void FindPostion(char* s);  //找位置并按照题目要求输出
void InsertElement(char c, int position);  //将字符串中的字符插入hash表

int main(){
    char s[100];
    while(scanf("%s", s) != EOF){  //多点输入
        FindPostion(s);
    }
}

void FindPostion(char *s){
    int i,j,index,size;
    int length = strlen(s);
    for(i = 0; i < length; i++)  //将字符串s中的每个字符插入hash表
        InsertElement(s[i], i);
    
    for(i = 0; i < length; i++){
        index = s[i] - '0';  //直接定址：得到当前字符s[i]在hash表中的位置
        size = Hash[index].size();  //存储当前字符s[i]的变长数组的大小
        if(size > 1 && Vis[index] == false){ //size>1说明有s[i]有重复，Vis[]数组防止多次打印结果
            Vis[index] = true;  //标记，防止多次打印结果
            for(j = 0; j < size; j++){ //遍历vector[index]，打印结果
                if(j == size-1)
                    printf("%c:%d", Hash[index][j].element, Hash[index][j].positon);
                else
                    printf("%c:%d,", Hash[index][j].element, Hash[index][j].positon);
            }
            printf("\n");
        }
    }
}

void InsertElement(char c, int position){ //将字符c及其所在的位置存入hash表中
    Node n;
    n.element = c;
    n.positon = position;

    int index = c -'0';  //直接定址：得到当前字符s[i]在hash表中的位置
    Hash[index].push_back(n);  //插入
}
