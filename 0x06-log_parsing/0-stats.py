#!/usr/bin/python3
""" Log Parsing """

import sys

count = 0
code_status = {"200": 0, "301": 0, "400": 0, "401": 0,
               "403": 0, "404": 0, "405": 0, "500": 0}
total_size = 0

try:
    for line in sys.stdin:
        my_list = line.split(" ")
        if len(my_list) > 2:
            code = str(my_list[-2])
            size = int(my_list[-1])
            if code in code_status:
                code_status[code] += 1
            total_size += size
            count += 1
        if count == 10:
            print("File size: {:d}".format(total_size))
            for key, val in sorted(code_status.items()):
                if code_status[key] != 0:
                    print("{:}: {:d}".format(key, val))
            count = 0
except Exception:
    pass
finally:
    print("File size: {:d}".format(total_size))
    for key, val in sorted(code_status.items()):
        if code_status[key] != 0:
            print("{:}: {:d}".format(key, val))
