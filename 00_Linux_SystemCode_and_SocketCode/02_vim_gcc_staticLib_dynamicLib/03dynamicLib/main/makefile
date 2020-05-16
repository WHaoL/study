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

# 头文件目录
INCLUDEPATH = -I../include/
#---------------------------------------------------------

#依赖库所在的目录
LIBPATH     = -L../
#---------------------------------------------------------

#依赖库的库名
#LIBS        = -l../libcalc.so
LIBS2       = -l calc
#---------------------------------------------------------

CC          = gcc
CFlag       = -w -g -ggdb -fshort-wchar -std=c11  $(INCLUDEPATH)
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