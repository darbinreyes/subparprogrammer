# Implementation of the algorithm described in Dijkstra's Reasoning About
# Programs problem 2.

""" Performs a flip operation on a random set of points until there are no intersections."""

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

class FiniteLine:
    """ Represents a line connecting two colored points."""
    def setline(self, slp, yintercept):
        """ Construct a line by slope and y intercept.
        Standard equation for representing a line y = m * x + b =
        slp * x + yintercept. """
        self.slp = slp
        self.yintercept = yintercept

    def __init__(self, point0, point1):
        """ Construct a line from two points."""
        # TODO: How to address possible errors due to floating point precision?

        # Calculate the slope = delta_y/delta_x.
        if point0.x > point1.x:
            # Save the point with the greater x-coordinate in self.point1 and
            # save the point with the lesser x-coordinate in self.point0. This
            # will be used in the self.intersection() test.
            self.point1 = point0
            self.point0 = point1
        else:
            self.point1 = point1
            self.point0 = point0

        dx = self.point1.x - self.point0.x
        dy = self.point1.y - self.point0.y
        slp = dy/dx

        # Calculate the y-intercept. y - m * x = b
        yintercept = point0.y - slp * point0.x

        yintercept2 = point1.y - slp * point1.x # TODO: Fix yintercept2 != yintercept

        self.setline(slp, yintercept)
        #print("Line: y = " + str(self.slp) + " * x + " + str(self.yintercept) + " || " + str(yintercept2))

    def intersects(self, other_finite_line):
        """ Determines if this line intersects with other_finite_line. The lines
        intersect if the x-coordinate of the computed intersection lies between
        the x-range of this line and the x-range of other_finite_line. If the lines
        intersect, the x-coordinate of the intersection is returned, if they do
        not intersect, None is returned. ERROR NOTE: This implementation does not
        take into account the floating point errors, see
        https://docs.python.org/3/tutorial/floatingpoint.html
        https://docs.python.org/3/tutorial/stdlib2.html#decimal-floating-point-arithmetic"""

        # Calculate the x-coordinate of the intersection between this line and
        # other_finite_line. The calculation is done by solving for x in the
        # equation obtained from setting both line's equations equal to each other.
        dslp = self.slp - other_finite_line.slp
        if dslp == 0:
            # The lines do not intersect because they have the same slope.
            # Catch this here to prevent an exception:
            # ZeroDivisionError: float division by zero
            print("dslp == 0")
            return None
        dyintercept = self.yintercept - other_finite_line.yintercept
        x_intersection = -dyintercept/dslp

        # Lines finite lines intersect if the calculated x-intersection lies
        # between the x-range of both lines.
        if x_intersection >= self.point0.x and x_intersection <= self.point1.x \
        and x_intersection >= other_finite_line.point0.x and \
        x_intersection <= other_finite_line.point1.x:
            return x_intersection

        # The lines do not intersect.
        return None

    def gety(self, xval):
        """ Returns the y value at xval according to y = slp * x + yintercept."""
        return self.slp * xval + self.yintercept

def create_coordinates(n, coordsmin, coordsmax):
    """ Returns a list of n distinct numbers in the range coordsmin <= c <= coordsmax. min/max should be integers."""
    return random.sample(range(coordsmin, coordsmax + 1), n) # sample() takes random samples without replacement. This ensures distinct coordinates.

def create_points(n, xmin, xmax, ymin, ymax):
    """ Returns a list of n distinct point. color = 0 means red, 1 means blue """

    ####

    # Comment out these lines so I can do testing and development with the same
    # set of points.
    xcoords = create_coordinates(n, xmin, xmax)
    ycoords = create_coordinates(n, ymin, ymax)
    print(xcoords)
    print(ycoords)

    ###

    #xcoords = [93, 4, 76, 47, 94, 11] # n = 3
    #ycoords = [31, 89, 59, 12, 27, 8]
    #xcoords = [98, 16, 89, 18, 37, 14]
    #ycoords = [5, 73, 67, 6, 27, 17]
    #xcoords = [68, 8, 64, 46, 50, 90, 9, 85, 82, 91, 66, 23, 84, 26, 65, 28, 0, 97, 100, 88] # n = 10, This revealed the divide zero error in FiniteLine.intersect().
    #ycoords = [72, 88, 85, 80, 11, 22, 21, 47, 61, 38, 92, 93, 91, 36, 83, 51, 19, 33, 67, 90]
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
    lines = []
    for i in range(len(conn_matrix)):
        for j in range(len(conn_matrix[i])):
            if conn_matrix[i][j]:
                # Create a FiniteLine object for each line
                tmp_line = FiniteLine(bluepts[i], redpts[j])
                xis = lines_intersect(lines, tmp_line)
                for x_intersection in xis:
                    # Plot a point at the occurrence of each intersection
                    ax.plot(x_intersection, tmp_line.gety(x_intersection), marker='.', color='green', markersize=12)

                lines.append(tmp_line)
                # Plot a line.
                ax.plot([bluepts[i].x, redpts[j].x], [bluepts[i].y, redpts[j].y], color='black')

    # Show the figure and block execution, if block=False you never see the
    # figure because it disappears once execution continues.
    plt.show(block=True)
    return lines

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

def lines_intersect(lines, newline):
    """ Determines if newline intersects with any line in the list lines."""
    # TODO: It may be more efficient to test for overlapping x-ranges before
    # calculating x-intercept. This could be implemented in FiniteLine.intersects().
    xis = [] # Array of x coordinates of each intersection, if any.
    for line in lines:
        x_intersection = line.intersects(newline)
        if x_intersection != None:
            xis.append(x_intersection)


    return xis

def lines_intersect_index(lines):
    """ Returns the index of the first pair of lines that intersect."""
    for i in range(len(lines)):
        for j in range(len(lines)):
            if i != j:
                if lines[i].intersects(lines[j]) != None:
                    return i, j
    return None, None

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
    n = 10
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
    i = 0
    j = 0
    while i != None and j != None:
        conn_swap_rows(conn_matrix, i, j)
        lines = plot_points(conn_matrix, redpts, bluepts)
        i, j = lines_intersect_index(lines)
        print(i, j)
    #enum_conns(conn_matrix, plot_points, redpts, bluepts)


if __name__ == '__main__':
  main()
