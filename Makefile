CC = gcc

CFLAGS = -Wall -Werror -I./include -L./lib

SRCDIR = src
OBJDIR = obj
TESTDIR = test
LIBDIR = lib

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

TESTS_C =  $(wildcard $(TESTDIR)/*.c)
TESTS_OUT = $(filter-out $(TESTS_C), $(wildcard $(TESTDIR)/*))
TOBJS = $(TESTS_C:%.c=%)

all: $(TOBJS)
	@echo MAKEFILE COMPLETED


lib: $(OBJS)
	mkdir -p $(LIBDIR)
	ar rcs $(LIBDIR)/libtests.a $^
	ranlib $(LIBDIR)/libtests.a
	rm -rf $(OBJDIR)

%: %.c lib
	$(CC) $(CFLAGS) $< -o $@ -ltests

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(LIBDIR)
	rm  $(TESTS_OUT)
	rm -rf $(OBJDIR)

#Opsiyonel kisim
rbt: $(TESTDIR)/rbt_test
	@clear
	@echo RED BLACK TREE TEST
	@./$(TESTDIR)/rbt_test

heap: $(TESTDIR)/heap_sort_test
	@clear
	@echo HEAP SORT TEST
	@./$(TESTDIR)/heap_sort_test

shell: $(TESTDIR)/shell_sort_test
	@clear
	@echo SHELL SORT TEST
	@./$(TESTDIR)/shell_sort_test

skip: $(TESTDIR)/skip_list_test
	@clear
	@echo SKIP LIST TEST
	@./$(TESTDIR)/skip_list_test

djb: $(TESTDIR)/djb_hash_test
	@clear
	@echo DJB HASH TEST
	@./$(TESTDIR)/djb_hash_test