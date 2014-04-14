.PHONY: all cpp clean

all: cpp

cpp: create_order_test

clean: 
	rm -f create_order_test

protoc_file: Unit.proto
	protoc --cpp_out=../ ../UnitType.proto
	@touch protoc_file

create_order_test: CreateOrderTest.cpp
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ -std=c++11 CreateOrderTest.cpp ../UnitType.pb.cc -o create_order_test `pkg-config --cflags --libs protobuf`
