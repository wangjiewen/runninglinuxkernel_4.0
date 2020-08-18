ARCH=arm
CROSS_COMPILE=arm-linux-gnueabi-

BASEINCLUDE ?= /home/rlk/rlk_basic/runninglinuxkernel_4.0

myexp-objs := export_sym.o
myexpuse-objs := use_export_sym.o

obj-m := myexp.o
obj-m += myexpuse.o

all :
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) modules;

clean:
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -f *.ko
