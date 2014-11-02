# Main file

import genp


points = 10
problem = genp.generate(points, 5, 10)
for point in problem:
    print point
