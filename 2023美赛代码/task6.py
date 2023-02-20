import pandas as pd
import math
import numpy as np
data = pd.read_excel("C_data_3.xlsx")
# print(data)

max = 1
min = 0

# 计算余弦相似度
for i in range(0, 4):
    for j in range(i+1, 4):
        data1 = []
        data2 = []
        for k in range(1, 8):
            data1.append(data.iloc[i][k])
            data2.append(data.iloc[j][k])
        cos = 0
        a2 = 0
        b2 = 0
        c = 0
        for k in range(0, 7):
            a2 += data1[k]*data1[k]
            b2 += data2[k]*data2[k]
            c += data1[k]*data2[k]
        cos = math.sqrt(a2+b2)
        print(data.iloc[i][0], "与", data.iloc[j][0], "之间的相异度为：", cos)
