cc=arm-linux-gnueabi-gcc
prom=test
obj=test.o
CFLAG=-static

$(prom):$(obj)
	$(cc) -o $(prom) $(obj) $(CFLAGS)

%.o:%.c
	$(cc) -c $< -o $@

clean:
	rm -rf $(obj) $(prom)
