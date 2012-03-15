# TinyLog - minimalistic logging library for C++
#
# (c) 2012 Sascha Fendrich
#
# License:
#
# This program is free software. It comes without any warranty, to
# the extent permitted by applicable law. You can redistribute it
# and/or modify it under the terms of the Do What The Fuck You Want
# To Public License, Version 2, as published by Sam Hocevar. See
# http://sam.zoy.org/wtfpl/COPYING for more details.


default: libtiny_log.a

test: tiny_log_test

libtiny_log.a: tiny_log.o
	$(AR) ru $@ $^

tiny_log.o: tiny_log.cpp tiny_log.h
	$(CXX) -c $<

tiny_log_test: tiny_log_test.o libtiny_log.a
	$(CXX) -L. -o $@ $< -ltinylog

tiny_log_test.o: tiny_log_test.cpp tiny_log.h
	$(CXX) -c $<

.PHONY:
clean:
	$(RM) -f tiny_log_test libtiny_log.a *.o
