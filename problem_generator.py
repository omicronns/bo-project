# Problem generation module

from random import randint
from goal_function_additions import Point


# This function returns problem to solve in following format:
# [[n, Point, [t_0, t_1, ... ,t_N]], ...]
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
