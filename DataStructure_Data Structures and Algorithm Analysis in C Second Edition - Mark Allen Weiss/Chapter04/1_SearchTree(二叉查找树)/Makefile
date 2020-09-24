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

OBJFILES    =  ./tree.$(ObjSuf)  
OBJFILES    +=  ./testtree.$(ObjSuf)  

#---------------------------------------------------------
# 头文件目录
INCLUDEPATH += -I /usr/include/
INCLUDEPATH += -I /usr/local/include 

# 库目录
LIBPATH     += -L /usr/lib/ 
LIBPATH     += -L /usr/local/lib/
#---------------------------------------------------------
CC          =   gcc

# 编译选项
CFlag       =   $(INCLUDEPATH) -w -g -ggdb -std=c11 -l pthread 

# 链接选项
LDFLAGS     +=  $(LIBPATH)    
LDFLAGS     +=  -l pthread         
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