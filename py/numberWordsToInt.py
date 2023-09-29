#https://www.codewars.com/kata/525c7c5ab6aecef16e0001a5
def parse_int (input, keyWords={}):
    if not keyWords:
        units = [
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
        "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen",
        ]

        tens = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

        scales = ["hundred", "thousand", "million", "billion", "trillion"]

        keyWords["and"] = (1, 0)
        for idx, word in enumerate(units):  keyWords[word] = (1, idx)
        for idx, word in enumerate(tens):       keyWords[word] = (1, idx * 10)
        for idx, word in enumerate(scales): keyWords[word] = (10 ** (idx * 3 or 2), 0)

    ordinal_words = {'first':1, 'second':2, 'third':3, 'fifth':5, 'eighth':8, 'ninth':9, 'twelfth':12}
    ordinal_endings = [('ieth', 'y'), ('th', '')]

    input = input.replace('-', ' ')

    current = result = 0
    answer = ""
    posible = False
    for word in input.split():
        if word in ordinal_words:
            scale, increment = (1, ordinal_words[word])
            current = current * scale + increment
            if scale > 100:
                result += current
                current = 0
            posible = True
        else:
            for ending, replacement in ordinal_endings:
                if word.endswith(ending):
                    word = "%s%s" % (word[:-len(ending)], replacement)

            if word not in keyWords:
                if posible:
                    answer += repr(result + current) + " "
                answer += word + " "
                result = current = 0
                posible = False
            else:
                scale, increment = keyWords[word]

                current = current * scale + increment
                if scale > 100:
                    result += current
                    current = 0
                posible = True

    if posible:
        answer += repr(result + current)

    return int(answer)


print(parse_int('two hundred forty-six'))