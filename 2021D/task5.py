import pandas as pd

music = pd.read_csv("/home/anqian/桌面/2021D/2021D/full_music_data.csv")
influence = pd.read_csv("/home/anqian/桌面/2021D/2021D/influence_data.csv")

# 找出特定的年代的歌曲，把这些歌曲的作家的名字添加到列表中
year = 1960
namelist = []
for i in range(0, 98340):
    if music.iloc[i][16] >= year-5 and music.iloc[i][16] <= year+5:
        name = music.iloc[i][0]
        name = name.strip("'[]'")
        name = name.strip('""')
        if name not in namelist:
            namelist.append(name)

number_of_followers = {}

for item in namelist:
    number_of_followers.update({item: 0})
for i in range(0,42770):
    if influence.iloc[i][1] in number_of_followers:
        number_of_followers[influence.iloc[i][1]]+=1

mydata= []
for item in number_of_followers:
    data=[]
    data.append(item)
    data.append(number_of_followers[item])
    mydata.append(data)

for i in range(0,len(mydata)):
    k=i
    for j in range(i+1,len(mydata)):
        if mydata[k][1] < mydata[j][1]:
            k=j
    mydata[k],mydata[i]=mydata[i],mydata[k]

for item in mydata:
    print(item[0],"的追随者数量为：",item[1])
    
