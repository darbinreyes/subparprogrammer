import math

def VII_4_part_or_parts_v1(b, a):
    rp = math.gcd(b,a)
    ret = -1 # 0 = part. 1 = parts.
    m = -1
    n = -1

    if rp == 1: # b, a relatively prime.
        ret = 1 # parts.
        m = b
        n = a
    elif rp > 1 and (a % b == 0): # b, a NOT relatively prime.
        ret = 0 # part.
        m = 1
        n = a // b
    elif rp > 1 and (a % b != 0):
        ret = 1 # parts.
        m = b // rp
        n = a // rp
    else:
        assert(0)

    return ret, m, n

if __name__ == "__main__":
    # Test cases for VII_4_part_or_parts_v1().
    b = 3
    a = 7
    print("ret, m, n = ", VII_4_part_or_parts_v1(b, a))

    b = 6
    a = 7
    print("ret, m, n = ", VII_4_part_or_parts_v1(b, a))

    b = 2
    a = 6
    print("ret, m, n = ", VII_4_part_or_parts_v1(b, a))

    b = 3
    a = 12
    print("ret, m, n = ", VII_4_part_or_parts_v1(b, a))

    b = 4
    a = 6
    print("ret, m, n = ", VII_4_part_or_parts_v1(b, a))

    b = 8
    a = 12
    print("ret, m, n = ", VII_4_part_or_parts_v1(b, a))