
include_directories = mavlink/ardupilotmega/  

INCLUDES = $(patsubst %,-I%,$(include_directories))

TARGET = mavlink_demo.exe
BUILD_DIR = build
BIN_DIR = bin

CXXFLAGS = -Wall -std=gnu++11

OBJECTS = $(patsubst %.o, $(BUILD_DIR)/%.o, \
	main.o \
	serial.o \
	msg_functions.o \
)

.PHONY : all clean

all : $(BIN_DIR)/$(TARGET) 

$(BIN_DIR)/$(TARGET) : $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	g++ -o $@ $(OBJECTS) 

$(BUILD_DIR)/%.o : %.cpp
	@mkdir -p $(BUILD_DIR)
	g++ $(CXXFLAGS) -c $< $(INCLUDES) -o $@ 

clean :
	rm -f $(BUILD_DIR)/*.o $(BIN_DIR)/*.exe


