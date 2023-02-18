import wordcloud
import matplotlib.pyplot as plt
import pandas as pd

data=pd.read_excel("C_data.xlsx")


words = []
weights = []

for i in range(0,356):
    sum=0
    for j in range(5,11):
        sum+=(11-j)*data.iloc[i][j]/100
        #noun_score.append(data.iloc[i][2])
        words.append(data.iloc[i][2])
        weights.append(sum)

# 将单词和权重打包成一个字典
word_freq = dict(zip(words, weights))

# 创建WordCloud对象，并设置字体大小范围
wc = wordcloud.WordCloud(width=800, height=800, background_color='white', colormap='viridis', max_font_size=200, min_font_size=10)

# 使用generate_from_frequencies方法生成词云图
wc.generate_from_frequencies(word_freq)

# 绘制词云图
plt.figure(figsize=(8, 8), facecolor=None)
plt.imshow(wc)
plt.axis("off")
plt.tight_layout(pad=0)
plt.show()
