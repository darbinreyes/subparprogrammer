# coding style : https://www.python.org/dev/peps/pep-0008/
# recommended way implementing a C like struct.: https://docs.python.org/3/tutorial/classes.html#odds-and-ends
# I will use matplotlib to draw points and lines. https://matplotlib.org/tutorials/introductory/usage.html#sphx-glr-tutorials-introductory-usage-py
import random
import matplotlib.pyplot as plt

class coloredPoint:
    """ represents a colored point."""
    def __init__(self, color, x, y):
        self.color = color # 0 = red, 1 = blue.
        self.x = x
        self.y = y

def create_coordinates(n, coordsmin, coordsmax):
    """ returns a list of n distinct coordinates in the range  coordsmin <= c <= coordsmax. min/max should be integers."""
    return random.sample(range(coordsmin, coordsmax + 1), n) # sample() takes random samples without replacement. This ensures distinct coordinates.

def create_points(n, xmin, xmax, ymin, ymax):
    """ returns a list of n distinct point. color = 0 means red, 1 means blue """
    #xcoords = create_coordinates(n, xmin, xmax)
    #ycoords = create_coordinates(n, ymin, ymax)
    #print(xcoords)
    #print(ycoords)
    xcoords = [93, 4, 76, 47, 94, 11]
    ycoords = [31, 89, 59, 12, 27, 8]
    points = []
    for i in range(n):
        points.append(coloredPoint(0, xcoords[i], ycoords[i]))

    return points

def plot_points(n, redpts, bluepts):
    """ plots the given points. """
    fig, ax = plt.subplots()
    # plot red then blue points.
    for p in redpts:
        ax.plot(p.x, p.y, marker='.', color='red', markersize=12)
    for p in bluepts:
        ax.plot(p.x, p.y, marker='.', color='blue', markersize=12)

    # This connects the points in the same order each time, I need to represent
    # the connections with a boolean matrix.
    for i in range(n):
        ax.plot([redpts[i].x, bluepts[i].x], [redpts[i].y, bluepts[i].y], color='black')
    plt.show(block=True)

def main():
    """ main function """
    n = 3
    xmin = 0
    xmax = 100
    ymin = 0
    ymax = 100
    pts = create_points(2 * n, xmin, xmax, ymin, ymax)
    redpts = pts[0:n]
    bluepts = pts[n:]
    for p in bluepts:
        p.color = 1

    plot_points(n, redpts, bluepts)

if __name__ == '__main__':
  main()