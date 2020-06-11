# 下载安装包

https://tangentsoft.com/mysqlpp/home 

- tar -zxvf mysql++-3.2.5.tar.gz 

- cd mysql++-3.2.5/





查看README-Linux.txt

1、首先它告诉你，mysql++必须得有mysql c API才能正常工作，mysql c API就需要安装mysqlclient.

- ubuntu下
  - sudo apt-get install libmysqlclient15-dev
- CentOS下
  - yum install mysql-devel

2、其次它告诉你，为了防止动态链接器找不见，最好不要装在非主流的目录下，它建议你放/usr下面

- ./configure --prefix=/usr
- ./configure --prefix=/usr –enable-thread-check(据说这样可以支持多线程，我没尝试)  

确定是否安装mysqlclient(可选) -- 利用locate查找文件位置

- locate mysqlclient





安装

- make
- make install



如果一切全程没有, include  lib 就应该在你指定的目录下了



[root@lwh mysql++-3.2.5]# find / -name "libmysqlpp.so"
/usr/lib/libmysqlpp.so
/usr/local/lib/libmysqlpp.so
/usr/local/mysql++-3.2.5/libmysqlpp.so



进入到测试文件夹下/home/lwh/Desktop/mysql++-3.2.5/examples

编译一个Demo：

g++ -o simple1 simple1.cpp -I /usr/local/include/mysql++/ -lmysqlpp -I /usr/include/mysql/ 





```makefile
#---------------------------------------------------------
# 生成可执行文件 execute
PROJECT     = execute
#---------------------------------------------------------
# .o文件
SrcSuf      = cpp
ObjSuf      = o
LibSuf      = so

OBJFILES    = ./test.$(ObjSuf)


INCLUDEPATH =  -I /usr/local/include/mysql++/  -I /usr/include/mysql/ 
#---------------------------------------------------------
CC          = g++
CFlag       = -w -g -ggdb -fshort-wchar -std=c++11  $(INCLUDEPATH)
CFlagLink   = -lmysqlpp $(INCLUDEPATH)
#---------------------------------------------------------
.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(LibSuf)

all:  $(PROJECT) clean

$(PROJECT):$(OBJFILES)
	@echo "creating $(PROJECT) start..."
	$(CC) $(OBJFILES) -o $(PROJECT) $(CFlagLink)
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
```

