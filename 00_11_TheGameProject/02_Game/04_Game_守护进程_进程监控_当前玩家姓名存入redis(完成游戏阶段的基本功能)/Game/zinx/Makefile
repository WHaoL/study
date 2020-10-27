all:libzinx.so libzinx.a

libzinx.so:*.c* *.h
	g++ -std=c++11 -fPIC -shared $^ -o $@

libzinx.a:./*.cpp  
	g++ -c -std=c++11 -fPIC  $^ 
	ar -rc $@ *.o

install:
	cp libzinx.so /usr/lib/
	cp libzinx.a  /usr/lib/
	cp *.h /usr/include/

.PHONY:clean
clean:
	@rm -f *.o 
	@rm -f ./libzinx.a
	@rm -f ./libzinx.so
