#https://www.codewars.com/kata/5266876b8f4bf2da9b000362/train/python

def likes(names):
    # your code here
    
    if names:
        if(len(names)==1):
            return names[0]+' likes this'
        elif(len(names)==2):
            return names[0]+' and '+names[1]+' like this'
        elif(1<len(names)<4):
            return names[0]+', '+names[1]+' and '+names[2]+' like this'
        else:
            return names[0]+', '+names[1]+' and '+str(len(names)-2)+' others like this'
    else:
        return 'no one likes this'

print(likes([]))
print(likes(['Peter']))
print(likes(['Jacob', 'Alex']))
print(likes(['Max', 'John', 'Mark']))
print(likes(['Alex', 'Jacob', 'Mark', 'Max']))

def likes2(names):
    n = len(names)
    return {
        0: 'no one likes this',
        1: '{} likes this', 
        2: '{} and {} like this', 
        3: '{}, {} and {} like this', 
        4: '{}, {} and {others} others like this'
    }[min(4, n)].format(*names[:3], others=n-2)