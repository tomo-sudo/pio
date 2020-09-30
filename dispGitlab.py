import re
import sys
import os
import time  
import requests
from selenium import webdriver  
from lxml import etree
from pynput.keyboard import Controller,Key,Listener
from pathlib import Path

def writeRt(gitlabRt):
    tmpFilePath = "./gitlabState";
    tmpFileJudge = Path(tmpFilePath)

    if tmpFileJudge.is_file: 
        tmpFile = open(tmpFilePath, 'w')
    else:
        tmpFile = open(tmpFilePath, 'w+')

    tmpFile.truncate()
    tmpFile.write(gitlabRt)
    tmpFile.close()

def trig_enter(kb):
    kb.press(Key.enter)
    kb.release(Key.enter)

work_number = "UT000576"
password = "guo_4433"

def gitlab_judge():
    packName = sys.argv[1]

    driver = webdriver.Chrome()  
    
    driver.get("https://gitlabwh.uniontech.com/users/sign_in") 
    #driver.maximize_window() 
    
    time.sleep(1) 
    driver.find_element_by_id("username").send_keys(work_number)  
    driver.find_element_by_id("password").send_keys(password)  
    time.sleep(1) 
    #driver.find_element_by_id("remember_me").click()  
    driver.find_element_by_xpath("//input[@class='btn-success btn']").click()
    

    driver.find_element_by_id("project-filter-form-field").send_keys(packName)  

    kb = Controller()
    trig_enter(kb)
    time.sleep(1) 

    html = driver.page_source
    text = html.encode("utf8")
    empty="This user doesn't have any personal projects"

    if empty in html:
        print("this project does not exist")
        writeRt("0")
        return

    driver.find_element_by_xpath("//a[@class='text-plain']").click()

    html = driver.page_source
    text = html.encode("utf8")
    empty="No repository"

    if empty in html:
        writeRt("0")
        print("this project exists but is empty")
        return

    writeRt("1")
    time.sleep(5) 
#    driver.quit()   

    #html = driver.page_source
    #text = html.encode("utf8")
    #selector = etree.HTML(text)
    #token = selector.xpath("//a[@class='text-plain']")
    #print(token)
    

    #kb.press('a')
    #kb.release('a')
    #kb.press(Key.enter)
    #kb.release(Key.enter)
    
    #kb.type("hello world")

if __name__ == '__main__':
    gitlab_judge()
