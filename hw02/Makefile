CXX = g++
CXXFLAGS = -std=c++11
TARGET = program
OBJS = Shape.o Circle.o Rect.o Line.o main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
