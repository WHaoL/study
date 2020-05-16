#---------------------------------------------------------
# 生成可执行文件 execute
PROJECT     = execute
#---------------------------------------------------------
# .o文件
SrcSuf      = cpp
ObjSuf      = o
LibSuf      = so

OBJFILES    = ./5_01_byteOrder.$(ObjSuf)
#---------------------------------------------------------
CC          = g++
CFlag       = -w -g -ggdb -fshort-wchar -std=c++11  
#---------------------------------------------------------
.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(LibSuf)

all:  $(PROJECT) clean

$(PROJECT):$(OBJFILES)
	@echo "creating $(PROJECT) start..."
	$(CC) $(OBJFILES) -o $(PROJECT) 
	@echo "creating $(PROJECT) end"


clean:
	@echo "Cleaning $(PROJECT) project files"
	@rm -f $(OBJFILES) core

.$(SrcSuf).$(ObjSuf):
	@echo "Compiling $(PROJECT) $<"
	$(CC) -MM $^ 
	$(CC) -c $< -o $@ $(CFlag) 


.PHONY:cleanobj
cleanobj:
	-rm -f $(OBJFILES) 
.PHONY:cleanexe
cleanexe:
	-rm -f $(PROJECT) 
.PHONY:cleanall
cleanall:cleanobj cleanexe