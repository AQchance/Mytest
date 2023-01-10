import pandas as pd
import csv
#music = pd.read_csv("/home/anqian/桌面/2021D/2021D/full_music_data.csv")
influence = pd.read_csv("/home/anqian/桌面/2021D/2021D/influence_data.csv")

# 使用字典来存储每个音乐家的风格
styledc = {}
# for i in range(0, 42770):
#     styledc.update({influence.iloc[i][1]: influence.iloc[i][2]})
#     styledc.update({influence.iloc[i][5]: influence.iloc[i][6]})

# data = []

Jazz_dc = {}

for i in range (0,42770):
    if influence.iloc[i][2]=='Electronic':
        if influence.iloc[i][6] in Jazz_dc:
            Jazz_dc[influence.iloc[i][6]]+=1
        else:
            Jazz_dc.update({influence.iloc[i][6]:1})

mydata = []

for item in Jazz_dc:
    tmp=[]
    tmp.append(item)
    tmp.append(Jazz_dc[item])
    mydata.append(tmp)
print (mydata)

f = open("Electronic_influence.csv", "w", newline="")
writer = csv.writer(f)
for row in mydata:
    writer.writerow(row)
f.close()