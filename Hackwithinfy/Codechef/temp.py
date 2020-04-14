def nonRepeatingChar(string):
    m = {}
    for char in string:
        if char in m:
            m[char] += 1
        else:
            m[char] = 1
    for char in string:
        if m[char] == 1:
            return char
# Main
string = input()
print(nonRepeatingChar(string))
