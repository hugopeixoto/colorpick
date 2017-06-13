# colorpick - simple X11 color picker

LDFLAGS+=-lX11

all: colorpick

colorpick: colorpick.o
	${CC} -o $@ $< ${LDFLAGS}
