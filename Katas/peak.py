#https://www.codewars.com/kata/5279f6fe5ab7f447890006a7/train/python


def pick_peaks(arr):
    j=arr.index(max(arr))
    r=max(arr)
    t={'pos':[j,len(arr)]}
    return j,r
print(pick_peaks([1,2,3,6,4,1,2,3,2,1])) 
    