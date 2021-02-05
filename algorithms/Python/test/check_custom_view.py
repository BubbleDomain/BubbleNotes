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

white_list = list(('TextView', 'ImageView', 'FrameLayout', 'LinearLayout', 'merge', 'include', 'GridLayout',
                   'ProgressBar', 'CheckBox', 'EditText', 'RelativeLayout', 'RecyclerView', 'fragment',
                   'ScrollView', 'Switch', 'GridView', 'ListView', 'ViewPager2', 'CardView', 'View', 'RadioGroup',
                   'ViewFlipper', 'HorizontalScrollView', 'Button', 'SurfaceView', 'TextSwitcher', 'NumberPicker',
                   'RadioButton', 'ViewStub', 'Space'))
white_list_prefix = list(('com.facebook.+', 'tv.danmaku.+', 'androidx.+', 'com.google.+',
                          'com.bilibili.magicasakura.+', 'com.bilibili.lib.+', 'com.bilibili.app.+'))
custom_views = set()


def prefix_filter(target):
    for prefix in white_list_prefix:
        result = re.match(prefix, target)
        if result:
            return 0
    return 1


def detect(path):
    for new_dir in os.listdir(path):
        with open(path + '/' + new_dir) as file1:
            for line in file1:
                result = re.search('(?<=<)(\\.|[a-zA-Z0-9])+', line)
                if result and prefix_filter(result.group()) and result.group() not in white_list:
                    custom_views.add(result.group())
            file1.close()


opts, args = getopt.getopt(sys.argv[1:], 'p:e:', ['path=', 'extra='])
if len(opts) == 0:
    print("please enter path with -p(--path)")
for opt, arg in opts:
    if opt in ['--path', '-p']:
        detect(arg)
    if opt in ['--extra', '-e']:
        detect(arg)

if len(custom_views) > 0:
    with open('result', mode='w') as file:
        for view in custom_views:
            file.write(view + '\n')
        file.close()
        print('file \'result\' is created in current dir')
