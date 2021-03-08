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

custom_views = list()


def detect(path):
    with open(path) as file1:
        for line in file1:
            result = re.search('.+com.bilibili.bililive.streaming.+', line)
            if result is not None:
                custom_views.append(result.group())
        file1.close()


detect('map-tribe.txt')

custom_views.sort()
with open('result-tribe', mode='w') as file:
    for view in custom_views:
        file.write(view + '\n')
    file.close()
    print('file \'result\' is created in current dir')