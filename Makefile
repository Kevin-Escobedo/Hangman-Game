CC=g++
CXXFLAGS=-std=c++17 -Wpedantic -Wall -Werror -Wextra -Weffc++ -Wzero-as-null-pointer-constant
OPTIMIZE=-O2
FILES=Database.h Database.cpp WordDatabase.h WordDatabase.cpp main.cpp
LIBRARIES=-l sqlite3
TARGET=hangman

all: $(TARGET)
$(TARGET): $(FILES)
	$(CC) $(CXXFLAGS) $(OPTIMIZE) $(FILES) $(LIBRARIES) -o $(TARGET)

run: $(TARGET)
	valgrind ./$(TARGET)

clean:
	/bin/rm -f $(TARGET)
