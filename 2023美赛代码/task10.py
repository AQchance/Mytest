import pandas as pd

data = pd.read_excel('C_data_有效属性.xlsx')

print(data)

min = 1000000
max = 0

for i in range(0,356):
    num = data.iloc[i][3]
    if max < num:
        max = num
    if min > num:
        min = num
print(max)
print(min)