#---------------------------------------------------------
# 生成可执行文件 execute
PROJECT     = execute
#---------------------------------------------------------
# .o文件
SrcSuf      = c
SrcSuf2     = cpp
SrcSuf3     = cc
ObjSuf      = o
LibSuf      = so
LibSuf2     = a
#---------------------------------------------------------
OBJFILES    = ./main_ByLiuYang.$(ObjSuf)      
#---------------------------------------------------------
# 头文件目录
INCLUDEPATH =  -I /usr/include/
INCLUDEPATH += -I /usr/local/include 
INCLUDEPATH += -I /usr/include/c++/4.8.2/
INCLUDEPATH += -I /usr/local/include/hiredis/
# /usr/include/zinx.h 
# /usr/include/ZinxTCP.h
# /usr/local/include/google/protobuf
# /usr/include/c++/4.8.2/random
# /usr/local/include/hiredis/hiredis.h


# 库目录
LIBPATH     =  -L /usr/local/lib/
LIBPATH     += -L /usr/lib/ 
# /usr/lib/libzinx.so
# /usr/local/lib/libprotobuf.so
# /usr/local/lib/libhiredis.so
#---------------------------------------------------------
CC          =   g++

# 编译选项
CFlag       =   $(INCLUDEPATH) -w -g -ggdb -fshort-wchar -std=c++11 -pthread
#CFlag       =   $(INCLUDEPATH) -Wall -g -ggdb -fshort-wchar -std=c++11 -pthread


# 链接选项
LDFLAGS     +=  $(LIBPATH) 
LDFLAGS     +=  -l pthread         
LDFLAGS     +=  -l zinx 
LDFLAGS     +=  -l protobuf
LDFLAGS     +=  -l hiredis    
#---------------------------------------------------------
.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(LibSuf) .$(SrcSuf2) .$(LibSuf2) .$(SrcSuf3)

all:  $(PROJECT) clean
# 生成可执行文件
$(PROJECT):$(OBJFILES)
	@echo "creating $(PROJECT) start..."
	$(CC) $(LDFLAGS) $(OBJFILES) -o $(PROJECT) 
	@echo "creating $(PROJECT) end"
#---------------------------------------------------------
# .c 生成 .o 文件
.$(SrcSuf).$(ObjSuf):
	@echo "Compiling $(PROJECT) $<"
	$(CC) $(CFlag) -c $< -o $@ 
#---------------------------------------------------------
# .cpp 生成 .o 文件
.$(SrcSuf2).$(ObjSuf):
	@echo "Compiling $(PROJECT) $<"
	$(CXX) $(CFlag) -c $< -o $@
#---------------------------------------------------------
# .cc 生成 .o 文件
.$(SrcSuf3).$(ObjSuf):
	@echo "Compiling $(PROJECT) $<"
	$(CXX) $(CFlag) -c $< -o $@
#---------------------------------------------------------
# 删除 .o 文件
clean:
	@echo "Cleaning $(PROJECT) project files"
	@rm -f $(OBJFILES) core
#---------------------------------------------------------
# make cleanall 删除 .o 文件 execute文件
.PHONY:cleanobj
cleanobj:
	-rm -f $(OBJFILES) 
.PHONY:cleanexe
cleanexe:
	-rm -f $(PROJECT) 
.PHONY:cleanall
cleanall:cleanobj cleanexe