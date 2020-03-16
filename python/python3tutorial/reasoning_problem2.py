# coding style : https://www.python.org/dev/peps/pep-0008/
# recommended way implementing a C like struct.: https://docs.python.org/3/tutorial/classes.html#odds-and-ends
# I will use matplotlib to draw points and lines. https://matplotlib.org/tutorials/introductory/usage.html#sphx-glr-tutorials-introductory-usage-py
import random

class coloredPoint:
    def __init__(self, color, x, y):
        self.color = color # 0 = red, 1 = blue.
        self.x = x
        self.y = y

def main():
    print("hello")
    p0 = coloredPoint(0, 7, 5)
    p1 = coloredPoint(0, 3, 1)
    print (p0.x, p1.x)
    # random.sample(range(xmin, xmax+1), n)

if __name__ == '__main__':
  main()