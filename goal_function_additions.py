# Set of functions used to improve goal function calculations

from random import random


class Point:
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