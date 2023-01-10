import pandas as pd
import csv
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
    if name in styledc and styledc[name] == 'Jazz':
        tmp = []
        for j in range(2,6):
            tmp.append(music.iloc[i][j])
        tmp.append(music.iloc[i][16])
        data.append(tmp)

year = []
mydata=[]
for i in range(0,len(data)):
    if data[i][4] in year:
        continue
    else:
        year.append(data[i][4])
for i in range(0,len(year)):
    cnt=0
    c=[0,0,0,0]
    c.append(year[i])
    for j in range(0,len(data)):
        if data[j][4]==year[i]:
            cnt+=1
            c[0]+=data[j][0]
            c[1]+=data[j][1]
            c[2]+=data[j][2]
            c[3]+=data[j][3]
    for k in range(0,4):
        c[k]/=cnt
    mydata.append(c)
print(mydata)
f = open("output.csv", "w", newline="")
writer = csv.writer(f)
for row in mydata:
    writer.writerow(row)
f.close()