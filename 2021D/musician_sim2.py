import pandas as pd
import math
import csv
from numpy import *

data = pd.read_csv('data2.csv')
mydata = pd.read_csv('data4.csv')

# 对所有特征的值进行归一化处理

def handle(list, index):
    max = -1000
    min = 1000
    for row in list:
        if max < row[index]:
            max = row[index]
        if min > row[index]:
            min = row[index]
    for row in list:
        if max==min:
            row[index]=1
            continue
        row[index] = (row[index]-min)/(max-min)

# 计算两个向量的欧几里得相似度


def calculateSe(list1, list2):
    result = 0
    for i in (0, len(list1)-1):
        result += (list1[i]-list2[i])*(list1[i]-list2[i])
    result = math.sqrt(result)
    result = 1/(1+result)
    return result

# 计算两个向量的余弦相似度


def calculateScos(list1, list2):
    a1 = 0
    a2 = 0
    a3 = 0
    for i in range(0, len(list1)-1):
        a1 += list1[i]*list1[i]
        a2 += list2[i]*list2[i]
        a3 += list1[i]*list2[i]
    return a3/(math.sqrt(a1)*math.sqrt(a2))


# 使用字典来存储每个音乐家的风格
data1 = []
data2 = []
data3 = []
for i in range(0, 16):
    tmp = []
    for j in range(2, 13):
        tmp.append(data.iloc[i][j])
    data1.append(tmp)
for i in range(16, 29):
    tmp = []
    for j in range(2, 13):
        tmp.append(data.iloc[i][j])
    data2.append(tmp)
for i in range(32, 50):
    tmp = []
    for j in range(2, 13):
        tmp.append(mydata.iloc[i][j])
    data3.append(tmp)

# 把特征做归一化处理
for i in range(2, 11):
    handle(data1, i)
    handle(data2, i)
    handle(data3, i)

Se1 = []
Se2 = []
Scos1 = []
Scos2 = []
mydata = []
for row1 in data1:
    for row2 in data2:
        Se1.append(calculateSe(row1, row2))
        Scos1.append(calculateScos(row1, row2))
for row1 in data3:
    for row2 in data2:
        Se2.append(calculateSe(row1, row2))
        Scos2.append(calculateScos(row1, row2))

myse1 = mean(Se1)
myse2 = mean(Se2)
mycos1 = mean(Scos1)
mycos2 = mean(Scos2)
mycos1 = (mycos1+1)/2
mycos2 = (mycos2+1)/2

result1 = 0.7 * myse1 + 0.3 * mycos1
result2 = 0.7 * myse2 + 0.3 * mycos2
print("受影响相似度结果为：", result1)
print("不受影响的相似度为：", result2)