OBJS = GeometricShapes.cpp

#Change compiler here if required
CC = g++

OBJ_NAME = GeometricShapes

all :
	$(CC) $(OBJS) -std=c++11 -o $(OBJ_NAME)