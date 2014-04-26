CPP_SOURCES=$(wildcard ../*.cpp) $(wildcard ../../GameMap/*.cpp) $(wildcard ../../GameObject/*.cpp) $(wildcard ../../GameState/Managers/Resource/*.cpp) $(wildcard ../../GameObject/Unit/*.cpp)
PROTO_SOURCES=$(wildcard ../*.proto)
CC_SOURCES=$(patsubst %.proto, %.pb.cc, $(PROTO_SOURCES))
PROTO_OBJS=$(patsubst %.pb.cc, %.o, $(CC_SOURCES))
CPP_OBJS=$(patsubst %.cpp, %.o, $(CPP_SOURCES))

.PHONY: all cpp clean

all: cpp

cpp: create_order_test

clean: 
	rm -f create_order_test
%.pb.cc: %.proto
	protoc --proto_path=`dirname $@` $< --cpp_out=`dirname $@`
%.o:%.cpp
	g++ `pkg-config --cflags protobuf` --std=c++11 -c -o $@ $<
%.o:%.pb.cc
	g++ `pkg-config --cflags protobuf` --std=c++11 -c -o $@ $<

create_order_test: $(PROTO_OBJS) $(CPP_OBJS) ../*.h CreateOrderTest.cpp
	g++ -std=c++11 CreateOrderTest.cpp $(PROTO_OBJS) $(CPP_OBJS) -o create_order_test `pkg-config --cflags --libs protobuf`

