TOPDIR = ..

SRCS = $(wildcard *.cpp)
OBJS = $(addprefix ., ${SRCS:.cpp=.o})

LIBRARY = threadmaster.a

all: ${LIBRARY}

${LIBRARY}: ${OBJS}
	@echo "$(shell date +%H:%M:%S) Linking..."
	@ar rs ${LIBRARY} ${OBJS}
	@chmod a+x ${LIBRARY}

.%.o: %.cpp
	@echo "$(shell date +%H:%M:%S) Building $?..."
	@g++ -c $? -I../include -o $@

clean:
	@rm -f ${OBJS} ${LIBRARY}
