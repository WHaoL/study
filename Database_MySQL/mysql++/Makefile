# 头文件目录
CXXFLAGS := -I/usr/include/mysql 			\
			-I/usr/local/include/mysql++ 

# 库目录		
LDFLAGS := -L/usr/local/lib					\
		   -L/usr/lib64/mysql/
# 动态库
LDLIBS := -lmysqlpp 						\
		  -lmysqlclient

# 源文件
EXECUTABLE := helloMySQL++

all: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) *.o