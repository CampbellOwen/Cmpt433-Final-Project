#include <stdio.h>
#include <include/device_manager.h>
#include <include/udp_server.h>
#include <include/moisture.h>
#include <include/pid.h>

#ifndef PORT
#define PORT 12345
#endif

int main( void )
{
	if( !PID_Init() ) return 1;

	if( !DeviceManager_Init() ) return 1;

	if( !UDP_Server_Init( PORT ) ) return 1;

	UDP_Server_Wait();

	DeviceManager_Shutdown();

	PID_Shutdown();

	return 0;
}
