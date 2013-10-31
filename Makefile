#
# Open Bloom Filter Master MakeFile
# By Arash Partow - 2000
#
# URL: http://www.partow.net/programming/hashfunctions/index.html
#
# Copyright Notice:
# Free use of this library is permitted under the guidelines
# and in accordance with the most current version of the
# Common Public License.
# http://www.opensource.org/licenses/cpl1.0.php
#

COMPILER         = -c++
OPTIMIZATION_OPT = -O3
OPTIONS          = -pedantic-errors -ansi -Wall -Wextra -Werror -Wno-long-long $(OPTIMIZATION_OPT) -o
LINKER_OPT       = -L/usr/lib -lstdc++

BUILD+=bloom_filter_example01
BUILD+=bloom_filter_example02
BUILD+=bloom_filter_example03

all: $(BUILD)

bloom_filter_example01: bloom_filter.hpp bloom_filter_example01.cpp
	$(COMPILER) $(OPTIONS) bloom_filter_example01 bloom_filter_example01.cpp $(LINKER_OPT)

bloom_filter_example02: bloom_filter.hpp bloom_filter_example02.cpp
	$(COMPILER) $(OPTIONS) bloom_filter_example02 bloom_filter_example02.cpp $(LINKER_OPT)

bloom_filter_example03: bloom_filter.hpp bloom_filter_example03.cpp
	$(COMPILER) $(OPTIONS) bloom_filter_example03 bloom_filter_example03.cpp $(LINKER_OPT)

clean:
	rm -f core *.o *.bak *stackdump *#

#
# The End !
#
