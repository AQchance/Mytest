import pandas as pd
import math
import csv
from numpy import *
music = pd.read_csv("/home/anqian/桌面/2021D/2021D/full_music_data.csv")
influence = pd.read_csv("/home/anqian/桌面/2021D/2021D/influence_data.csv")

# 使用字典来存储每个音乐家的风格
styledc = {}
for i in range(0, 42770):
    styledc.update({influence.iloc[i][1]: influence.iloc[i][2]})
    styledc.update({influence.iloc[i][5]: influence.iloc[i][6]})

Jazz_data = []
for i in range(0, 98340):
    name = music.iloc[i][0]
    name = name.strip('["]')
    name = name.strip("'")
    if name in styledc and styledc[name] == 'Comedy/Spoken':
        tmp = []
        for j in range(2, 13):
            tmp.append(music.iloc[i][j])
        Jazz_data.append(tmp)

Country_data = []
for i in range(0, 98340):
    name = music.iloc[i][0]
    name = name.strip('["]')
    name = name.strip("'")
    if name in styledc and styledc[name] == "Electronic":
        tmp = []
        for j in range(2, 13):
            tmp.append(music.iloc[i][j])
        Country_data.append(tmp)

def handle(list, index):
    max=-1000
    min=1000
    for row in list:
        if max<row[index]:
            max=row[index]
        if min>row[index]:
            min=row[index]
    for row in list:
        row[index]=(row[index]-min)/(max-min)

for i in range(2,11):
    handle(Jazz_data, i)
    handle(Country_data, i)
Se = []
Scos = []

def calculateSe(list1, list2):
    result = 0
    for i in (0, len(list1)-1):
        result += (list1[i]-list2[i])*(list1[i]-list2[i])
    result = math.sqrt(result)
    result = 1/(1+result)
    return result


def calculateScos(list1, list2):
    a1 = 0
    a2 = 0
    a3 = 0
    for i in range(0, len(list1)-1):
        a1 += list1[i]*list1[i]
        a2 += list2[i]*list2[i]
        a3 += list1[i]*list2[i]
    return a3/(math.sqrt(a1)*math.sqrt(a2))

mydata = []
for row1 in Jazz_data:
    for row2 in Country_data:
        Se.append(calculateSe(row1, row2))
        Scos.append(calculateScos(row1, row2))

myse = mean(Se)
mycos = mean(Scos)

mycos = (mycos+1)/2

result = 0.7 * myse + 0.3 * mycos
print("综合的相似度结果为：", result)