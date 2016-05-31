#include <CommProto/AbstractPacket.h>

// NOTE(): We will need to check this because g++ does not have functional like visual studio.
#include <tr1/functional>

namespace Comnet {

/**
   Constructor for AbstractPacket.
*/
AbstractPacket::AbstractPacket(const char* className)
: typeId(std::tr1::hash<const char*>()(className)) {
}

/**
   AbstractPacket Destructor.
*/
AbstractPacket::~AbstractPacket() {
}

} // Comnet