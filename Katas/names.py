#https://www.codewars.com/kata/53368a47e38700bd8300030d

def namelist(names):
    q = [ b.get('name') for b in names  ]
    n=len(q)
    return{
        0: '',
        1: '{}', 
        2: '{} & {}', 
        3: '{}, {} & {}', 
        4: '{}, {}, {} & {}',
        5: '{}, {}, {}, {} & {}',
        6: '{}, {}, {}, {}, {} & {}',
        7: '{}, {}, {}, {}, {}, {} & {}',
        8: '{}, {}, {}, {}, {}, {}, {} & {}',
        9: '{}, {}, {}, {}, {}, {}, {}, {} & {}',
        
        
       
    }[min(9, n)].format(*q[:])
   

   

d=[{'name': 'Homer'},{'name': 'Maude'},{'name': 'Seymour'},{'name': 'Barney'},{'name': 'Moe'}]
print(namelist(d))
def likes2(names):
    n = len(names)
    return {
        0: 'no one likes this',
        1: '{} likes this', 
        2: '{} and {} like this', 
        3: '{}, {} and {} like this', 
        4: '{}, {} and {others} others like this'
    }[min(4, n)].format(*names[:3], others=n-2)
    
    """return{
        0:None,
        1:k[1].values()
    }[min(4, n)].format(*names[:3])
    #your code here"""