val= fileOp.o userInfo.o

CFLAG =  -I.     #-Werror 在编译时会将warning看成error

dep_files:=$(patsubst %, .%, d, $(val))

dep_files:=$(wildcard $(dep_files))

test:$(val)
	gcc -o  userInfo `mysql_config --cflags --libs` -lpthread  $^

ifneq ($(depfiles),)
include $(dep_files)
endif

%.o:%.c
	gcc $(CFLAG)  -c -g -o  $@ $< -MD -MF .$@.d 

clean:
	rm *.o userInfo .*.d

ditclean:
	rm $(dep_files)



#.o 文件比对应的.c文件新，该.c文件方可参与编译
# x:y 其中x为目标文件，y为依赖文件
# $@表示目标文件 $<表示第一个依赖文件 $^表示所有的依赖文件
