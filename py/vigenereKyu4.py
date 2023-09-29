#https://www.codewars.com/kata/52d1bd3694d26f8d6e0000d3
class VigenereCipher(object):
    

    def __init__(self, key, alphabet):
        self.key=key
        self.alphabet=alphabet
  
    
    def encode(self,text):
        result = ''
        i = 0
        for l in text:
            if l in self.alphabet:
                sum = self.alphabet.find(l) + self.alphabet.find(self.key[i % len(self.key)])
                mod = int(sum) % len(self.alphabet)
                result = result + str(self.alphabet[mod])
                i+=1
            else:
                result+=l
                i+=1
        
        return result
    
    
    def decode (self,text):
        result = ''
        i = 0
        for l in text:
            if l in self.alphabet:
                sum =self.alphabet.find(l) - self.alphabet.find(self.key[i % len(self.key)])
                mod = int(sum) % len(self.alphabet)
                result = result + str(self.alphabet[mod])
                i+=1
            else:
                result+=l
                i+=1
       
        return result
    
abc = "abcdefghijklmnopqrstuvwxyz"
key = "password"
c = VigenereCipher(key, abc)
print(c.encode('CODEWARS'))
print(c.decode('CODEWARS'))
print(c.encode('waffles'))