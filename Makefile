### This Makefile was written for GNU Make. ###
ifeq ($(DEBUG),true)
    COPTFLAGS  := -O0 -g3 -ftrapv -fstack-protector-all -D_FORTIFY_SOURCE=2
    LDLIBS     += -lssp
else
ifeq ($(OPT),true)
    COPTFLAGS  := -flto -Ofast -march=native -DNDEBUG
    LDOPTFLAGS := -flto -Ofast -s
else
ifeq ($(LTO),true)
    COPTFLAGS  := -flto -DNDEBUG
    LDOPTFLAGS := -flto
else
    COPTFLAGS  := -O3 -DNDEBUG
    LDOPTFLAGS := -O3 -s
endif
endif
endif


C_WARNING_FLAGS := -Wall -Wextra -Wformat=2 -Wstrict-aliasing=2 \
                   -Wcast-align -Wcast-qual -Wconversion \
                   -Wfloat-equal -Wpointer-arith -Wswitch-enum \
                   -Wwrite-strings -pedantic

CC      := gcc
CFLAGS  := -pipe $(C_WARNING_FLAGS) $(COPTFLAGS) $(INCS) $(MACROS) -std=gnu99
LDFLAGS := -pipe $(LDOPTFLAGS)
LDLIBS  := -lm
TARGET  := mamemaki
OBJS    := $(addsuffix .o, $(basename $(TARGET)))
SRCS    := $(OBJS:%.o=%.c)

ifeq ($(OS),Windows_NT)
    TARGET := $(addsuffix .exe, $(TARGET))
endif

%.exe:
	$(CC) $(LDFLAGS) $(filter %.c %.o, $^) $(LDLIBS) -o $@
%.out:
	$(CC) $(LDFLAGS) $(filter %.c %.o, $^) $(LDLIBS) -o $@


.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)


.PHONY: test
test:
	./$(TARGET)


.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)
.PHONY: cleanobj
cleanobj:
	$(RM) $(OBJS)
