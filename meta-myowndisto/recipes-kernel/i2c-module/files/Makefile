obj-m += i2c_driver.o

SRC := ${shell pwd}

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(SRC)  modules

modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=${SRC} modules_install

clean:
	rm -f  *.o  *.mod. .*.cmd Modules.sysmvers modules.order *.mod.c *.ko .depend
	rm -rf .tmp_versions