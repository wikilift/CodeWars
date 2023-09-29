#https://www.codewars.com/kata/525c65e51bf619685c000059
from math import floor
def cakes(recipe, available):
    recipeKeys=set(recipe.keys())
    availableKeys=set(available.keys())
    shared_keys = recipeKeys.intersection(availableKeys)
    t=list(shared_keys)
    test=[]
    if recipeKeys != shared_keys:
        return 0
    
    for k,v in recipe.items():
        
        test.append(floor(available[k]/v))
        
        
   
    return min(test)
    
    
def cakes2(recipe, available):
    try:
        return min([available[a]/recipe[a] for a in recipe])
    except:
        return 0


recipe = {"flour": 500, "sugar": 200, "eggs": 1}
available = {"flour": 1200, "sugar": 1200, "eggs": 5, "milk": 200}
print(cakes(recipe, available))
