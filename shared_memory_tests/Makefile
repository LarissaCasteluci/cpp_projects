BIN := bin
INCLUDE := include
INCLUDE := $(addprefix -I, ${INCLUDE})
LIBS := -lpthread -lrt

targets: all

all: owner.cpp reader.cpp
	mkdir -p ${BIN}
	g++ -g -o ${BIN}/owner.exe owner.cpp ${INCLUDE} ${LIBS}
	g++ -g -o ${BIN}/reader.exe reader.cpp ${INCLUDE} ${LIBS}

clean:
	rm -f ${BIN}/owner.exe ${BIN}/reader.exe