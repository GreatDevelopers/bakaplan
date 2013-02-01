# Makefile for installation
next = cd BakaPlan
back = cd ..

all: make

make:
	$(next) && make && $(back)

install: 
	$(next) && make install && $(back)

cp: 
	$(next) && make cp-BaKaPlan && $(back)

clean: 
	$(next) && make clean && $(back)

