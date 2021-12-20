#https://www.codewars.com/kata/52761ee4cffbc69732000738
def good_vs_evil(good, evil):
    def tryParseInt(s, base=10, val=None):
        try:
            return int(s, base)
        except ValueError:
            pass
    goodValues=(1,2,3,3,4,10)
    evilValues=(1,2,2,2,3,5,10)
    totalGood=sum([value*soldiers for value,soldiers in zip([ tryParseInt(x) for x in good.split(" ") if x is not None],goodValues)])
    totalEvil=sum([value*soldiers for value,soldiers in zip([ tryParseInt(x) for x in evil.split(" ") if x is not None],evilValues)])
    if totalEvil>totalGood:
        return 'Battle Result: Evil eradicates all trace of Good'
    elif totalEvil<totalGood:
        return 'Battle Result: Good triumphs over Evil'
    else:
        return 'Battle Result: No victor on this battle field'
   
  



print(good_vs_evil('1 1 1 1 1 1', '1 1 1 1 1 1 1'))

