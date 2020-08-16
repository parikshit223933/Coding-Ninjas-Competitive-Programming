numbersss = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
numbercountofvowels = [2, 2, 1, 2, 2, 2, 1, 2, 2, 2]

userInputforLength = int(input())
arrayofnumbers = list(map(int, input().strip().split()))
initialCount = 0
for iteratorMain in range(userInputforLength):
    for iteratorSecondary in str(arrayofnumbers[iteratorMain]):
        initialCount = initialCount + numbercountofvowels[int(iteratorSecondary)]
finalAnswer = 0
for iteratorMain in range(userInputforLength-1):
    for j in range(iteratorMain+1,userInputforLength):
        if arrayofnumbers[iteratorMain] + arrayofnumbers[j] == initialCount:
            finalAnswer += 1
if finalAnswer <= 100:
    print(numbersss[finalAnswer],end="")
else:
    print("greater 100",end="")