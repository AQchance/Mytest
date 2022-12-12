import pandas as pd
import numpy as np
from  sklearn.decomposition import PCA
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn import metrics

data=pd.read_csv('/home/anqian/Test2/klein.rds',sep = '\t')
x=data.T
data0=pd.read_csv('/home/anqian/Test2/klein.rds_label',sep='\t')
y0=data0.iloc[:,0]
d={'d0':0, 'd2':1, 'd4':2, 'd7':3}
for i in range(len(y0)):
    j = y0[i]
    y0[i] = d[j]
pca=PCA(n_components=1600,random_state=1)
pca.fit_transform(x)
x_new = pca.transform(x)
kmeans=KMeans(n_clusters=4)
kmeans=kmeans.fit(x_new)
y = kmeans.fit_predict(x_new)
#print(kmeans.labels_)

plt.scatter(x_new[:,0], x_new[:,1], c=y)
plt.show()
plt.scatter(x_new[:,0], x_new[:,1], c=y0)
plt.show()

print(metrics.adjusted_rand_score(y, y0))
