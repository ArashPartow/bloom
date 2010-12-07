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

BUILD+=bloom_filter_example01
BUILD+=bloom_filter_example02

all: $(BUILD)

bloom_filter_example01: bloom_filter.hpp bloom_filter_example01.cpp
	$(COMPILER) $(OPTIONS) bloom_filter_example01 bloom_filter_example01.cpp

bloom_filter_example02: bloom_filter.hpp bloom_filter_example02.cpp
	$(COMPILER) $(OPTIONS) bloom_filter_example02 bloom_filter_example02.cpp

clean:
	rm -f core *.o *.bak *stackdump *#

#
# The End !
#
