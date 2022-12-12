import pandas as pd

mydata=pd.read_csv('/home/anqian/Test2/house-votes-84.data', sep=',', header=None)
#使用mydata进行投票结果的统计
republican_ycount=[]
republican_ncount=[]
republican_wcount=[]
democrat_ncount=[]  
democrat_ycount=[]  
democrat_wcount=[]        
for i in range(16):
    republican_ycount.append(0)
    republican_ncount.append(0)
    republican_wcount.append(0)
    democrat_ycount.append(0)
    democrat_ncount.append(0)
    democrat_wcount.append(0)
    for j in range (435):
        if mydata[0][j] == 'republican':
            if mydata[i+1][j]=='y':
                republican_ycount[i]+=1
            elif mydata[i+1][j]=='?':
                republican_wcount[i]+=1
            else:
                republican_ncount[i]+=1
        else:
            if mydata[i+1][j]=='y':
                democrat_ycount[i]+=1
            elif mydata[i+1][j] == '?':
                democrat_wcount[i]+=1
            else:
                democrat_ncount[i]+=1

#输出投票统计的结果
print('republican_y:',republican_ycount)
print('republican_n:',republican_ncount)
print('republican_w:',republican_wcount)
print('democrat_y:',democrat_ycount)
print('democrat_n:',democrat_ncount)
print('democrat_w:',democrat_wcount)
'''打开文件'''
path='/home/anqian/Test2/house-votes-84.data'
txt_file = open(path)
txt = txt_file.read()
txt_file.close()
lst_txt=txt.split('\n')  
data = []
for txt_line in lst_txt:
    tmp=txt_line.split(',')
    data.append(tmp)

#数据预处理，分类处理
def DataPreProcessing(data, choice1, choice2):
    data1 = []
    for data_line in data:
        tmp_data = []
        for i in range(1,len(data_line)):
            if(data_line[0]!=choice2):
                continue
            if(data_line[i] == choice1):
                tmp_data.append(i)
    
        if(tmp_data == []):
            continue
        data1.append(tmp_data)
    return data1
#深入挖掘规则
def Deep_mining(data, suport, coincidence):
    #一阶关联规则挖掘
    dic_1 = mining_first(data, suport, coincidence)
    #print(dic_1)
    #二阶关联规则挖掘
    dic_2 = mining_second(data, dic_1, suport, coincidence)
    #print(dic_2)
    dic_before = dic_2
  
    dic_r = []
    #循环进行更深层次的挖掘
    while(dic_before != {}):
        dic_r.append(dic_before)
        dic_3 = mining(data, dic_before, suport, coincidence)
        dic_before = dic_3
  
    return dic_r
'''
  进行关联规则的更深层次挖掘
  挖掘出候选3-项集或者4-项集乃至n-项集
  '''
def mining(data, dic_before, suport, coincidence):
  dic_3 = {}
  #对二阶遍历输出的字典进行挖掘
  for item0 in dic_before:
    for item1 in dic_before:
      if (item0 != item1):
        # print(item0,item1)
        item_len = len(item0)
        equal = True
        tmp_item3 = []
        # 判断前n-1项是否一致
        for i in range(item_len - 1):
          tmp_item3.append(item0[i])
          if (item0[i] != item1[i]):
            equal = False
            break
        if (equal == True):
          minitem = min(item0[-1], item1[-1])
          maxitem = max(item0[-1], item1[-1])
          tmp_item3.append(minitem)
          tmp_item3.append(maxitem)
          tmp_item3 = tuple(tmp_item3)
          dic_3[tmp_item3] = 0
        else:
          continue
  # print('dic_3:',dic_3)
  #剪枝
  for data_line in data:
    for item in dic_3:
      is_in = True
      for i in range(len(item)):
        if (item[i] not in data_line):
          is_in = False

      if (is_in == True):
        dic_3[item] += 1

  #计算数据规模，用于计算支持度和置信度
  count = len(data)
  dic_3n = {}
  
  for item in dic_3:
    count_item0 = dic_before[item[:-1]]
    # 判断 支持度 和 置信度
    if ((dic_3[item] >= suport * count) and (dic_3[item] >= coincidence * count_item0)):
      dic_3n[item] = dic_3[item]

  return dic_3n


def mining_first(data, suport, coincidence):
    #挖掘候选1-项集
    dic = {}
    count = len(data)
    for data_line in data:
        for data_item in data_line:
            if(data_item in dic):
                dic[data_item] += 1
            else:
                dic[data_item] = 1

    item_suport = int(count * suport)
    dic_1 = {}
    for item in dic:
        if(dic[item] >= item_suport):
            dic_1[item] = dic[item]
  
    return dic_1
  
def mining_second(data, dic_before, suport, coincidence):
    #挖掘出候选2-项集
    dic = {}
    count = len(data)
    count2 = 0
    for data_line in data:
        for i in range(len(data_line)):
            for j in range(i + 1, len(data_line)):
                if(data_line[i] in dic_before and data_line[j] in dic_before):
                    count2 += 1
                    tmp = (data_line[i], data_line[j])
                    if(tmp in dic):
                        dic[tmp] += 1
                    else:
                        dic[tmp] = 1
                else:
                    continue
  
    dic_2 = {}
    for item in dic:
        count_item0 = dic_before[item[0]]
        count_item1 = dic_before[item[1]]
        # 判断 支持度 和 置信度
        if((dic[item] >= suport * count) and ((dic[item] >= coincidence * count_item0) or (dic[item] >= coincidence * count_item1))):
            dic_2[item] = dic[item]
  
    return dic_2





suport = 0.3
coincidence = 0.9


#数据预处理
data_y_r = DataPreProcessing(data,'y','republican')
data_n_r = DataPreProcessing(data,'n','republican')
data_y_d = DataPreProcessing(data,'y','democrat')
data_n_d = DataPreProcessing(data,'n','democrat')

#挖掘关联规则
vote_y_r = Deep_mining(data_y_r, suport, coincidence)
print('republican_vote YES:\n',vote_y_r)
vote_n_r = Deep_mining(data_n_r, suport, coincidence)
print('republican_vote No:\n',vote_n_r)
vote_y_d = Deep_mining(data_y_d, suport, coincidence)
print('democrat_vote Yes:\n',vote_y_d)
vote_n_d = Deep_mining(data_n_d, suport, coincidence)
print('democrat_vote No:\n',vote_n_d)
