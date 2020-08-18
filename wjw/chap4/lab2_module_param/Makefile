ARCH=arm
CROSS_COMPILE=arm-linux-gnueabi-

BASEINCLUDE ?= /home/rlk/rlk_basic/runninglinuxkernel_4.0

mymodule-objs := module_parm.o

obj-m := mymodule.o

all :
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) modules;

clean:
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -f *.ko
