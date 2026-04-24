CC = g++
CFLAGS = -Wall -fsanitize=address

TrieTest: TrieTest.o Trie.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o Trie.o

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp

TrieTest.o: TrieTest.cpp Trie.h
	$(CC) $(CFLAGS) -c TrieTest.cpp

clean:
	rm -f TrieTest *.o

test: TrieTest
	./TrieTest "words.txt" "test.txt"
