import pandas as pd
import math
import numpy as np
data = pd.read_excel("C_data_2.xlsx")
#print(data)

# max = 0
# min=1
# mydata = []
# for i in range(0,356):
#     num=data.iloc[i][7]
#     if num > max:
#         max = num
#     if num < min:
#         min = num
#     mydata.append(num)

# print(max)
# print(min)
# print(mydata)

newdata=[]
for i in range(0,356):
    tmp1 = []
    tmp2=[]
    tmp3=[]
    tmp4=[]
    item = data.iloc[i][7]
    if item <= 0.2:
        tmp=[]
        for j in range(10,17):
            tmp.append(data.iloc[i][j])
        tmp1.append(tmp)

    elif item > 0.2 and item <= 0.3:
        tmp=[]
        for j in range(10,17):
            tmp.append(data.iloc[i][j])
        tmp2.append(tmp)
    elif item >0.3 and item <= 0.4:
        tmp=[]
        for j in range(10,17):
            tmp.append(data.iloc[i][j])
        tmp3.append(tmp)
    elif item > 0.4:
        tmp=[]
        for j in range(10,17):
            tmp.append(data.iloc[i][j])
        tmp4.append(tmp)
for i in range(0,7):
    for j in range(0,len(tmp1)):
        sum+=tmp1[j][i]
        
# # 计算余弦相似度
# for i in range(0,4):
#     for j in range(i+1,4):
#         data1=[]
#         data2=[]
#         for k in range(1,8):
#             data1.append(data.iloc[i][k])
#             data2.append(data.iloc[j][k])
#         cos = 0
#         a2=0
#         b2=0
#         c=0
#         for k in range(0,7):
#             a2+=data1[k]*data1[k]
#             b2+=data2[k]*data2[k]
#             c+=data1[k]*data2[k]
#         cos = c/math.sqrt(a2*b2)
#         print(data.iloc[i][0], "数量级与", data.iloc[j][0], "数量级之间的余弦相似度为：",cos)
