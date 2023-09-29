#https://www.codewars.com/kata/525caa5c1bf619d28c000335/train/python
import numpy as np
def is_solved(board):
    #convert to numpy array
    b=np.array(board)
    #we obtain posibles win positions
    winnerList=[[b[0,0],b[1,1],b[2,2]],
              [b[0,2],b[1,1],b[2,0]],
                b[:,0].tolist(),
                b[:,1].tolist(),
                b[:,2].tolist(),
                b[0,:].tolist(),
                b[1,:].tolist(),
                b[2,:].tolist()]
    
   #we go through the possibilities of victory and check if in some
   #same player has marked all 3 positions
    for t in winnerList:
        if all(e1 == 1 for e1 in t):
            return 1
        elif all(e1 == 2 for e1 in t):
            return 2
    #If we have arrived here, no player has won, we check if there is any free space left -> value 0    
    if np.any(b[:] == 0):
        return -1 

    #in any other case, it is a tie
    return 0
    



print(is_solved( [[1, 2, 1],
                  [1, 1, 2],
                  [2, 2, 0]]))