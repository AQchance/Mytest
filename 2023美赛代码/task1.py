import pandas as pd
import numpy as np

data = pd.read_excel("C_data.xlsx")

noun_array = ['robot', 'light', 'mount', 'skill', 'month', 'chest', 'stair', 'story', 'homer', 'metal']
verb_array = ['crimp', 'shake', 'allow', 'shown', 'delve', 'crept', 'blown', 'sever', 'smear', 'woven']
noun_score = []
verb_score = []


for i in range(0,359):
    if data.iloc[i][2] in noun_array:
        sum=0
        for j in range(5,11):
            sum+=(11-j)*data.iloc[i][j]/100
        #noun_score.append(data.iloc[i][2])
        noun_score.append(sum)
    if data.iloc[i][2] in verb_array:
        sum=0
        for j in range(5,11):
            sum+=(11-j)*data.iloc[i][j]/100
        #verb_score.append(data.iloc[i][2])
        verb_score.append(sum)

print(noun_score)
print(verb_score)

print("名词的平均得分为：", np.mean(noun_score))
print("动词的平均得分为：", np.mean(verb_score))
