CXX= mpic++
CXXFLAGS = -g -O2

SRCS = IsendIrecv_byte.cpp
OBJS = $(SRCS:%.cpp=%.o)
PROG = IsendIrecv_byte

all: $(PROG)

test:
	mpirun -np 8 ./$(PROG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean: 
	rm -rf $(OBJS) $(PROG) *~
