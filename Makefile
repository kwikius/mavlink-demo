
# A list of include directories where header files are looked up
include_directories = mavlink/ardupilotmega/  /home/andy/cpp/projects/quan-trunk/

# A list of g++ compiler switches
# created by adding the preceeding -I switch to each in
# the list of include directories
INCLUDES = $(patsubst %,-I%,$(include_directories))

# the g++ compile flags
# The -Wall flag enables all warnings 
# the -std=gnu++11 specifies the C++11 flavour of C++ with gnu extensions
CXXFLAGS = -Wall -std=gnu++11

# 'all' is the standard target. This rule says it depends on mavlink_demo.exe.exe
all : mavlink_demo.exe

# The list of object files to be included in the build
# These  names are composed from the .cpp files
# with the .cpp replaced with .o
# done by substition in the $(objects) target rule below
objects = main.o serial.o mav_type.o

# build the app. This rule says the app depends on the object files
# ,so the object files are looked for and built if not found
# then the following command is invoked to build the app
mavlink_demo.exe : $(objects)
	g++ -o $@ $(objects) 

# This rule says build the objects from the same named sources
# using the following command
$(objects) : %.o : %.cpp
	g++ $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

# Invoke 'make clean' to invoke this command
# to remove the object and executable files
clean :
	rm -f *.o *.exe


