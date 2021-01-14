# Makefile
# simulation
KDIR=/lib/modules/3.16.0-6-amd64/build

obj-m := driver0.o
drivername=driver0.ko

MODULE= $(obj-m:.o=.ko)

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules


install:
	sudo insmod $(MODULE) input=1 #not a real bool

uninstall:
	sudo rmmod $(MODULE)

clean:
	rm -f *~
	$(MAKE) -C $(KDIR) M=$(PWD) clean
