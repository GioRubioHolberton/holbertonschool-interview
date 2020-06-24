#!/usr/bin/python3
""" UTF-8 validation """


def validUTF8(data):
    """ set represents a valid UTF-8 encoding. """

    num = 0

    for bit in data:
        env = format(bit, '#010b')[-8:]
        if num == 0:
            if env.startswith('110'):
                num = 1
            elif env.startswith('1110'):
                num = 2
            elif env.startswith('11110'):
                num = 3
            elif env.startswith('10'):
                return False
        else:
            if not env.startswith('10'):
                return False
            num -= 1
    return True
