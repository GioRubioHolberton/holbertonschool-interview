#!/usr/bin/python3
""" Lockboxes """
""" Write a method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):

    for i in range(1, len(boxes) - 1):
        validator = 0
        for box in range(len(boxes)):
            if i in boxes[box] and i != box:
                validator = 1
                break
        if validator == 0:
            return False
    return True
