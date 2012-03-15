// TinyLog - minimalistic logging library for C++
//
// (c) 2012 Sascha Fendrich
//
// License:
//
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// http://sam.zoy.org/wtfpl/COPYING for more details.


#include <iostream>
#include <time.h>
#include "tiny_log.h"

// Setup static members
TinyLog::Level TinyLog::level_ = TinyLog::kInfo;
std::ostream *TinyLog::os_ = &std::cerr;

// Create time stamp
const char *TinyLog::Timestamp ()
{
  static char time_str[32];
  time_t t      = time (NULL);
  struct tm *tm = localtime (&t);
  if (strftime (time_str, sizeof (time_str), "%F %T", tm) == 0)
    time_str[0] = 0;
  return time_str;
}
