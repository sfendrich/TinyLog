// TinyLog - minimalistic logging class for C++
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


#ifndef TINY_LOG_H
#define TINY_LOG_H

#include <ostream>
#include <time.h>

#define TINY_LOG(msg_level,log_label)\
  if (msg_level <= TinyLog::level ())\
    TinyLog::stream () << TinyLog::Timestamp()\
              << " (" __FILE__ ":" << __LINE__ << "): " log_label ": "

#define FATAL TINY_LOG(TinyLog::kFatal, "FATAL")
#define ERROR TINY_LOG(TinyLog::kError, "ERROR")
#define WARN  TINY_LOG(TinyLog::kWarn , "WARN ")
#define INFO  TINY_LOG(TinyLog::kInfo , "INFO ")
#define DEBUG TINY_LOG(TinyLog::kDebug, "DEBUG")
#define TRACE TINY_LOG(TinyLog::kTrace, "TRACE")


class TinyLog
{
  public:
    typedef enum { kOff,  kFatal, kError, kWarn, 
                   kInfo, kDebug, kTrace, kAll  } Level;
    static Level level ();                    // Get log level
    static void  SetLevel (Level level);      // Set log level
    static std::ostream &stream ();           // Get output stream for logging
    static void SetStream (std::ostream &os); // Set output stream for logging
    static const char *Timestamp ();          // Generate time stamp
  private:
    static Level level_;                      // Current log level
    static std::ostream *os_;                 // Output stream for logging
    TinyLog () {};                            // Hidden constructor
    TinyLog (const TinyLog &);                // Prevent copying
    TinyLog& operator= (const TinyLog &);     // Prevent assignment
};


inline TinyLog::Level TinyLog::level ()
{
  return level_;
}


inline void TinyLog::SetLevel (TinyLog::Level level)
{ 
  level_ = level;
}


inline std::ostream &TinyLog::stream ()
{
  return *os_;
}


inline void TinyLog::SetStream (std::ostream &os)
{
  os_ = &os;
}

#endif
