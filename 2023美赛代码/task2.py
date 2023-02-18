import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# 字母频率

data = pd.read_excel("C_data.xlsx")

word_array = ['panic', 'sugar', 'pleat', 'cynic', 'bloke', 'cloth', 'cater', 'epoxy', 'natal', 'shame']
frequency = {}
score = {}

frequency_dic = {"a":0.08167, "b":0.01492, "c": 0.02782, "d":0.04253, "e":0.12702, 
"f":0.02228, "g":0.02015, "h":0.06094, "i":0.06966, "j":0.00153, "k":0.00772, "l":0.04025,
"m":0.02406, "n":0.06749, "o":0.07507, "p":0.01929, "q":0.00095, "r":0.05987, "s":0.06372, 
"t":0.09056, "u":0.02758, "v":0.00978, "w":0.02360, "x":0.00150, "y":0.01974, "z":0.00074}

for i in range(0,359):
    if data.iloc[i][2] in word_array:
        sum=0
        for ch in data.iloc[i][2]:
            sum+=frequency_dic[ch]
        frequency.update({data.iloc[i][2]:sum})
        sum=0
        for j in range(5,11):
            sum+=(11-j)*data.iloc[i][j]/100
        #noun_score.append(data.iloc[i][2])
        score.update({data.iloc[i][2]:sum})

print("字母频率的计算结果为：")
frequency = dict(sorted(frequency.items(), key = lambda kv:kv[1]))
print(frequency)
print("单词得分的计算结果为：")
score = dict(sorted(score.items(), key = lambda kv:kv[1]))
print(score)

x1 = []
y1 = []
for item in frequency:
    x1.append(item)
    y1.append(frequency[item])
x2 = []
y2 = []
for item in frequency:
    x2.append(item)
    y2.append(score[item])

fig, ax = plt.subplots()
# 绘制折线图
ax.plot(x2, y2)

# 添加标题和坐标轴标签
ax.set_title('Plot1')
ax.set_xlabel('Words')
ax.set_ylabel('Letter Frequency')

# 显示图形
plt.show()

# fig.plot(x2, y2)

# # 添加标题和坐标轴标签
# fig.set_title('Plot2')
# fig.set_xlabel('Words')
# fig.set_ylabel('Score')

# plt.show()