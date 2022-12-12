import pandas as pd
from sklearn import preprocessing
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn import metrics
#读数据
data=pd.read_csv('/home/anqian/iris_nan2.csv')

my_classes=data['class'].values
my_values=data[['sepal_length','sepal_width','petal_length','petal_width']].values
(training_inputs, test_inputs, training_classes, 
test_classes) = train_test_split(my_values, my_classes, train_size=0.75)	#划分训练集和测试集
    
#创建贝叶斯分类模型
gnb=GaussianNB()
gnb.fit(training_inputs,training_classes)

classes_pred=gnb.predict(test_inputs)
#输出准确率
print('预测准确率:',metrics.accuracy_score(test_classes,classes_pred))


