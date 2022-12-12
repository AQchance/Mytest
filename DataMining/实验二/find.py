import pandas as pd

data=pd.read_csv('/home/anqian/Test2/zeisel.rds_label',sep = '\t')

m=data.iloc[:,0].value_counts()
print(m)