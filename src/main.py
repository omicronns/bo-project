# Main file
from solver import Solver


workPoints = 100
solver = Solver()
solver.generateProblem(workPoints, 10, 5)
print solver.generateInitSolution()
a=[]
for i in range(0, workPoints):
    a.append(solver.getSolution().count(i))
print solver.permuteSolution(1000)
b=[]
for i in range(0, workPoints):
    b.append(solver.getSolution().count(i))
print a==b
