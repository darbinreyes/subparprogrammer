# Implementation of the algorithm described in Dijkstra's Reasoning About
# Programs problem 2.

# coding style : https://www.python.org/dev/peps/pep-0008/
import random
import matplotlib.pyplot as plt # I will use matplotlib to draw points and lines. https://matplotlib.org/tutorials/introductory/usage.html#sphx-glr-tutorials-introductory-usage-py

class coloredPoint:
    """ Represents a colored point."""
    def __init__(self, color, x, y):
        """ Constructor."""
        self.color = color # 0 = red, 1 = blue.
        self.x = x
        self.y = y

def create_coordinates(n, coordsmin, coordsmax):
    """ Returns a list of n distinct numbers in the range coordsmin <= c <= coordsmax. min/max should be integers."""
    return random.sample(range(coordsmin, coordsmax + 1), n) # sample() takes random samples without replacement. This ensures distinct coordinates.

def create_points(n, xmin, xmax, ymin, ymax):
    """ Returns a list of n distinct point. color = 0 means red, 1 means blue """

    ####

    # Comment out these lines so I can do testing and development with the same
    # set of points.
    #xcoords = create_coordinates(n, xmin, xmax)
    #ycoords = create_coordinates(n, ymin, ymax)
    #print(xcoords)
    #print(ycoords)

    ###

    xcoords = [93, 4, 76, 47, 94, 11]
    ycoords = [31, 89, 59, 12, 27, 8]
    points = []
    for i in range(n):
        points.append(coloredPoint(0, xcoords[i], ycoords[i]))

    return points

def plot_points(conn_matrix, redpts, bluepts):
    """ Plots the given points."""

    fig, ax = plt.subplots() # Matplotlib recipe for basic plotting.

    # Plot red points.
    for p in redpts:
        ax.plot(p.x, p.y, marker='.', color='red', markersize=12)

    # Plot blue points.
    for p in bluepts:
        ax.plot(p.x, p.y, marker='.', color='blue', markersize=12)

    # This connects the points according to the given boolean matrix.
    # Let the row index correspond to blue points and the column index
    # correspond to red points.
    # conn_matrix = [[False, True, False], # Hard-coded connection matrix.
    #                [True, False, False],
    #                [False, False, True]]

    # Connect the points with lines according to the above matrix.
    for i in range(len(conn_matrix)):
        for j in range(len(conn_matrix[i])):
            if conn_matrix[i][j]:
                # Plot a line.
                ax.plot([bluepts[i].x, redpts[j].x], [bluepts[i].y, redpts[j].y], color='black')

    # Show the figure and block execution, if block=False you never see the
    # figure because it disappears once execution continues.
    plt.show(block=True)

# For testing purposes, count the number of possible red-blue point connection
# matrices.
print_count = 0

def print_conn(conn, *args):
    """ Prints the given connection matrix."""
    global print_count # See above.
    print_count += 1
    print(print_count)

    # Print the connection matrix 1 row at a time.
    for i in range(len(conn)):
        print(conn[i])

def conn_swap_rows(conn, i, j):
    """ Swap rows i and j of matrix conn."""

    if i == j: # Nothing to do.
        return

    tmp = conn[i]
    conn[i] = conn[j]
    conn[j] = tmp

def enum_conns_helper(mainrow, conn, conn_matrix_func, redpts=[], bluepts=[]):
    """ Recursive helper function for enumerating all possible connection matrices."""

    n = len(conn)

    for r in range(mainrow, n): # For every row at and subsequent to mainrow.
        tmpconn = conn.copy() # Take a copy of the original matrix.
        conn_swap_rows(tmpconn, mainrow, r) # Swap mainrow and current row.

        if mainrow == r:
            # No swap occurred, avoid printing a duplicate matrix. The
            # recursive call below will print any other permutations if any
            # exist.
            pass
        else:
            # print_conn(tmpconn) # Print this connection matrix.
            conn_matrix_func(tmpconn, redpts, bluepts)

        # Recursively print the next possible connection matrix.
        enum_conns_helper(mainrow + 1, tmpconn, conn_matrix_func, redpts, bluepts)

