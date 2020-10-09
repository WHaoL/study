#---------------------------------------------------------
# 生成可执行文件 libzinx.so
PROJECT     = libzinx
OUTNAME     = $(PROJECT).so
#---------------------------------------------------------
# 文件后缀
SrcSuf      = c
SrcSuf2     = cpp
SrcSuf3     = cc
ObjSuf      = o
LibSuf      = so
LibSuf2     = a
#---------------------------------------------------------
# .o文件
OBJFILES    =  ./TcpDataChannel.$(ObjSuf)
OBJFILES    += ./utils.$(ObjSuf) 
OBJFILES    += ./zinx.$(ObjSuf) 
#---------------------------------------------------------
# 头文件目录
INCLUDEPATH =  -I /usr/include/
INCLUDEPATH += -I /usr/local/include 
# 库目录
LIBPATH     =  -L /usr/local/lib/
LIBPATH     += -L /usr/lib/ 
#---------------------------------------------------------
CC          =   g++
CXX         =   g++
LD          =   g++
# 编译选项
CFlag       =   $(INCLUDEPATH) -w -g -ggdb -fshort-wchar -std=c++11 -fPIC -pthread
#CFlag       =   $(INCLUDEPATH) -Wall -g -ggdb -fshort-wchar -std=c++11 -pthread

# 链接选项
LIBEXPORT   = -fvisibility=hidden
.DEFINES    = -DTRACE_LOG
LDFLAGS     +=  $(LIBPATH) 
LDFLAGS     +=  -l pthread       
LDFLAGS     +=  -shared  $(LIBEXPORT) $(.DEFINES)  
#---------------------------------------------------------
.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(LibSuf) .$(SrcSuf2) .$(LibSuf2) .$(SrcSuf3)

all:  $(OUTNAME) clean
# 生成so文件
$(OUTNAME):$(OBJFILES)
	@echo "creating $(OUTNAME) start..."
	$(LD) $(OBJFILES) -o $(OUTNAME) $(LDFLAGS) -ldl
	@echo "creating $(OUTNAME) end"
	strip $(OUTNAME)

# 安装
.PHONY : install
install:$(OUTNAME)
	cp $^  /usr/lib/
	cp *.h /usr/include/
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