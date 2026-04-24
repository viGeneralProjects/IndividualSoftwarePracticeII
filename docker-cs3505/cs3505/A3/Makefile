LIBHARU = /libharu

CC     = g++
CFLAGS = -Wall -std=c++17 -I$(LIBHARU)/include
LFLAGS = -L$(LIBHARU)/src
LIBS   = -lhpdfs

SRCS  = HaruPDF.cpp Sine.cpp sinePDF.cpp
OBJS  = HaruPDF.o Sine.o sinePDF.o
TARGET = sinePDF

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

HaruPDF.o: HaruPDF.cpp HaruPDF.h
	$(CC) $(CFLAGS) -c HaruPDF.cpp

Sine.o: Sine.cpp Sine.h
	$(CC) $(CFLAGS) -c Sine.cpp

sinePDF.o: sinePDF.cpp HaruPDF.h Sine.h
	$(CC) $(CFLAGS) -c sinePDF.cpp

clean:
	$(RM) $(TARGET) *.o
