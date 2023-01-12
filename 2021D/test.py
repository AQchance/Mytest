import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
# 模拟数据
data = {'name': ['Alice', 'Bob', 'Charlie'],
        'age': [25, 30, 35],
        'gender': ['F', 'M', 'M']}

# 将数据转换为DataFrame
df = pd.DataFrame(data)

# 绘制表格
sns.set(font_scale=1.5)
sns.set_style("whitegrid")
sns.boxplot(data=df, width=0.5)

# 显示表格
plt.show()
