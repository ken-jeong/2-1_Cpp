# 변수 설정
CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = shapes
SRCS = shapes.cpp
OBJS = $(SRCS:.cpp=.o)

# 기본 목표: 실행 파일 생성
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 개별 오브젝트 파일 생성
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# make clean 시 불필요한 파일 제거
clean:
	rm -f $(TARGET) $(OBJS) objects.txt

