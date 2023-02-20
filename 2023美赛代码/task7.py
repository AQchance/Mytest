import pandas as pd
import csv

data=pd.read_excel("C_data.xlsx")

use=['a', 'o', 'i', 'e', 'u']

mydata=[]
for i in range(0,356):
    cnt=0
    tmp=[]
    word = data.iloc[i][2]
    for ch in word:
        if ch in use:
            cnt+=1
    tmp.append(cnt)
    mydata.append(tmp)

f = open("output2.csv", "w", newline="")
writer = csv.writer(f)
for row in mydata:
    writer.writerow(row)
f.close()         


