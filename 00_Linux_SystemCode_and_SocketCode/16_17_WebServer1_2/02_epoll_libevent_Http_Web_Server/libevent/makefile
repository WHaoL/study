#makefile 

target = http_server
$(target):libevent_http.c main.c
	gcc -o $@ $^ -g -levent

.PHONY:clean
clean:
	-rm -f $(target)
