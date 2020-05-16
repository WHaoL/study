target:server.c client.c
	gcc server.c -o server -levent
	gcc client.c -o client -levent

.PHONY:clean
clean:
	-rm *.o server client -f
