/*

	Serial Port wrapper for libserial (POSIX Serial port library)
	Author: Amiraj Dhawan
	Email: amirajdhawan@gmail.com
	Version: 0.98
	For usage check the sample code in main.cpp

*/

#include "serial_port.hpp"

int setup_serial_port(  LibSerial::SerialStream& serial_port, 
						const char* SERIAL_PORT_DEVICE,
						LibSerial::SerialStreamBuf::BaudRateEnum baud_rate
						) {
	
	using namespace LibSerial;    
	
	//Open the port SERIAL_PORT_DEVICE
	serial_port.Open( SERIAL_PORT_DEVICE );
	if ( ! serial_port.good() ) {
		std::cout << "Not able to open serial port at " << SERIAL_PORT_DEVICE << std::endl;
		return 0;
	}
	//Set Baudrate
	serial_port.SetBaudRate( baud_rate );
	if ( ! serial_port.good() ) {
		std::cout << "Unable to set Baud Rate " << std::endl;
		return 0;
	}

	//Set Character Size
	serial_port.SetCharSize( SerialStreamBuf::CHAR_SIZE_8 );
	if( ! serial_port.good() ) {
		std::cout << "Unable to set Char Size 8" << std::endl;
		return 0;
	}

	//Set Parity
	serial_port.SetParity( SerialStreamBuf::PARITY_NONE );

	if( ! serial_port.good() ) {
		std::cout << "Unable to set Parity None " << std::endl;
		return 0;
	}

	//Set Number of Stop Bits
	serial_port.SetNumOfStopBits( 1 );
	if( ! serial_port.good() ) {
		std::cout << "Unable to set Num of Stop Bits 1 " << std::endl;
		return 0;
	}

	//Set Hardware Flow Control 
	serial_port.SetFlowControl( SerialStreamBuf::FLOW_CONTROL_NONE );
	if( ! serial_port.good() ) {
		std::cout << "Unable to set Hardware Flow Control None" << std::endl;
		return 0;
	}

	return 1;
}

int write_byte( LibSerial::SerialStream& serial_port, char data) {
	if( serial_port.good() ) {
		serial_port.write( &data, 1);
		return 1;
	}
	else
		std::cout  <<  "Unable to write to serial port"  <<  std::endl;
	return 0;
}