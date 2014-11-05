from random import randint
from random import random

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distanceSqr(self, pt):
        return (self.x - pt.x)*(self.x - pt.x) + (self.y - pt.y)*(self.y - pt.y)

    @staticmethod
    def rand():
        return Point(random(), random())

    def __str__(self):
        return "[" + str(self.x) + ", " + str(self.y) + "]"


class Solver(object):
    __problem = []
    __solution = []

    def setProblem(self, problem):
        self.__problem = problem

    def getProblem(self, problem):
        return self.__problem

    def getSolution(self):
        return self.__solution

    def generateProblem(self, workPointsCount, toolsCount, maxToolsPerWorkPoint):
    # This function returns problem to solve in following format:
    # [[i, pt_i, [t_i0, t_i1, ... ,t_iN]], ...]
    # where:
    #   i       is work point number
    #   pt_i    is a point associated with i-th work point
    #   t_ik    is a k-th tool needed to use for i-th work point
        for workPointNumber in range(workPointsCount):
            point = Point.rand()
            toolsAtThisWorkPoint = randint(1, maxToolsPerWorkPoint)
            taskTools = []
            for tool in range(toolsAtThisWorkPoint):
                taskTools.append(randint(0, toolsCount))
            workPoint = []
            workPoint.append(workPointNumber)
            workPoint.append(point)
            workPoint.append(taskTools)
            self.__problem.append(workPoint)
        return self.__problem

    def generateInitSolution(self):
    # Generates solution of form:
    # [k_1, k_2, ... , k_N]
    # where:
    #   k_i     is a number of work point needed to process in i-th step
        while(len(self.__problem) != 0):
            workPointToAddIndex = randint(0, len(self.__problem) - 1)
            self.__problem[workPointToAddIndex][2].pop()
            self.__solution.append(self.__problem[workPointToAddIndex][0])
            if(len(self.__problem[workPointToAddIndex][2]) == 0):
                del(self.__problem[workPointToAddIndex])
        return self.__solution

    def permuteSolution(self, iterations):
    # Permutes valid solution for iteration number of times
        length = len(self.__solution)
        if(length == 0):
            return
        while(iterations > 0):
            i = randint(0, length - 1)
            j = randint(0, length - 1)
            tmp = self.__solution[i]
            self.__solution[i] = self.__solution[j]
            self.__solution[j] = tmp
            iterations -= 1
        return self.__solution