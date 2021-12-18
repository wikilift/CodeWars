#https://www.codewars.com/kata/59d9ff9f7905dfeed50000b0/train/python
import numpy as np
def solve(arr):
    a=np.arange(65,91)
    alpha=[chr(x) for x in a]
    upper=[x.upper() for x in arr ]
    counter=0
    returned=[]
    for word in upper:
        for i in range(len(word)):
            if(i>25):
                break
            if alpha[i]==word[i]:
               counter+=1
        returned.append(counter)
        counter=0
    return returned


from string import ascii_lowercase as alphabet

def solve2(arr):
    return [sum(c == alphabet[i] for i,c in enumerate(word[:26].lower())) for word in arr]
   
 

print(solve(["abode","ABc","xyzD"]))