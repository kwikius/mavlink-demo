#ifndef FRSKY_DATA_SERIAL_PORT_HPP_INCLUDED
#define FRSKY_DATA_SERIAL_PORT_HPP_INCLUDED


/*
 Copyright (c) 2012 - 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/


#if !defined(__linux) && !defined(__APPLE__)
#error "only for use on linux or macOS"
#endif


#include <cstddef>
#include <cstdint>
#include <string>
#include <sys/ioctl.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdexcept>

#include <err.h>

#ifdef __linux
#include <linux/serial.h>
#endif

extern "C" struct termios;

struct serial_port{
   typedef  unsigned char data_type;
   serial_port(const char* filename);
   ~serial_port();
   void init(int baud = 9600);
   ssize_t read( data_type* buf,size_t num);
   ssize_t write(const data_type* buf, size_t num) ;
   ssize_t write(const char* buf, size_t num) ;

   // adds 0 at end
   template<size_t N>
   ssize_t write(const char(& buf)[N]){
      return write(buf,N);
   }

   template<size_t N>
   ssize_t write_strlen(const char(& buf)[N]){
      return write(buf,N-1);
   }

   size_t in_avail();
   size_t in_avail(uint32_t const & t_ms, size_t n = 1);
   bool good() const;
   bool is_deleteable()const;

   int set_baud( uint32_t val);
   bool set_dtr(bool val);
   bool set_rts(bool val);
   void flush();
   std::string const & get_filename() { return m_filename;}
   void close();
private:
   std::string m_filename;
   void cleanup();
   int m_fd;
   termios * m_old_termios;
   bool m_good_state;
  
   serial_port (serial_port const &) = delete;
   serial_port& operator = (serial_port const &) = delete;

   bool set_pin( unsigned int pin, bool val);
};

#endif // FRSKY_DATA_SERIAL_PORT_HPP_INCLUDED
