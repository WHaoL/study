# 根据 *.c 和 .h
# 生成动态库 libcalc.so

#---------------------------------------------------------
# 工程名 / 库名 # 生成静态库 libcalc.so  计算简单的加减乘除
PROJECT     = libcalc
OUTNAME     = $(PROJECT).so
#---------------------------------------------------------
# 头文件目录
INCLUDEPATH = -I./include/
#---------------------------------------------------------
CC          = gcc
LD          = gcc
#---------------------------------
# 编译依赖项
CFlag       = -w -g -ggdb -fshort-wchar -std=c11 -fPIC $(INCLUDEPATH)
#---------------------------------
# 链接依赖项
LIBEXPORT   = -fvisibility=hidden
.DEFINES    = -DTRACE_LOG
CxxFlage    = -shared  $(LIBEXPORT) $(.DEFINES)
#---------------------------------------------------------
# .o文件
SrcSuf      = c
ObjSuf      = o
LibSuf      = so

OBJFILES    = ./add.$(ObjSuf)\
              ./div.$(ObjSuf)\
              ./mult.$(ObjSuf)\
              ./sub.$(ObjSuf)\
#---------------------------------------------------------
.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(LibSuf)


all:  $(PROJECT) clean

$(PROJECT):$(OBJFILES)
	@echo "Linking $(OUTNAME) start..."
	$(LD) $(OBJFILES) -o $(OUTNAME) $(CxxFlage) -ldl
	@echo "Linking $(OUTNAME) end"

clean:
	@echo "Cleaning $(PROJECT) project files"
	@rm -f $(OBJFILES) core

.$(SrcSuf).$(ObjSuf):
	@echo "Compiling $(PROJECT) $<"
	$(CC) -c $< -o $@  $(CFlag)


# [root@lwh 03dynamicLib]# make
# Compiling libcalc add.c
# gcc -c add.c -o add.o  -w -g -ggdb -fshort-wchar -std=c11 -fPIC -I./include/
# Compiling libcalc div.c
# gcc -c div.c -o div.o  -w -g -ggdb -fshort-wchar -std=c11 -fPIC -I./include/
# Compiling libcalc mult.c
# gcc -c mult.c -o mult.o  -w -g -ggdb -fshort-wchar -std=c11 -fPIC -I./include/
# Compiling libcalc sub.c
# gcc -c sub.c -o sub.o  -w -g -ggdb -fshort-wchar -std=c11 -fPIC -I./include/
# Linking libcalc.so start...
# gcc ./add.o ./div.o ./mult.o ./sub.o  -o libcalc.so -shared  -fvisibility=hidden -DTRACE_LOG -ldl
# Linking libcalc.so end
# Cleaning libcalc project files

# [root@lwh 03dynamicLib]# ls
# add.c  div.c  include  libcalc.so  main  Makefile  mult.c  sub.c

# [root@lwh 03dynamicLib]# tree
# .
# ├── add.c
# ├── div.c
# ├── include
# │   └── head.h
# ├── libcalc.so
# ├── main
# │   ├── main.c
# │   └── makefile
# ├── Makefile
# ├── mult.c
# └── sub.c
# 
# 2 directories, 9 files
# [root@lwh 03dynamicLib]#