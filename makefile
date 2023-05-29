CC := gcc
CFLAGS := -Wall -Wextra -std=c99
LDFLAGS := -lcunit

SRC := CUnit_testing_STM32.c arithmetic.c
OBJ := $(SRC:.c=.o)
EXECUTABLE := CUnit_testing_STM32
TEST_RESULTS := test_results.xml

.PHONY: all clean test

all: $(EXECUTABLE) test

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test: $(EXECUTABLE) 
	./$(EXECUTABLE) -fjunit > $(TEST_RESULTS)


create_test_dir:


clean:
	rm -f $(EXECUTABLE) $(OBJ)

