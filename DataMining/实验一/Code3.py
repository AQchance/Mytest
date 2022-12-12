import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier

# 读取数据
data = pd.read_csv("/home/anqian/iris_nan2.csv")


# 取出数据当中的特征值和目标值
y = data['class']
x = data.drop(['class'], axis=1)


# 进行数据的分割训练集合测试集
(x_train, x_test, y_train, y_test) = train_test_split(x, y, train_size=0.75)  #创建训练集和测试集


# 标准化处理
std = StandardScaler()


# 对测试集和训练集的特征值进行标准化处理
x_train = std.fit_transform(x_train)
x_test = std.transform(x_test)


#创建KNN模型
knn = KNeighborsClassifier()
knn.fit(x_train, y_train)
y_predict = knn.predict(x_test)


#print("y_predict:", y_predict)
#输出预测的准确率
print("预测的准确率:", knn.score(x_test, y_test))
