obj-m += gpio-blinker.o 

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) modules

clean:
	rm -f *.o *.ko *.mod.* .*.cmd Module.symvers modules.order
	rm -rf .tmp_versions
