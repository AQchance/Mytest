import pandas as pd
import csv
influence = pd.read_csv("/home/anqian/桌面/2021D/2021D/influence_data.csv")

# 使用字典来存储每个音乐家的风格
styledc = {}
# 使用字典来存储每个音乐家出道的
yeardc = {}
for i in range(0, 42770):
    styledc.update({influence.iloc[i][1]: influence.iloc[i][2]})
    styledc.update({influence.iloc[i][5]: influence.iloc[i][6]})
    yeardc.update({influence.iloc[i][1]: influence.iloc[i][3]})
    yeardc.update({influence.iloc[i][5]: influence.iloc[i][7]})

year = []
for item in yeardc:
    if yeardc[item] not in year:
        year.append(yeardc[item])
year.sort()

classification = []
for item in styledc:
    if styledc[item] not in classification:
        classification.append(styledc[item])

mydc = []

for item1 in classification:
    for item2 in year:
        tmp = {}
        tmp.update({item2:0})
        for item3 in yeardc:
            if yeardc[item3]==item2 and styledc[item3]==item1:
                # 我们找到了特定流派在特定年份的艺术家
                tmp[item2]+=1
        tmp1 = []
        tmp1.append(item1)
        tmp1.append(tmp)
        mydc.append(tmp1)

mydata = []

for item1 in mydc:
    tmp = []
    tmp.append(item1[0])
    for item2 in item1[1]:
        tmp.append(item2)
        tmp.append(item1[1][item2])
    mydata.append(tmp)

f = open("output2.csv", "w", newline="")
writer = csv.writer(f)
for row in mydata:
    writer.writerow(row)
f.close()