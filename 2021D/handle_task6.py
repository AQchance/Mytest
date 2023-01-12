import pandas as pd
import matplotlib.pyplot as plt

data=pd.read_csv('output2.csv',header=None)

x=[]
y=[]
name='Electronic'
for i in range(0,180):
    if data.iloc[i][0]==name:
        x.append(data.iloc[i][1])
        y.append(data.iloc[i][2])
plt.plot(x,y)
plt.show()