#https://www.codewars.com/kata/52223df9e8f98c7aa7000062/


import codecs
def rot13(message):
    #your code here
    return codecs.decode(message,'rot_13')
  

print(rot13("EBG13 rknzcyr."))