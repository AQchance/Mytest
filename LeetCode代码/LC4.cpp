#include<bits/stdc++.h>

using namespace std;
//好一个O(log(m+n))复杂度的题啊，花了我接近六小时才搞出来，属实是不容易了
//这个题也让我开始时思考如何处理边界问题，因为大体的思路一点也不难想，但是边界问题就是很难处理
//还是要多积累经验
//OK废话不多说，开始注释了QwQ


//本题的基本思路是寻找到两个有序数组的从小到大的第k个数，k可以由中位数的条件求出
//O(log(m+n))基本都要选择进行二分，此题也不例外
int find_kth_number(vector<int> nums1, vector<int> nums2, int k) {
    int m = 0, n = 0;
    bool flag1 = false, flag2 = false;//用来检查越界与否
    int size1 = nums1.size(), size2 = nums2.size();//记录两个增长数组的大小
    if (size1 == 0) flag1 = true;
    if (size2 == 0) flag2 = true;//size为0时，由于没有数据，所以直接设置为数组出界
    while (k != 1) {//只要k≠1，我们就可以每次排除单个数组中的k/2个数据，它们都是一定比第k个数小的数
        if (m + k / 2 > size1) flag1 = true;
        else flag1 = false;//这里花了好久才想到的，true和false是相对的，会随着k的改变而改变
        if (n + k / 2 > size2) flag2 = true;//只要一个数组删掉k/2个数据后越界，那么就删除另一个数组的k/2个数据，这一定不会越界
        else flag2 = false;
        if (true==flag1) {
            n += k / 2;//flag1==true表示m越界，那么删掉n中的k/2个数据
        }
        else if (true == flag2) {
            m += k / 2;//同理于上
        }
        else {
            if (nums1[m + k / 2 - 1] < nums2[n + k / 2 - 1]) { //比较两个边界数的大小，小的数所对应的数组中理应被删掉k/2个数据
                m += k / 2;
                if (m == size1) flag1 = true;//如果m==size1，说明已经越界，在此处设置flag1=true是因为万一k=2，循环将结束，
                                             //flag的值将不会被改写，最后返回值的判定条件可能会失效
            }
            else {
                n += k / 2;
                if (n == size2) flag2 = true;//同上
            }
        }
        k = k - k / 2;//更新k值，以后每次写while都要先写上更新值，别忘了
    }
    if (true == flag1) return nums2[n];//nums1中的所有数据都被删光，所以直接返回nums2[n]即可
    else if (true == flag2) return nums1[m];//同理于上
    else return min(nums1[m], nums2[n]);//最后只剩下一个元素便是第k个元素，二者之中最小者便是我们要找的目标
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
}//这个函数没什么好注释的，就是对上一个函数的执行罢了，对应题目进行相应的操作

int main()
{
    vector<int> nums1, nums2;
    int m, n, j;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> j;
        nums1.push_back(j);//这个输入我一开始还用nums1[i]，才学到的原来要用push_back
    }
    for (int i = 0; i < n; i++) {
        cin >> j;
        nums2.push_back(j);
    }
    double result = findMedianSortedArrays(nums1, nums2);
    cout << result;
    return 0;
}