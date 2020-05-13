#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    if n <= 1 or n is None:
        return 0
    r = n;
    i = 2
    total = 0
    while r != 1:
        if r % i == 0:
            while r != 1 and r % i == 0:
                r = r / i
                total += i
        i += 1
    return total
