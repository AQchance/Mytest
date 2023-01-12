import pandas as pd
import csv
import matplotlib.pyplot as plt
music = pd.read_csv("/home/anqian/桌面/2021D/2021D/full_music_data.csv")
influence = pd.read_csv("/home/anqian/桌面/2021D/2021D/influence_data.csv")

# 使用字典来存储每个音乐家的风格
styledc = {}
for i in range(0, 42770):
    styledc.update({influence.iloc[i][1]: influence.iloc[i][2]})
    styledc.update({influence.iloc[i][5]: influence.iloc[i][6]})

data = []

for i in range(0, 98340):
    name = music.iloc[i][0]
    name = name.strip('["]')
    name = name.strip("'")
    if name in styledc and styledc[name] == 'Blues':
        tmp = []
        for j in range(2,13):
            tmp.append(music.iloc[i][j])
        tmp.append(music.iloc[i][15])
        tmp.append(music.iloc[i][16])
        data.append(tmp)

year = []
mydata=[]
for i in range(0,len(data)):
    if data[i][12] in year:
        continue
    else:
        year.append(data[i][12])
for i in range(0,len(year)):
    cnt=0
    c=[0,0,0,0,0,0,0,0,0,0,0,0]
    c.append(year[i])
    for j in range(0,len(data)):
        if data[j][12]==year[i]:
            cnt+=1
            for k in range (0,12):
                c[k]+=data[j][k]
    for k in range(0,12):
        c[k]/=cnt
    mydata.append(c)

# 对年份进行排序
for i in range(0,len(mydata)):
    k=i
    for j in range(i+1,len(mydata)):
        if mydata[k][12] > mydata[j][12]:
            k=j
    mydata[k],mydata[i]=mydata[i],mydata[k]

x= []
y = []

# 控制输出的属性
for row in mydata:
    x.append(row[12])
    y.append(row[7])
plt.plot(x, y)
plt.show()

# f = open("output.csv", "w", newline="")
# writer = csv.writer(f)
# for row in mydata:
#     writer.writerow(row)
# f.close()