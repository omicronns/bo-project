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
    # This function returns problem to solve in following format:
    # [[i, pt_i, [t_i0, t_i1, ... ,t_iN]], ...]
    # where:
    #   i       is work point number
    #   pt_i    is a point associated with i-th work point
    #   t_ik    is a k-th tool needed to use for i-th work point
    @staticmethod
    def generateProblem(workPointsCount, toolsCount, maxToolsPerWorkPoint):
        problem = []
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
            problem.append(workPoint)
        return problem

    # Generates solution of form:
    # [k_1, k_2, ... , k_N]
    # where:
    #   k_i     is a number of work point needed to process in i-th step
    @staticmethod
    def generateInitSolution(problem):
        solution = []
        while(len(problem) != 0):
            workPointToAddIndex = randint(0, len(problem) - 1)
            problem[workPointToAddIndex][2].pop()
            solution.append(problem[workPointToAddIndex][0])
            if(len(problem[workPointToAddIndex][2]) == 0):
                del(problem[workPointToAddIndex])
        return solution