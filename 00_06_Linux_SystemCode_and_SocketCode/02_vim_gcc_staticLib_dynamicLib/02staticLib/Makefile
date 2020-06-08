# 根据 *.c 和 .h
# 生成静态库 libcalc.a

#---------------------------------------------------------
# 工程名 / 库名 # 生成静态库 libcalc.a  计算简单的加减乘除
PROJECT     = libcalc
OUTNAME     = $(PROJECT).a
#---------------------------------------------------------
# 头文件目录
INCLUDEPATH = -I./include/
#---------------------------------------------------------
# .o文件
SrcSuf      = c
ObjSuf      = o
LibSuf      = a

OBJFILES    = ./add.$(ObjSuf)\
              ./div.$(ObjSuf)\
              ./mult.$(ObjSuf)\
              ./sub.$(ObjSuf)\
#---------------------------------------------------------

CC          = gcc
LD          = ar rcs

# 编译
CFlag       = -w -g -ggdb -fshort-wchar -std=c11 $(INCLUDEPATH)
#---------------------------------------------------------
.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(LibSuf)

all:  $(PROJECT) clean

$(PROJECT):$(OBJFILES)
	@echo "Linking $(OUTNAME) start..."
	$(LD) $(OUTNAME) $(OBJFILES)
	@echo "Linking $(OUTNAME) end"

clean:
	@echo "Cleaning $(PROJECT) project files"
	@rm -f $(OBJFILES) core

.$(SrcSuf).$(ObjSuf):
	@echo "Compiling $(PROJECT) $<"
	$(CC) -c $< -o $@ $(CFlag)


# [root@lwh 02staticLib]# make
# Compiling libcalc add.c
# gcc -c add.c -o add.o -w -g -ggdb -fshort-wchar -std=c11 -I./include/
# Compiling libcalc div.c
# gcc -c div.c -o div.o -w -g -ggdb -fshort-wchar -std=c11 -I./include/
# Compiling libcalc mult.c
# gcc -c mult.c -o mult.o -w -g -ggdb -fshort-wchar -std=c11 -I./include/
# Compiling libcalc sub.c
# gcc -c sub.c -o sub.o -w -g -ggdb -fshort-wchar -std=c11 -I./include/
# Linking libcalc.a start...
# ar rcs libcalc.a ./add.o ./div.o ./mult.o ./sub.o 
# Linking libcalc.a end
# Cleaning libcalc project files

# [root@lwh 02staticLib]# ls
# add.c  div.c  include  libcalc.a  main  Makefile  mult.c  sub.c

# [root@lwh 02staticLib]# tree
# .
# ├── add.c
# ├── div.c
# ├── include
# │   └── head.h
# ├── libcalc.a
# ├── main
# │   ├── main.c
# │   └── makefile
# ├── Makefile
# ├── mult.c
# └── sub.c
# 
# 2 directories, 9 files
# [root@lwh 02staticLib]# 