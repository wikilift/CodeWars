#https://www.codewars.com/kata/52b757663a95b11b3d00062d
def to_weird_case(t):
    j=""
  
    words=t.split(" ")
    returned=[]
    for word in words:
        for counter in range(len(word)):
           
            if(counter%2==0):
               j+= word[counter].upper()
            elif(counter %2 !=0):
               j+=word[counter].lower()
        returned.append(j)
        j=""
    return ' '.join(returned)


def to_weird_case2(string):
    recase = lambda s: "".join([c.upper() if i % 2 == 0 else c.lower() for i, c in enumerate(s)])
    return " ".join([recase(word) for word in string.split(" ")])
                
            
    
                
       
            

print(to_weird_case("hola pene gordo"))
