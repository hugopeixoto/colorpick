# colorpick - simple X11 color picker

include config.mk

LDFLAGS+=-lX11

all: colorpick

colorpick: colorpick.o
	${CC} -o $@ $< ${LDFLAGS}

clean:
	rm -f colorpick colorpick.o

install: all
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f colorpick ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/colorpick
