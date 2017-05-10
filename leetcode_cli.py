#!/usr/bin/env python3
import json
import subprocess
import sys
from os.path import expanduser
home = expanduser("~")

#script to automatically cache leetcode questions
accepted_language=['c','cpp','csharp','golang','java','javascript','python','ruby','swift']

def init_leetcode_questions(language):
    fp = open("%s/.lc/all.json"%(home))
    leetcode_json = json.load(fp)

    for i in range(len(leetcode_json)):
        id=leetcode_json[i]['id']
        print(id)
        cmd = "leetcode show %d -gx -l %s "%(id, language)
        cmd_args=cmd.split()
        print(cmd_args)
        subprocess.call(cmd_args, stdout=subprocess.PIPE)

def validate(code):
    ret = False
    for template in accepted_language:
        if code == template:
            ret= True
    return ret

def help_exit():
    print ('''format:
        leetcode_cli.py - if no language option, use default language cpp
        leetcode_cli.py [language]

        language accepted list: "c","cpp","csharp","golang","java","javascript","python","ruby","swift"''')

if __name__ == "__main__":
    if len(sys.argv) < 2:
        code = 'cpp'
    else:
        code = sys.argv[1]

    if True == validate(code):
        init_leetcode_questions(code)
    else:
        help_exit()
