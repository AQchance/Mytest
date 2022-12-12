# 导入相关包
import numpy as np                  #矩阵计算
import pandas as pd                 #提供数据结构
import seaborn as sns					
from pandas import plotting         #画图&加载文件&生成文件
from sklearn import datasets        #数据处理
import matplotlib.pyplot as plt     #画图          
from sklearn.linear_model import LogisticRegression 	
from sklearn.model_selection import train_test_split	#用于划分训练集和测试集
from sklearn import tree		#生成文字可视化的决策树
from sklearn.tree import DecisionTreeClassifier #决策树包




#其中有一部分被注释掉的代码是在写代码过程中检测输出结果的


#加载数据
iris_data = pd.read_csv('/home/anqian/iris_nan1.csv',na_values=['NA'])   # 读取.csv文件并且把空值用Nan代替


print(iris_data)		#输出数据表
print(iris_data.describe())    # 检查四列数据的个数，平均数，标准差，最小值，最大值和25，50，75的百分位数


#sns.pairplot(iris_data.dropna(), hue="class")    # 画散点矩阵图sns.pairplot(iris_data.dropna())
#plt.show()

#查看 class=2 里sepal_length小于5.0厘米的数据，只有一个，下面将其删掉
#print(iris_data.loc[(iris_data['class'] == 2) & (iris_data['sepal_length'] < 5.0)])    
#print(iris_data.loc[iris_data['class'] == 2, 'sepal_length'].hist())

#删掉坏值
iris_data = iris_data.loc[(iris_data['class'] != 2) | (iris_data['sepal_length'] >= 5.0)]
iris_data = iris_data.loc[(iris_data['class'] != 0) | (iris_data['sepal_width'] >= 2.5)]


#sns.pairplot(iris_data.dropna(), hue="class")
# 画出其条形图
#iris_data.loc[iris_data['class'] == 0, 'sepal_length'].hist()
#plt.show()


# 查看所有NaN值
print(iris_data.loc[(iris_data['sepal_length'].isnull()) |
              (iris_data['sepal_width'].isnull()) |
              (iris_data['petal_length'].isnull()) |
              (iris_data['petal_width'].isnull())])


# 用平均值来代替NaN值
average_petal_width = iris_data.loc[iris_data['class'] == 1, 'petal_width'].mean()
average_petal_length = iris_data.loc[iris_data['class'] == 1, 'petal_length'].mean()
average_sepal_width = iris_data.loc[iris_data['class'] == 1, 'sepal_width'].mean()
average_sepal_length = iris_data.loc[iris_data['class'] == 1, 'sepal_length'].mean()
iris_data.loc[(iris_data['class'] == 1) &
              (iris_data['petal_width'].isnull()),
              'petal_width'] = average_petal_width
iris_data.loc[(iris_data['class'] == 1) &
              (iris_data['petal_length'].isnull()),
              'petal_length'] = average_petal_length
iris_data.loc[(iris_data['class'] == 1) &
              (iris_data['sepal_width'].isnull()),
              'sepal_width'] = average_sepal_width
iris_data.loc[(iris_data['class'] == 1) &
              (iris_data['sepal_length'].isnull()),
              'sepal_length'] = average_sepal_length
 
#将新的文件保存
iris_data.to_csv('/home/anqian/iris_nan2.csv', index = False)          
