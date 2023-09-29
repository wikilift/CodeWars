#https://www.codewars.com/kata/57ed40e3bd793e9c92000fcb/train/python
def correctness(bobs_decisions, expert_decisions): 
    # your code here
    points=0
    for i,t in zip(bobs_decisions,expert_decisions):
        print(i,t)
        if(i == t): 
            points+=1
        elif (i!='?' and t=='?' or i=='?' and t!='?'): 
            points+=0.5
        else:
            continue
         
         
    return points
print(correctness(('M', '?', 'M'), ('M', 'F', '?')))
def correctness(bob, exp): 
    return sum(b==e or 0.5*(b=='?' or e=='?') for b,e in zip(bob, exp))

def correctness(bobs_decisions, expert_decisions):
    return sum(1 if bob == expert else .5 if '?' in (bob, expert) else 0 for bob, expert in zip(bobs_decisions, expert_decisions))
        