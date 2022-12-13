//��λ��
//hash��+������
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
struct Node{
    char element;
    int positon;
};
vector<Node> Hash[125];  
//hash�������������ͻ��ʵ������ͼ���ڽӾ���
//hash����Ϊֱ�Ӷ�ַ��ÿ���ַ�c��Ӧ��ASCII�룬��Сд��ĸ��ASCII������125
//hash���ÿ��Ԫ����һ���䳤����(vector)��vector�д洢���Node�������ַ�c�Լ���Ӧ���±�λ��position��
bool Vis[125] = {false}; 
//������飺Vis[i] = true ��ʾ�ڹ�ϣ����ӳ��Ϊi��ֵ�Ѿ�����ӡ���������ٴ�ӡ
void FindPostion(char* s);  //��λ�ò�������ĿҪ�����
void InsertElement(char c, int position);  //���ַ����е��ַ�����hash��

int main(){
    char s[100];
    while(scanf("%s", s) != EOF){  //�������
        FindPostion(s);
    }
}

void FindPostion(char *s){
    int i,j,index,size;
    int length = strlen(s);
    for(i = 0; i < length; i++)  //���ַ���s�е�ÿ���ַ�����hash��
        InsertElement(s[i], i);
    
    for(i = 0; i < length; i++){
        index = s[i] - '0';  //ֱ�Ӷ�ַ���õ���ǰ�ַ�s[i]��hash���е�λ��
        size = Hash[index].size();  //�洢��ǰ�ַ�s[i]�ı䳤����Ĵ�С
        if(size > 1 && Vis[index] == false){ //size>1˵����s[i]���ظ���Vis[]�����ֹ��δ�ӡ���
            Vis[index] = true;  //��ǣ���ֹ��δ�ӡ���
            for(j = 0; j < size; j++){ //����vector[index]����ӡ���
                if(j == size-1)
                    printf("%c:%d", Hash[index][j].element, Hash[index][j].positon);
                else
                    printf("%c:%d,", Hash[index][j].element, Hash[index][j].positon);
            }
            printf("\n");
        }
    }
}

void InsertElement(char c, int position){ //���ַ�c�������ڵ�λ�ô���hash����
    Node n;
    n.element = c;
    n.positon = position;

    int index = c -'0';  //ֱ�Ӷ�ַ���õ���ǰ�ַ�s[i]��hash���е�λ��
    Hash[index].push_back(n);  //����
}
