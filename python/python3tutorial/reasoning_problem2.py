# coding style : https://www.python.org/dev/peps/pep-0008/
# recommended way implementing a C like struct.: https://docs.python.org/3/tutorial/classes.html#odds-and-ends
# I will use matplotlib to draw points and lines. https://matplotlib.org/tutorials/introductory/usage.html#sphx-glr-tutorials-introductory-usage-py
import random
import matplotlib.pyplot as plt

print_count = 0

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

    # This connects the points according to the given boolean matrix.
    # Let the row index correspond to blue points and the column index
    # correspond to red points.
    conn_matrix = [[False, True, False],
                   [True, False, False],
                   [False, False, True]]
    for i in range(len(conn_matrix)):
        for j in range(len(conn_matrix[i])):
            if conn_matrix[i][j]:
                ax.plot([bluepts[i].x, redpts[j].x], [bluepts[i].y, redpts[j].y], color='black')
    plt.show(block=True)

def print_conn(conn):
    """Prints the given connection matrix."""
    for i in range(len(conn)):
        print(conn[i])

    print("\n")

def conn_swap_rows(conn, i, j):
    tmp = conn[i]
    conn[i] = conn[j]
    conn[j] = tmp

def enum_conns(mainrow, n, conn):
    """Enumerates all possible red-blue point connections given a left to right
    diagonally initialized matrix."""
    if mainrow >= n:
        return

    if mainrow == 0:
        print_conn(conn)

    enum_conns(mainrow + 1, n, conn)

    for r in range(mainrow + 1, n):
        tmpconn = conn.copy()
        conn_swap_rows(tmpconn, mainrow, r)
        print_conn(tmpconn)
        enum_conns(mainrow + 1, n, tmpconn)

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

    conn_matrix = [[True, False, False],
                   [False, True, False],
                   [False, False, True]]
    enum_conns(0, 3, conn_matrix)
    ##plot_points(n, redpts, bluepts)

if __name__ == '__main__':
  main()