def enum_conns(conn, conn_matrix_func, redpts=[], bluepts=[]):
    """ Enumerates all possible red-blue point connections given a top-left to
    bottom-right diagonally initialized matrix."""

    # Enumerate the n matrices obtained by swapping the 0th row with each
    # subsequent row, including swapping the 0th row with the 0th row [sic].
    # I call these the "primary" connection matrices. For each primary
    # connection matrix, we recursively enumerate its permutations.
    # for r in range(n): # For each row in the matrix.
    #     tmpconn = conn.copy() # Take a copy of the given matrix.
    #     conn_swap_rows(tmpconn, 0, r)

    #     # TODO: Instead of printing the matrix add a argument to this function
    #     # that is a function itself, and that function is called with the
    #     # connection matrix as its argument.
    #     print_conn(tmpconn) # Print

    #     # Recursively enumerate permutations of the primary matrix tmpconn.
    #     enum_conns_helper(1, n, tmpconn)

    #####
    #####
    #####

    # Just a thought on simplification.
    tmpconn = conn.copy() # Take a copy of the given matrix.
    #print_conn(tmpconn)
    conn_matrix_func(tmpconn, redpts, bluepts)
    enum_conns_helper(0, tmpconn, conn_matrix_func, redpts, bluepts)


def init_conn_matrix(n):
    """ Returns a top-left to bottom-right diagonally initialized matrix."""
    #pass # TODO Implement me.

    result = []
    for i in range(n):
        row = []
        for j in range(n):
            if i == j:
                row.append(True)
            else:
                row.append(False)
        result.append(row)

    return result


def has_intersection():
    """ Determines if the given set of red-blue connections has an intersection
    and if so returns the first intersection that is encountered, i.e. returns
    the 4 points participating in the intersection."""
    pass # TODO Implement me.

def do_flip_operation():
    """ Performs the flip operation that removes the given intersection."""
    pass # TODO Implement me.

def main():
    """ Main function."""
    n = 3
    xmin = 0
    xmax = 100
    ymin = 0
    ymax = 100
    pts = create_points(2 * n, xmin, xmax, ymin, ymax)
    redpts = pts[0:n] # Make half of the points red, half blue.
    bluepts = pts[n:]
    for p in bluepts:
        p.color = 1

    conn_matrix = init_conn_matrix(n)
    #enum_conns(conn_matrix, print_conn)
    #plot_points(conn_matrix, redpts, bluepts)
    enum_conns(conn_matrix, plot_points, redpts, bluepts)


if __name__ == '__main__':
  main()

""" Calculation of intersection, n = 3, plot 1.
MacBook-Air:python3tutorial darbinreyes$ python3.8
Python 3.8.1 (default, Jan  7 2020, 01:35:47)
[Clang 11.0.0 (clang-1100.0.33.12)] on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>> 93-47
46
>>> 31-12
19
>>> 27-89
-62
>>> 19/46
0.41304347826086957
>>> 12 - (19/46)*47
-7.413043478260871
>>> 27 - (-62/90)*94
91.75555555555556
>>> -62/90
-0.6888888888888889
>>> ((19/46) - (-62/90))
1.1019323671497585
>>> (12 - (19/46)*47) - (27 - (-62/90)*94)
-99.16859903381643
>>> (-((12 - (19/46)*47) - (27 - (-62/90)*94)))/((19/46) - (-62/90))
89.99517755370452
>>> (19/46) * (-((12 - (19/46)*47) - (27 - (-62/90)*94)))/((19/46) - (-62/90)) +(12 - (19/46)*47)
29.75887768522578
>>> (-62/90) * ((-((12 - (19/46)*47) - (27 - (-62/90)*94)))/((19/46) - (-62/90))) + (27 - (-62/90)*94)
29.758877685225777
>>>

"""