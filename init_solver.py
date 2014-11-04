# Init solution generator

from random import randint


def generateSolution(problem):
    solution = []
    while(len(problem) != 0):
        workPointToAddIndex = randint(0, len(problem) - 1)
        problem[workPointToAddIndex][2].pop()
        solution.append(problem[workPointToAddIndex][0])
        if(len(problem[workPointToAddIndex][2]) == 0):
            del(problem[workPointToAddIndex])
    return solution