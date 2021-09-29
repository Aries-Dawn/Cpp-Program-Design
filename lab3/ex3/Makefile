SRC_DIR = .
SOURCE = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SOURCE))
TARGET = main
INCLUDE = -I ./inc


CC = g++
CFLAGS = -c -Wall

$(TARGET):$(OBJS)
	$(CC) -o $@ $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(INCLUDE)


.PHONY:clean
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)