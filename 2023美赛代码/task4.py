import wordcloud
import matplotlib.pyplot as plt
import pandas as pd
import csv

data=pd.read_excel("C_data.xlsx")
frequency_dic = {"a":0.08167, "b":0.01492, "c": 0.02782, "d":0.04253, "e":0.12702, 
"f":0.02228, "g":0.02015, "h":0.06094, "i":0.06966, "j":0.00153, "k":0.00772, "l":0.04025,
"m":0.02406, "n":0.06749, "o":0.07507, "p":0.01929, "q":0.00095, "r":0.05987, "s":0.06372, 
"t":0.09056, "u":0.02758, "v":0.00978, "w":0.02360, "x":0.00150, "y":0.01974, "z":0.00074}
output = []
for i in range(0,356):
    sum=0
    mydata = []
    for ch in data.iloc[i][2]:
        sum+=frequency_dic[ch]
    mydata.append(sum)
    output.append(mydata)

f = open("output.csv", "w", newline="")
writer = csv.writer(f)
for row in output:
    writer.writerow(row)
f.close()
