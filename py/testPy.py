#https://www.codewars.com/kata/583d171f28a0c04b7c00009c/python
from itertools import accumulate

def max_sum(a, ranges):
    rolling_sum = list(accumulate(a)) + [0]
    return max(rolling_sum[j] - rolling_sum[i-1] for i, j in ranges)
    
   
    
   

print(max_sum( [1, -2, 3, 4, -5, -4, 3, 2, 1], [(1, 3), (0, 4), (6, 8)]))

""" def max_sum(a, ranges):
    list=[]
    t=0
    for start,end in ranges:
        k=np.arange(start,end+1)
       
        for n in k:
            t+=a[n]
        list.append(t)
        t=0   
   
    return max(list)"""