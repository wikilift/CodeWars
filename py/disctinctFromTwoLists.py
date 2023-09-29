#https://www.codewars.com/kata/523f5d21c841566fde000009/train/python
import pandas as pd
def array_diff(a, b):
    l=[]
    for i in a:
        if i not in b:
            l.append(i)
    return l

def array_diffCool(a, b):
    return [i for i in a if i not in b]

def array_diffUniques(a, b):
    return pd.Series(a).loc[b].values
# pd.Series(a).loc[b].values

print(array_diff([1,2,2], [1]))