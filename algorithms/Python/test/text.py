#!/usr/bin/python3
# coding=utf-8
# encoding=utf-8
# @Time        : 2021/2/5 12:18 下午
# @Version     : 1.0
# @Author      : BATTERIA
# @Description :
import os
import re
import sys
import getopt

custom_views = set()


def detect(path):
    with open(path) as file1:
        for line in file1:
            result = re.search('(?<=(/))(_|[a-zA-Z0-9])+(?=(\.xml))', line)
            if result is not None:
                custom_views.add(result.group())
        file1.close()


detect('conflict')

with open('result', mode='w') as file:
    for view in custom_views:
        file.write(view + '\n')
    file.close()
    print('file \'result\' is created in current dir')