target=app
src=$(wildcard ./*.c)
objs=$(patsubst %.c, %.o, $(src))
$(target):$(objs)
	gcc $(objs) -o $(target)
	
# 使用模式匹配
%.o:%.c
	gcc -c $< -o $@

.pHONY:clean
clean:
	rm $(target) $(objs)

