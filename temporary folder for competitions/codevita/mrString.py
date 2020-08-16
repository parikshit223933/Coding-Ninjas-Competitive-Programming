def printAnswers(numbersss, finalAnswer):
    if finalAnswer <= 100:
        print(numbersss[finalAnswer], end="")
    else:
        print("greater 100", end="")
    return


def initializeArrays():
    numbersss = ["zero", "one", "two", "three", "four",
                 "five", "six", "seven", "eight", "nine"]
    numbercountofvowels = [2, 2, 1, 2, 2, 2, 1, 2, 2, 2]
    return (numbersss, numbercountofvowels)


def initializeRequirements():
    finalAnswer = 0
    initialCount = 0
    userInputforLength = int(input())
    arrayofnumbers = list(map(int, input().strip().split()))
    return (finalAnswer, initialCount, userInputforLength, arrayofnumbers)


def main():

    (numbersss, numbercountofvowels) = initializeArrays()
    (finalAnswer, initialCount, userInputforLength,
     arrayofnumbers) = initializeRequirements()

    for iteratorMain in range(userInputforLength):
        for iteratorSecondary in str(arrayofnumbers[iteratorMain]):
            initialCount = initialCount + \
                numbercountofvowels[int(iteratorSecondary)]

    for iteratorMain in range(userInputforLength-1):
        for j in range(iteratorMain+1, userInputforLength):
            if arrayofnumbers[iteratorMain] + arrayofnumbers[j] == initialCount:
                finalAnswer += 1

    printAnswers(numbersss, finalAnswer)


main()
