#https://www.codewars.com/kata/54bb6ee72c4715684d0008f9/train/python
def solution(number):
    return sum_of_multiples(3, number) + sum_of_multiples(5, number) - sum_of_multiples(15, number)

def sum_of_multiples(multiple, limit):
    max_factor = (limit - 1) // multiple
    return multiple * max_factor * (max_factor + 1) // 2


print(solution(10))  
print(solution(20))  
