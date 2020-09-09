#---------------------------------------------------------
# 生成可执行文件 execute
PROJECT     = execute
#---------------------------------------------------------
# .o文件
SrcSuf      = c
SrcSuf2     = cpp
ObjSuf      = o
LibSuf      = so
LibSuf2     = a
#---------------------------------------------------------
#src=fig1.8_P14IntCell.cpp
#src+=fig1.11_P18.cpp
#OBJFILES=$(src:.cpp=.o)

OBJFILES    = ./CommandRecognition.$(ObjSuf) \
              ./StdInOutChannel.$(ObjSuf)    \
			  ./Roles.$(ObjSuf)              \
			  ./testzinx.$(ObjSuf)
			  #./CommandMassage.cpp.$(ObjSuf) \
#---------------------------------------------------------
# 头文件目录
#INCLUDEPATH =  -I /usr/local/include/hiredis/
#zinx.h ZinxTCP.h
INCLUDEPATH += -I /usr/include/

# 库目录
LIBPATH     =  -L /usr/local/lib/
# libzinx.so
LIBPATH     += -L /usr/lib/ 
#---------------------------------------------------------
CC          =   g++

# 编译选项
CFlag       =   $(INCLUDEPATH) -w -g -ggdb -fshort-wchar -std=c++11

# 链接选项
LDFLAGS     +=  $(LIBPATH) 
#LDFLAGS     +=	-l hiredis     
LDFLAGS     +=	-l pthread     
LDFLAGS     +=  -l zinx 
#---------------------------------------------------------
.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(LibSuf) .$(SrcSuf2) .$(LibSuf2)

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