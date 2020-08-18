ARCH=arm
CROSS_COMPILE=arm-linux-gnueabi-

BASEINCLUDE ?= /home/rlk/rlk_basic/runninglinuxkernel_4.0

mytest-objs := my_test.o

obj-m := mytest.o

all :
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) modules;

clean:
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -f *.ko
