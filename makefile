CC=g++
CFLAGS=-g -lpthread
lib=/root/Shark/libshark.a

OBJ=book1  book2  book3  book4  book5  book6  book7 \
    book8  book9  book10 book11 book12 book13 book14 \
	book15 book16 book17

all:$(OBJ)
	 
%:%.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(lib)

clean:
	rm -rf $(OBJ)
