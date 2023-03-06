import pandas as pd
import csv

data = pd.read_excel("C_data_有效属性2.xlsx")

max = 0
min = 10
mydata=[]

cnt1=0
cnt2=0
cnt3=0
cnt4=0
for i in range(0,355):
    tmp=[]
    num = data.iloc[i][17]
    if num>3.2:
        cnt1+=1
        tmp.append(1)   # 1代表难度为简单
    elif num>2.7 and num<=3.2:
        cnt2+=1
        tmp.append(2)   # 2代表难度为普通
    elif num<=2.7 and num>2.2:
        cnt3+=1
        tmp.append(3)   # 3代表难度为困难
    elif num<=2.2:
        cnt4+=1
        tmp.append(4)   # 4代表超困难
    mydata.append(tmp)

print(cnt1)
print(cnt2)
print(cnt3)
print(cnt4)
f = open("output4.csv",'w',newline='')
writer = csv.writer(f)
for row in mydata:
    writer.writerow(row)
f.close()