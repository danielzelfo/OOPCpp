CC = g++

OBJS = driver.cpp RationalNumber.cpp

OBJ_NAME = driver

all :
	$(CC) $(OBJS) -std=c++11 -o $(OBJ_NAME)