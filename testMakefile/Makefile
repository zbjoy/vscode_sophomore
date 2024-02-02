# SRC = $(wildcard ./*.c)
# TARGET = test
# OBJS = $(patsubst %.c, %.o, ${SRC})

# ${TARGET}:${OBJS}
# 	gcc $^ -o $@

# %.o:%.c
# 	gcc -c $< -o $@

SRC=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRC))
TARGET=test
$(TARGET):$(OBJS)
    gcc $(OBJS) -o $(TARGET) 

%.o:%.c
    gcc -c $< -o $@

# test.exe:func.o main.o
# 	gcc func.o main.o -o test.exe

# func.o:func.c
# 	gcc -c func.c -o func.o

# main.o:main.c
# 	gcc -c main.c -o main.o