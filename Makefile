# The make file for BCSLib

# compiler configuration

CC = g++
CFLAGS = -I. -Wall

BASE_HEADERS = bcslib/base/config.h bcslib/base/basic_defs.h bcslib/base/basic_funcs.h bcslib/base/basic_mem.h bcslib/base/enumerate.h 

TEST_HEADERS = bcslib/test/test_assertion.h bcslib/test/test_units.h bcslib/test/execution_mon.h

ARRAY_BASIC_HEADERS = bcslib/array/array_base.h bcslib/array/index_selection.h


all: test_array

test_array : bin/test_array_basics

ARRAY_BASIC_TESTS = test/test_array_basics.cpp test/test_index_selection.cpp
bin/test_array_basics: $(BASE_HEADERS) $(TEST_HEADERS) $(ARRAY_BASIC_HEADERS) $(ARRAY_BASIC_TESTS) 
	$(CC) $(CFLAGS) $(ARRAY_BASIC_TESTS) -o bin/test_array_basics