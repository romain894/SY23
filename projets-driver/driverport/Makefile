# Makefile

KDIR=/lib/modules/3.16.0-6-amd64/build

obj-m := driverport.o

MODULE= $(obj-m:.o=.ko)

all:
	cp ../driverclassgpio-bin/Module.symvers .
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD)  modules

install:
	sudo insmod $(MODULE) direction=0

uninstall:
	sudo rmmod $(MODULE)

clean:
	rm -f *~
	$(MAKE) -C $(KDIR) M=$(PWD) clean
