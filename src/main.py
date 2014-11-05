# Main file
from solver import Solver


workPoints = 50
solver = Solver()
solver.setToolsWorkload([2, 5, 7, 5, 5, 7, 5, 5, 7, 5])
solver.generateProblem(workPoints, 2)
print solver.generateInitSolution()
print solver.getSolutionCost()
print solver.generateInitSolution()
print solver.getSolutionCost()
print solver.generateInitSolution()
print solver.getSolutionCost()
print solver.generateInitSolution()
print solver.getSolutionCost()
# a=[]
# for i in range(0, workPoints):
#     a.append(solver.getSolution().count(i))
# print solver.generateInitSolution()
# b=[]
# for i in range(0, workPoints):
#     b.append(solver.getSolution().count(i))
# print a==b
