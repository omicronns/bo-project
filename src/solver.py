from random import randint
from random import random
from copy import deepcopy

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distanceSqr(self, pt):
        return (self.x - pt.x)*(self.x - pt.x) + (self.y - pt.y)*(self.y - pt.y)

    @staticmethod
    def rand():
        return Point(random(), random())

    def copy(self):
        return Point(self.x, self.y)

    def __str__(self):
        return "[" + str(self.x) + ", " + str(self.y) + "]"


class Solver(object):
    __problem = []
    __problemSize = 0
    __solution = []
    __solutionLength = 0
    __toolsWorkload = []
    __toolsCount = 0
    __cost = 0

    def setProblem(self, problem):
        self.__problem = problem
        self.__problemSize = len(problem)

    def setToolsWorkload(self, toolsWorkload):
        self.__toolsWorkload = toolsWorkload
        self.__toolsCount = len(toolsWorkload)

    def getProblem(self):
        return self.__problem

    def getSolution(self):
        return self.__solution

    def getSolutionCost(self):
        return self.__cost

    def generateProblem(self, workPointsCount, maxStepsPerWorkPoint):
    # This function returns problem to solve in following format:
    # [[i, pt_i, [t_i0, t_i1, ... ,t_iN]], ...]
    # where:
    #   i       is work point number
    #   pt_i    is a point associated with i-th work point
    #   t_ik    is a k-th tool needed to use for i-th work point
        for workPointNumber in range(workPointsCount):
            point = Point.rand()
            toolsAtThisWorkPoint = randint(1, maxStepsPerWorkPoint)
            taskTools = []
            for tool in range(toolsAtThisWorkPoint):
                taskTools.append(randint(0, self.__toolsCount - 1))
            workPoint = []
            workPoint.append(workPointNumber)
            workPoint.append(point)
            workPoint.append(taskTools)
            self.__problem.append(workPoint)
        self.__problemSize = len(self.__problem)
        return self.__problem

# TODO:Change this method so it would calculate goal function also
    def generateInitSolution(self):
    # Generates solution of form:
    # [k_1, k_2, ... , k_N]
    # where:
    #   k_i     is a number of work point needed to process in i-th step
        self.__cost = 0
        self.__solution = []
        previousPoint = Point(0,0)
        problemCopy = deepcopy(self.__problem)
        while(len(problemCopy) != 0):
            workPointToAddIndex = randint(0, len(problemCopy) - 1)
            # TODO: Make function count tool changes cost also
            self.__cost += self.__toolsWorkload[problemCopy[workPointToAddIndex][2][0]]
            self.__cost += previousPoint.distanceSqr(problemCopy[workPointToAddIndex][1])
            previousPoint = problemCopy[workPointToAddIndex][1].copy();
            del(problemCopy[workPointToAddIndex][2][0])
            self.__solution.append(problemCopy[workPointToAddIndex][0])
            if(len(problemCopy[workPointToAddIndex][2]) == 0):
                del(problemCopy[workPointToAddIndex])
        self.__solutionLength = len(self.__solution)
        return self.__solution

# TODO:Change this method so it would change goal function also
    def permuteSolution(self, iterations):
    # Permutes valid solution for iterations number of times
        length = self.__solutionLength
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

