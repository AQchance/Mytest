# 导入相关包
import numpy as np                  
import pandas as pd                 
import seaborn as sns
from pandas import plotting         
from sklearn import datasets        
import matplotlib.pyplot as plt     
from sklearn.linear_model import LogisticRegression 
from sklearn.model_selection import train_test_split
from sklearn import tree
from sklearn.tree import DecisionTreeClassifier 
iris_data2 = pd.read_csv('/home/anqian/iris_nan2.csv')      
#sns.pairplot(iris_data2, hue='class')  # 查看散点矩阵图
#plt.show()
my_values = iris_data2[['sepal_length', 'sepal_width',		    
                             'petal_length', 'petal_width']].values	
my_classes = iris_data2['class'].values
(training_inputs, test_inputs, training_classes, 
 test_classes) = train_test_split(my_values, my_classes, train_size=0.75)	    #划分训练集，其中训练集与测试集采用了3:1的比例划分

decision_tree_classifier = DecisionTreeClassifier()				    
decision_tree_classifier.fit(training_inputs, training_classes)			    #创建决策树

text_representation = tree.export_text(decision_tree_classifier)		    #按文本输出可视化决策树
print(text_representation)
print('Score:',decision_tree_classifier.score(test_inputs, test_classes))

fig = plt.figure(figsize=(25,20))
_ = tree.plot_tree(
    decision_tree_classifier, 
    feature_names='petal_width',  
    class_names='class',
    filled=True
)
# 将可视化输出的图片保存
#fig.savefig("/home/anqian/decistion_tree3.png")

