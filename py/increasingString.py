#https://www.codewars.com/kata/54a91a4883a7de5d7800009c

def tryParseInt(s, base=10, val=None):
        try:
            return int(s, base)
        except ValueError:
            pass
def increment(word):
    
    t=[tryParseInt(i) for i in word ]
    j=[i for i in t if i is not None]
    if len(j)==0:
        return word+str(1)
   
    s=""
    zeros=0
    
    for i in j:
        if(i==0 and j[i+1]==0):
            zeros+=1
        else:
            s+=str(i)
    if(len(s)==0):
        return 'foobar{}{}'.format(str('0'*(zeros-1)),str(1))
    flag=tryParseInt(s)
   
    flag+=1
    return 'foobar{}{}'.format(str('0'*zeros),str(flag))



def increment_string2(s):
    c = s.rstrip('0123456789')
    n = s[len(c):]
    if n=='':
        return s+'1'
    else:
        return c+str(int(n)+1).zfill(len(n))
print(increment('foobar001000'))