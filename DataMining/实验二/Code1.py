import pandas as pd
import numpy as np
from  sklearn.decomposition import PCA
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn import metrics		#导入各种包

data=pd.read_csv('/home/anqian/Test2/xin.rds',sep = '\t')		#读取数据文件
data0=pd.read_csv('/home/anqian/Test2/xin.rds_label',sep='\t')		#读取金标文件
y0=data0.iloc[:,0]		#对金标文件的种类进行提取
x=data.T			#将目标数据转置，将细胞的基因特点设置为行向量

d={'alpha':0, 'beta':1, 'gamma':2, 'alpha.contaminated':3, 'delta':4, 
'beta.contaminated':5, 'gamma.contaminated':6, 'delta.contaminated':7}	    #从find.py中得到的细胞种类总数
for i in range(len(y0)):
    j = y0[i]
    y0[i] = d[j]	    #将细胞的种类用数字表示，便于使用数字来表示可视化时候的颜色
pca=PCA(n_components=1600)	    #设置PCA降维法降维至二维
pca.fit_transform(x)	    
x_new = pca.transform(x)    #x_new为降维后得到的数据
kmeans=KMeans(n_clusters=8, random_state=0)	#设置k均值算法的参数为2
kmeans=kmeans.fit(x_new)			
y = kmeans.fit_predict(x_new)			#y为使用k均值算法预测的结果
#print(kmeans.labels_)

plt.scatter(x_new[:,0], x_new[:,1], c=y)    
plt.show()
plt.scatter(x_new[:,0], x_new[:,1], c=y0)
plt.show()					#分别将预测结果与实际结果进行可视化 
	
print(metrics.adjusted_rand_score(y, y0))	#计算ARI指标


