CC = g++

OBJS = driver.cpp HugeInt.cpp

OBJ_NAME = driver

all :
	$(CC) $(OBJS) -std=c++11 -o $(OBJ_NAME)