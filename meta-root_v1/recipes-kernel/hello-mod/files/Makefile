obj-m += hello.o

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) modules

modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) modules_install

clean:
	rm -f *.o *.ko *.mod.* .*.cmd Module.symvers modules.order
	rm -rf .tmp_versions