
# 生成so文件：   gcc libcalc.so add.c div.c mult.c sub.c -fPIC -shared -I./include
# 根据动态库生成可执行文件： gcc main.c -o execute -L ../ -I ../include/ -l calc
# 
# 执行时遇到动态库找不到的问题： [root@lwh main]# ./execute 
# ./execute: error while loading shared libraries: libcalc.so: cannot open shared object file: No such file or directory
# [root@lwh main]# vim /etc/ld.so.conf  把动态库路径写到这个配置文件中
# [root@lwh main]# sudo ldconfig 
# [root@lwh main]# ./execute 
# a = 20, b = 12
# a + b = 32
# a - b = 8
# a * b = 240
# a / b = 1.666667
# [root@lwh main]# 



# 根据main.c libcalc.so head.h 
# 生成可执行文件 execute
#---------------------------------------------------------
# 工程名  计算简单的加减乘除
PROJECT     = execute
#---------------------------------------------------------
# .o文件
SrcSuf      = c
ObjSuf      = o
LibSuf      = so

OBJFILES    = ./main.$(ObjSuf)
#---------------------------------------------------------
#依赖库的库名
#LIBS        = -l../libcalc.so
LIBS2       = -l calc
#---------------------------------------------------------
CC          = gcc

# 头文件目录
INCLUDEPATH = -I../include/
#依赖库所在的目录
LIBPATH     = -L../

# 编译依赖项
CFlag       = -w -g -ggdb -fshort-wchar -std=c11  $(INCLUDEPATH)
# 链接依赖项
CxxFlage    = $(INCLUDEPATH) $(LIBPATH)
#---------------------------------------------------------
.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(LibSuf)

all:  $(PROJECT) clean

$(PROJECT):$(OBJFILES)
	@echo "creating $(PROJECT) start..."
	$(CC) $(OBJFILES) -o $(PROJECT) $(CxxFlage) $(LIBS2) 
	@echo "creating $(PROJECT) end"


clean:
	@echo "Cleaning $(PROJECT) project files"
	@rm -f $(OBJFILES) core

.$(SrcSuf).$(ObjSuf):
	@echo "Compiling $(PROJECT) $<"
	$(CC) -c $< -o $@ $(CFlag) 