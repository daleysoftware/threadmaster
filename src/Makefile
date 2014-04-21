TOPDIR = ..

SRCS = $(wildcard *.cpp)
OBJS = $(addprefix ., ${SRCS:.cpp=.o})

LIBRARY = threadmaster.a

all: example

example: ${LIBRARY}
	@echo "$(shell date +%H:%M:%S) Building example..."
	@g++ -I../include example.cpp ${LIBRARY} -o example

${LIBRARY}: ${OBJS}
	@echo "$(shell date +%H:%M:%S) Linking..."
	@ar rs ${LIBRARY} ${OBJS}
	@chmod a+x ${LIBRARY}

.%.o: %.cpp
	@echo "$(shell date +%H:%M:%S) Building $?..."
	@g++ -c $? -I../include -o $@

clean:
	@rm -f ${OBJS} ${LIBRARY}
