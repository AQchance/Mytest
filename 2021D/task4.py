import pandas as pd
import math
import csv
from numpy import *

data = pd.read_csv('d1.csv')
mydata = pd.read_csv('d2.csv')
namelist = ['danceability', 'energy', 'valence', 'tempo', 'loudness', 'mode',
            'key', 'acousticness', 'instrumentalness', 'liveness', 'speechiness']

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
        if max == min:
            row[index] = 1
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

# 计算缺失特征后向量的余弦相似度


def mycalculateScos(list1, list2, index):
    a1 = 0
    a2 = 0
    a3 = 0
    for i in range(0, len(list1)-1):
        if i == index:
            continue
        a1 += list1[i]*list1[i]
        a2 += list2[i]*list2[i]
        a3 += list1[i]*list2[i]
    return a3/(math.sqrt(a1)*math.sqrt(a2))

# 计算缺失特征后向量的欧几里得相似度


def mycalculateSe(list1, list2, index):
    result = 0
    for i in (0, len(list1)-1):
        if i == index:
            continue
        result += (list1[i]-list2[i])*(list1[i]-list2[i])
    result = math.sqrt(result)
    result = 1/(1+result)
    return result


data1 = []
data2 = []
data3 = []

# data1中存储披头士乐队的音乐特征
for i in range(0, 491):
    tmp = []
    for j in range(2, 13):
        tmp.append(data.iloc[i][j])
    data1.append(tmp)

# data2中存储披头士乐队的追随者的音乐特征
for i in range(0, 164):
    tmp = []
    for j in range(2, 13):
        tmp.append(mydata.iloc[i][j])
    data2.append(tmp)

# 把特征做归一化处理
for i in range(0, 11):
    handle(data1, i)
    handle(data2, i)

Se1 = []
Scos1 = []
for row1 in data1:
    for row2 in data2:
        Se1.append(calculateSe(row1, row2))
        Scos1.append(calculateScos(row1, row2))

myse1 = mean(Se1)
mycos1 = mean(Scos1)
mycos1 = (mycos1+1)/2
result1 = 0.7 * myse1 + 0.3 * mycos1
print("未缺失特征的相似度为：", result1)
for i in range(0, len(namelist)):
    Se = []
    Scos = []
    for row1 in data1:
        for row2 in data2:
            Se.append(mycalculateSe(row1, row2, i))
            Scos.append(mycalculateScos(row1, row2, i))
    myse = mean(Se)
    mycos = mean(Scos)
    mycos = (mycos+1)/2
    result = 0.7 * myse + 0.3 * mycos
    print('缺失',namelist[i],'后的相似度为：',result)