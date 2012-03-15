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

#include "tiny_log.h"


void log_messages (TinyLog::Level level)
{
  std::cerr << "Setting log level to " << level << ':' << std::endl;
  TinyLog::SetLevel (level);
  FATAL << "Fatal error message" << std::endl;
  ERROR << "Normal error message" << std::endl;
  WARN  << "Warning message" << std::endl;
  INFO  << "Information message" << std::endl;
  DEBUG << "Debug message" << std::endl;
  TRACE << "Tracing message" << std::endl;
  std::cerr << std::endl;
}


int main (int argc, char **argv)
{
   log_messages (TinyLog::kOff);
   log_messages (TinyLog::kFatal);
   log_messages (TinyLog::kError);
   log_messages (TinyLog::kWarn);
   log_messages (TinyLog::kInfo);
   log_messages (TinyLog::kDebug);
   log_messages (TinyLog::kTrace);
   log_messages (TinyLog::kAll);
}
