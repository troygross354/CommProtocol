/*
  XBee class for handling xbee connections.

  Copyright (C) 2016  Mario Garcia.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __XBEE_H
#define __XBEE_H

#include <CommProto/architecture/os/include_defines.h>
#include <CommProto/architecture/connection/serial-config.h>

#include <xbee/platform.h>
#include <xbee/device.h>
#include <wpan/aps.h>


namespace Comnet {
namespace Network {
namespace Experimental {


/**
   XBee communications module. Used for any Xbee protocol connection made to 
   other devices. Still needs work.
*/
class XBee {
public:
  /**
     Default constructor.
   */
  XBee(const char* port, speed_t baudrate);

  
  /**
     Default destructor.
   */
  ~XBee();
  /**
    Initialize the port on this device.
   */
  //bool initialize(const char* port, speed_t baudrate);
  /**
    Send data over to the destination node.
   */
  bool send(uint8_t destId, uint8_t* txData, uint32_t txLength);
  /**
    Check receive data.
   */
  bool recv(uint8_t* rxData, uint32_t* rxLength);
  /**
    Close the port.
   */
  bool closePort();

private:
  /**
    The information about the xbee device on this object.
   */
  struct xbee_serial_t serial;
  /**
    Information about the WPAN address on this device, subject by IEEE 802.15.4 protocol.
   */
  struct xbee_dev_t device;
  struct wpan_dev_t wpanDevice;
};
} // namespace Experimental
} // namespace Network
} // namespace Comnet
#endif // __XBEE_H
