#https://www.codewars.com/kata/52bc74d4ac05d0945d00054e

def first_non_repeating_letter(string):
    #your code here
    if string:
        k=string.lower()
        j=[x.lower() for x in string]
        q = [x for x in k if k.count(x)==1]
        if len(q) >0:
           r= next(iter(q or []), '')
           p=j.index(r)
           
           return string[p]
        return ''
        
    else: return ''
    
def first_non_repeating_letter2(string):
    for x in string:
        if string.lower().count(x.lower()) == 1:
            return x
    return ''
    
    
    
    
print(first_non_repeating_letter("sTreSS"))