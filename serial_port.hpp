/*

	Serial Port wrapper for libserial (POSIX Serial port library)
	Author: Amiraj Dhawan
	Email: amirajdhawan@gmail.com
	Version: 0.98
	For usage check the sample code in main.cpp

*/

#ifndef SERIAL_PORT_HPP
#define SERIAL_PORT_HPP

#include <SerialStream.h>
#include <iostream>
#include <cstdlib>

int setup_serial_port(  LibSerial::SerialStream&, 
						const char*,
						LibSerial::SerialStreamBuf::BaudRateEnum
						);

int write_byte( LibSerial::SerialStream&, 
				char 
				);

#endif