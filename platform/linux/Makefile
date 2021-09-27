BINPATH=/usr/bin

CC=$(BINPATH)/gcc
CXX=$(BINPATH)/g++
AR=$(BINPATH)/ar
LD=$(BINPATH)/ld
OBJCOPY=$(BINPATH)/objcopy
SIZE=$(BINPATH)/size

vpath %.cpp ../../src

CFLAGS  = -g -Wall -pthread -m64 # TODO: use -m32
CFLAGS += -I../../src
CFLAGS += -I../../src/lib/wxWidgets/include

###################################################

OBJDIR=obj
BINDIR=bin
MAIN_SRCS = main.cpp

#LIB_SRCS = <TODO: add files if needed>

PROJ_NAME=WxApp
OUTPATH=bin

###################################################

MAIN_OBJS=$(patsubst %.cpp,$(OBJDIR)/%.o,$(MAIN_SRCS))
#LIB_OBJS=$(patsubst %.c,$(OBJDIR)/%.o,$(LIB_SRCS))

###################################################

.PHONY: proj clean

all: $(OUTPATH)/$(PROJ_NAME).elf

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -L$(OBJDIR)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CFLAGS) -c $< -o $@ -L$(OBJDIR) `wx-config --cxxflags --libs`

$(OUTPATH)/$(PROJ_NAME).elf: $(MAIN_OBJS)
	 $(CXX) $(CFLAGS) $^ -o $@ -L. -Lobj `wx-config --cxxflags --libs`
	 $(SIZE) $@

proj: $(OUTPATH)/$(PROJ_NAME).elf

clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)

