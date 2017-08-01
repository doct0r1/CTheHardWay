PROGRAMS_SRC=$(wildcard	bin/*.c)
PROGRAMS=$(putsubst	%.c,%,$(PROGRAMS_SRC))

all:	$(TARGET)	$(SO_TARGET)	tests	$(PROGRAMS)

rm	-rf	build	$(OBJECTS)	$(TESTS)	$(PROGRAMS)

$(PROGRAMS):	CFLAGS	+=	$(TARGET)
