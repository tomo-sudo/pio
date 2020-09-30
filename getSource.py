#! /usr/bin/python3

import requests
import re
import sys
import os
from pathlib import Path

def main():
    discFile = getSourcePack()
    tmpFilePath = "./dscFileName";
    tmpFileJudge = Path(tmpFilePath)

    if tmpFileJudge.is_file: 
        tmpFile = open(tmpFilePath, 'w')
    else:
        tmpFile = open(tmpFilePath, 'w+')

    tmpFile.truncate()
    tmpFile.write(discFile)
    tmpFile.close()

def getSourcePack():
    discFile=""
    packet=sys.argv[1]
    url = "https://packages.debian.org/source/buster/" + packet
    print(url)
    pro = {
        'https': 'https://proxy01.deepin.com:3128',
    }
    response = requests.get(url, proxies=pro)
    response.encoding = "utf-8"  
    sourcesList = re.findall(r'"http://.*?.debian.org/.*?/pool.*?"', response.text)
    print(sourcesList)
    
    for source in sourcesList:
        if ".dsc" in source:
            discFile = source

    packDirPath = "./" + packet
    packDir = Path(packDirPath)
    if not packDir.is_dir():
        packDirGet = "mkdir " + packDirPath
        os.system(packDirGet)
        
        for source in sourcesList:
            getSource = "wget -P " + packDirPath + " " + source
            os.system(getSource)

    return discFile

if __name__ == '__main__':
    main()
