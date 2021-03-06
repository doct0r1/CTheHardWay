CFLAGS=-g	-O2	-Wall	-Wextra	-Isrc	-DNDEBUG	$(OPTFLAGS)
LIBS=-ldl	$(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard	src/**/*.c	src/*.c)
HEADERS=$(wildcard 	src/**/*.h 	src/*h)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard	tests/*_tests.c)
TESTS=$(patsubst	%.c,%,$(TEST_SRC))

PROGRAMS_SRC=$(wildcard	tests/*_tests.c)
TESTS=$(patsubst	%.c,%,$(PROGRAMS_SRC))

TARGET=build/libYOUR_LIBRARY.a
SO_TARGET=$(patsubst	%.a,%.so,$(TARGET))

# The Target Build
all:	$(TARGET)	$(SO_TARGET)	tests

dev:	CFLAGS=-G	Wall	-Isrc	-Wall	-Wextra	$(OPTFLAGS)
dev:	all

$(TESTS):	$(TARGET)	$(SO_TARGET)

$(TARGET):	CFLAGS	+=	-fPIC
$(TARGET):	build	$(OBJECTS)
	ar	rcs	$@	$(OBJECTS)
	ranlib	$@

$(SO_TARGET):	$(TARGET)	$(OBJECTS)
	$(CC)	-shared	-o	$@	$(OBJECTS)

build:
	@mkdir	-p	build
	@mkdir	-p	bin

# The Unit Tests
.PHONY:	tests
tests:	CFLAGS	+=	$(TARGETS)
tests:	$(TESTS)
	sh	./tests/runtests.sh

valgrind:
	VALGRIND="valgrind	--log-file=/tmp/valgrind-%p.log"	$(MAKE)

# The Cleaner
clean:
	rm	-rf	build	$(OBJECTS)	$(TESTS)
	rm	-f	tests/tests.log
	find	.	-name	".gc*"	-exec	rm	{}	\;
	rm	-rf	'find	.	-name	".DSYM"	-print

# The Install
install:	all
	install	-d	$(DESTDIR)/$(PREFIX)/lib/
	install	$(TARGET)	$(DESTDIR)/$(PREFIX)/lib/
	install $(SO_TARGET)	$(DESTDIR)/$(PREFIX)/lib/
	install	-d	$(DESTDIR)/$(PREFIX)/include/lcthw/
	install $(HEADERS)	$(DESTDIR)/$(PREFIX)/include/lcthw/

# The Checker
BADFUNC='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
	@eche Files With Potentially dangerous functions.
#	@egrep	'[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'	$(SOURCE)	||	tru
	@egrep 	$(BADFUNC)	$(SOURCES)	||	true

$(PROGRAMS):	CFLAGS	+=	$(TARGET)
