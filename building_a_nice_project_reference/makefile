BIN := bin
SRC := src
INCLUDE := include
INCLUDE := $(addprefix -I, ${INCLUDE})
LIBS := -lpthread -lrt

targets: all

all: main.cpp
	mkdir -p ${BIN}
	g++ -g -o ${BIN}/binary.exe ${BIN}/main.cpp ${INCLUDE} ${LIBS}

clean:
	rm -f ${BIN}/main.exe 