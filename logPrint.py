#!/usr/bin/python3
import datetime
import sys
import os


def logprint(logstr):
    try:
        raise Exception
    except:
        f = sys.exc_info()[2].tb_frame.f_back
    backco_name = f.f_code.co_name
    folder, backco_filename = os.path.split(f.f_code.co_filename)
    backlineno =  f.f_lineno
    dt_ms = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')  # 含微秒的日期时间，来源 比特量化
    logoutputstr = '['+dt_ms+'      '+backco_filename+'::'+backco_name+'::'+str(backlineno)+']'+logstr
    print(logoutputstr)
    if os.path.exists('../log'):
        pass
    else:
        os.mkdir('../log')
    file = open("../log/autoCVE.log", "a", encoding="utf")
    file.write(logoutputstr + '\n')
    file.close()



