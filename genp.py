# Problem generation module

import random


def generate(points, tools, maxtools):
    problem = []
    for pointn in range(points):
        coords = []
        coords.append(random.random())
        coords.append(random.random())
        tasktoolsn = random.randint(1, maxtools)
        tasktools = []
        for tool in range(tasktoolsn):
            tasktools.append(random.randint(0, tools))
        point = []
        point.append(coords)
        point.append(tasktools)
        problem.append(point)
    return problem
