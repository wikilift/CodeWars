#https://www.codewars.com/kata/52449b062fb80683ec000024

def generate_hashtag(s):
    
    j=[x.capitalize() for x in s.split()]
    
    return False  if not s or len(s)>140 else '#'+"".join(j)
    

print(generate_hashtag("podemos con todo"))