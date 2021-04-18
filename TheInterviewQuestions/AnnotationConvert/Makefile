#------------------目标 ------------------
EXECUTABLE := out	
#------------------文件后缀 ------------------
# .o文件
SrcSuf      = c
ObjSuf      = o
.SUFFIXES: 	.$(SrcSuf) .$(ObjSuf) 
#------------------源文件 ------------------
OBJFILES    +=  ./main.$(ObjSuf) \
				./AnnotationConvert.$(ObjSuf) \

#------------------编译选项 ------------------
# 头文件目录
INCLUDEPATH += 	-I /usr/include/ \
				-I /usr/local/include 
# C编译选项
CFlag += $(INCLUDEPATH) \
		 -w -g -ggdb -fshort-wchar \
		 -std=c11 
#------------------链接选项 ------------------
# 库目录
LIBPATH +=  -L /usr/lib/ \
			-L /usr/local/lib/     	 
# 动态库名称
LDLIBS 	:= 	-lpthread \
		  	-lprotobuf
# 链接选项		
LDFLAGS +=  $(LIBPATH) \
			$(LDLIBS)	
#------------------ ------------------
CC          =   gcc

all: $(EXECUTABLE) clean	

#------------------生成可执行文件 ------------------ 			
$(EXECUTABLE):$(OBJFILES)
	@echo "creating $(EXECUTABLE) start..."
	$(CC)  $(OBJFILES) -o $(EXECUTABLE) 
	@echo "creating $(EXECUTABLE) end"
#------------------.c 生成 .o 文件
.$(SrcSuf).$(ObjSuf):
	@echo "Compiling $(EXECUTABLE) $<"
	$(CC) $(CFlag) -c $< -o $@ 
#---------------------------------------------------------
.PHONY:clean
clean:
	rm -f *.o

.PHONY:cleanall
cleanall:
	rm -f $(EXECUTABLE) *.o
#---------------------------------------------------------



