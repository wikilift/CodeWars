#https://www.codewars.com/kata/5a51717fa7ca4d133f001fdf


def test(score,weight,capacity):
    
    dictionary=dict(zip(score, weight))
    l=[]
    suma=[]
    r=dictionary.copy()
    print(dictionary)
    print()
    for k in dictionary:
        q=max(r)
        print(max(r))
        del(r[q])
        pass
    
            
        
    
    
    return suma
        
    
        
        
    
print(test([15, 10, 9, 5],[1, 5, 3, 4],8))
#maxScore_name = max(r, key=r.get)