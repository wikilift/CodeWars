#https://www.codewars.com/kata/520446778469526ec0000001/python
def same_structure_as(first, second):
    if isinstance(first, list) and isinstance(second, list):
        return len(first) == len(second) and all(same_structure_as(ai, bi) for ai, bi in zip(first, second))
    return not isinstance(first, list) and not isinstance(second, list)

# test
print(same_structure_as([1, 1, 1], [2, 2, 2]))  
print(same_structure_as([1, [1, 1]], [2, [2, 2]]))  
print(same_structure_as([1, [1, 1]], [[2, 2], 2]))  
print(same_structure_as([[[], []]], [[[], []]]))  
print(same_structure_as([[[], []]], [[1, 1]]))  
