import pandas as pd
import numpy as np
from  sklearn.decomposition import PCA
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn import metrics

data=pd.read_csv('/home/anqian/Test2/lake.rds',sep = '\t')
x=data.T
data0=pd.read_csv('/home/anqian/Test2/lake.rds_label',sep='\t')
y0=data0.iloc[:,0]
d={'Ex1':0, 'Ex2':1, 'Ex3':2, 'Ex4':3, 'Ex5':4, 'Ex6':5, 'Ex7':6, 'Ex8':7, 
'In1':8, 'In2':15, 'In3':9, 'In4':10, 'In5':11, 'In6':12, 'In7':13, 'In8':14}
for i in range(len(y0)):
    j = y0[i]
    y0[i] = d[j]
pca=PCA(n_components=1600,random_state=0)
pca.fit_transform(x)
x_new = pca.transform(x)
kmeans=KMeans(n_clusters=16)
kmeans=kmeans.fit(x_new)
y = kmeans.fit_predict(x_new)
#print(kmeans.labels_)

plt.scatter(x_new[:,0], x_new[:,1], c=y)
plt.show()
plt.scatter(x_new[:,0], x_new[:,1], c=y0)
plt.show()
print(metrics.adjusted_rand_score(y, y0))
