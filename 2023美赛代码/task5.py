import requests
from lxml import etree
import pandas as pd
import time
import csv

#爬虫爬取检索次数

data=pd.read_excel('C_data.xlsx')

mydata = []
#输入 单个词语
headers={'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) '
                          'AppleWebKit/537.36 (KHTML, like Gecko) '
                          'Chrome/94.0.4606.71 Safari/537.36'}
url0='https://google.mirrors.pw/search?q='

cnt=0
for i in range(0,356):
    word = data.iloc[i][2]
    url=url0+word
    r = requests.get(url, headers=headers)
    selector = etree.HTML(r.text)
    #outcome = selector.xpath('//*[@id="result-stats"]')
    outcome = selector.xpath('//html/body/div[7]/div/div[7]/div[1]/div/div/div/div/text()')
    tmp=[]
    tmp.append(outcome)
    mydata.append(tmp)
    time.sleep(0.1)
    cnt+=1
    print(cnt,":成功爬取了",data.iloc[i][2],"的数据")
f = open("output1.csv", "w", newline="")
writer = csv.writer(f)
for row in mydata:
    writer.writerow(row)
f.close()           