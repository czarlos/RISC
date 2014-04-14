.PHONY: all cpp clean

all: cpp

cpp: create_order_test

clean: 
	rm -f create_order_test

protoc_file: UnitType.proto
	protoc --cpp_out=../ ../UnitType.proto ../Unit.proto ../Territory.proto ../AddUnitOrder.proto
	../ResourceType.proto
	@touch protoc_file

create_order_test: CreateOrderTest.cpp
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	c++ CreateOrderTest.cpp ../UnitType.pb.cc ../Unit.pb.cc ../Territory.pb.cc ../AddUnitOrder.pb.cc
	../ResourceType.pb.cc -o create_order_test `pkg-config --cflags --libs protobuf`
