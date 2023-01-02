#include<bits/stdc++.h>

using namespace std;
//��һ��O(log(m+n))���Ӷȵ��Ⱑ�������ҽӽ���Сʱ�Ÿ��������ʵ�ǲ�������
//�����Ҳ���ҿ�ʼʱ˼����δ���߽����⣬��Ϊ�����˼·һ��Ҳ�����룬���Ǳ߽�������Ǻ��Ѵ���
//����Ҫ����۾���
//OK�ϻ�����˵����ʼע����QwQ


//����Ļ���˼·��Ѱ�ҵ�������������Ĵ�С����ĵ�k������k��������λ�����������
//O(log(m+n))������Ҫѡ����ж��֣�����Ҳ������
int find_kth_number(vector<int> nums1, vector<int> nums2, int k) {
    int m = 0, n = 0;
    bool flag1 = false, flag2 = false;//�������Խ�����
    int size1 = nums1.size(), size2 = nums2.size();//��¼������������Ĵ�С
    if (size1 == 0) flag1 = true;
    if (size2 == 0) flag2 = true;//sizeΪ0ʱ������û�����ݣ�����ֱ������Ϊ�������
    while (k != 1) {//ֻҪk��1�����ǾͿ���ÿ���ų����������е�k/2�����ݣ����Ƕ���һ���ȵ�k����С����
        if (m + k / 2 > size1) flag1 = true;
        else flag1 = false;//���ﻨ�˺þò��뵽�ģ�true��false����Եģ�������k�ĸı���ı�
        if (n + k / 2 > size2) flag2 = true;//ֻҪһ������ɾ��k/2�����ݺ�Խ�磬��ô��ɾ����һ�������k/2�����ݣ���һ������Խ��
        else flag2 = false;
        if (true==flag1) {
            n += k / 2;//flag1==true��ʾmԽ�磬��ôɾ��n�е�k/2������
        }
        else if (true == flag2) {
            m += k / 2;//ͬ������
        }
        else {
            if (nums1[m + k / 2 - 1] < nums2[n + k / 2 - 1]) { //�Ƚ������߽����Ĵ�С��С��������Ӧ����������Ӧ��ɾ��k/2������
                m += k / 2;
                if (m == size1) flag1 = true;//���m==size1��˵���Ѿ�Խ�磬�ڴ˴�����flag1=true����Ϊ��һk=2��ѭ����������
                                             //flag��ֵ�����ᱻ��д����󷵻�ֵ���ж��������ܻ�ʧЧ
            }
            else {
                n += k / 2;
                if (n == size2) flag2 = true;//ͬ��
            }
        }
        k = k - k / 2;//����kֵ���Ժ�ÿ��дwhile��Ҫ��д�ϸ���ֵ��������
    }
    if (true == flag1) return nums2[n];//nums1�е��������ݶ���ɾ�⣬����ֱ�ӷ���nums2[n]����
    else if (true == flag2) return nums1[m];//ͬ������
    else return min(nums1[m], nums2[n]);//���ֻʣ��һ��Ԫ�ر��ǵ�k��Ԫ�أ�����֮����С�߱�������Ҫ�ҵ�Ŀ��
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size(), size2 = nums2.size();
    if ((size1 + size2) % 2 != 0) {
        return find_kth_number(nums1, nums2, (size1 + size2) / 2 + 1);
    }
    else {
        double result;
        result = find_kth_number(nums1, nums2, (size1 + size2) / 2) + find_kth_number(nums1, nums2, (size1 + size2) / 2 + 1);
        return result / 2;
    }
}//�������ûʲô��ע�͵ģ����Ƕ���һ��������ִ�а��ˣ���Ӧ��Ŀ������Ӧ�Ĳ���

int main()
{
    vector<int> nums1, nums2;
    int m, n, j;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> j;
        nums1.push_back(j);//���������һ��ʼ����nums1[i]����ѧ����ԭ��Ҫ��push_back
    }
    for (int i = 0; i < n; i++) {
        cin >> j;
        nums2.push_back(j);
    }
    double result = findMedianSortedArrays(nums1, nums2);
    cout << result;
    return 0;
}