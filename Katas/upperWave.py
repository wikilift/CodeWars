#https://www.codewars.com/kata/58f5c63f1e26ecda7e000029
def wave(t):
    r=[]
    
    for j in range(len(t)):
        if " " not in t[j]:
            r.append(t[:j].lower() + t[j:].capitalize())
        
    
    return r

def waves(s):
    return [s[:i].lower() + s[i:].capitalize() for i in range(len(s)) if s[i] != " "]

print(wave("two words"))

   