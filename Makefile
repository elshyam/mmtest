obj-m +=kfree_err_ptr_test.o

#subdir-ccflags-y := -I$(src)/include
#subdir-ccflags-y += -Wall -g

#ifeq ($(KERNELRELEASE),)

PWD := $(shell pwd)
KDIR= /lib/modules/$(shell uname -r)/build

modules:
	$(MAKE) -C '$(KDIR)' M='$(PWD)' modules
clean:
	$(MAKE) -C '$(KDIR)' M='$(PWD)' clean
