# https://www.codewars.com/kata/514b92a657cdc65150000006

def solution(number):
    
    return sum([x for x in range(1,number) if x%3==0 or x%5==0])
    
  
  
print(solution(200))

#  (1..entry).filter { it%5!=0 || it%3!=0 }.sum()