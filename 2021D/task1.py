import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import csv

influencedata=pd.read_excel("influence_data.xlsx")

namestart = []
nameend = []
values = []

for i in range(0,52):
    namestart.append(influencedata.iloc[i][1])
    nameend.append(influencedata.iloc[i][5])
    values.append(1)

start = np.array(namestart)
end = np.array(nameend)
value = np.array(values)

G1 = nx.DiGraph()
for i in range(0,52):
    G1.add_weighted_edges_from([(start[i], end[i],value[i])])

pos=nx.shell_layout(G1)
# nx.draw(G1,pos,with_labels=True, node_color='white', edge_color='red', node_size=800, alpha=1 )
    
# 计算点度中心性(degree centrality)作为对比
dc = nx.out_degree_centrality(G1)
print("输出点度中心度的计算值：")
for item1 in dc:
    print(item1,"\t",dc[item1])
G2 = nx.DiGraph()
for i in range(0,52):
    G2.add_weighted_edges_from([(end[i],start[i], value[i])])

pos=nx.shell_layout(G2)
# nx.draw(G2,pos,with_labels=True, node_color='white', edge_color='red', node_size=800, alpha=1 )

# 计算特征向量中心度(eigenvector centrality)并输出值
eigenvector1 = nx.eigenvector_centrality_numpy(G2, max_iter=5000) #特征向量中心度中心度
print("输出特征向量中心度的计算值：")
for item in eigenvector1:
    print(item,"\t",eigenvector1[item])


# 下面是新添加的
mydc = {}
for item in dc:
    mydc.update({item:0.1*dc[item]+0.9*eigenvector1[item]})

mydata = []
for item in mydc:
    tmp=[]
    tmp.append(item)
    tmp.append(mydc[item])
    mydata.append(tmp)

f = open("output.csv", "w", newline="")
writer = csv.writer(f)
for row in mydata:
    writer.writerow(row)
f.close()