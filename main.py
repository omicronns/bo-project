# Main file
from problem_generator import generateProblem
from init_solver import generateSolution
from goal_function_additions import Point


problem = generateProblem(10, 5, 5)
for workPoint in problem:
    print workPoint
solution = generateSolution(problem)
print solution
for i in range(0, 10):
    print solution.count(i)
