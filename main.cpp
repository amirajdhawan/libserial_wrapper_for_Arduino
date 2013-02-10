/*

	Serial Port wrapper for libserial (POSIX Serial port library)
	Author: Amiraj Dhawan
	Email: amirajdhawan@gmail.com
	Version: 0.98
	For usage check the sample code in main.cpp

*/

//User defined header files
#include "serial_port.hpp"

//Standard header files
#include <SerialStream.h>
#include <iostream>

int main(int argc, char** argv) {

	//String of the serial port address
	char* serial_name = "/dev/ttyACM0" ;

	//Object of SerialStream
	LibSerial::SerialStream serial_port;

	//Check if setup_serial_port was successful or not
	if ( setup_serial_port( serial_port, 
							serial_name, 
							LibSerial::SerialStreamBuf::BAUD_9600 ) ) {	
		
		unsigned char data_byte = 0;

		//Continously read data from standard input and send on serial port
		while(1) {
				
			std::cin >> data_byte;
			if( data_byte == 27)
				break;
			else {
				if( ! write_byte(serial_port, data_byte) )
					break;
			}
		}
	}

	else {
		//Display error for not able to setup serial port
		std::cout << "Unable to Setup Serial Port" << std::endl;
	}

	return 0;
}