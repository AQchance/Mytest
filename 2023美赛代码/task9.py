import pandas as pd
import csv

data = pd.read_excel("C_data_有效属性.xlsx")

max = 0
min = 10
mydata=[]
for i in range(0,356):
    tmp=[]
    num = data.iloc[i][17]
    if num>3:
        tmp.append(1)   # 1代表难度为简单
    elif num>2 and num<=3:
        tmp.append(2)   # 2代表难度为普通
    elif num<=2:
        tmp.append(3)   # 3代表难度为困难
    mydata.append(tmp)

f = open("output3.csv",'w',newline='')
writer = csv.writer(f)
for row in mydata:
    writer.writerow(row)
f.close()