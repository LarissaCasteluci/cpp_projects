BIN := bin
SRC := src
FLAGS := --std=c++11
INCLUDE := include
INCLUDE := $(addprefix -I, ${INCLUDE})
LIBS := -lpthread -lrt

targets: all

all: 
	mkdir -p ${BIN}
	g++ -g -o ${BIN}/server.exe ${SRC}/server.cpp ${INCLUDE} ${LIBS}
	g++ -g -o ${BIN}/client.exe ${SRC}/client.cpp ${INCLUDE} ${LIBS}


clean:
	rm -f ${BIN}/main.exe 