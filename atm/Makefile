CXX = g++
CXXFLAGS = -std=c++11
TARGET = atm
OBJS = Account.o ATMachine.o Statistics.o main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
