#https://www.codewars.com/kata/52685f7382004e774f0001f7
def make_readable(s):
    return '{:02}:{:02}:{:02}'.format(s / 3600, s / 60 % 60, s % 60)