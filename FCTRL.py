#!/usr/bin/env python
import sys

if __name__ == '__main__':
    # Precompute powers of 5 since max input is <= 1000000000
    powers_of_five = [5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625]

    cases = int(sys.stdin.readline())
    for i in range(0, cases):
        input_no = int(sys.stdin.readline())
        result = 0
        # Use formula for computing # of trailing zeros for factorials
        for j in range(0, 12):
            result += input_no / powers_of_five[j]
        print result
