#ifndef __LOG_H
#define __LOG_H

#include <CommProto/architecture/os/include_defines.h>
#include <CommProto/architecture/api.h>

namespace Comnet {
namespace Debug {


/**
   The Log status for the Log object.
 */
enum LogStatus {
  LOG_NOTHING,
  LOG_SIMPLE,
  LOG_NOTIFY,
  LOG_WARNING,
  LOG_ERROR,
};


/**
   Log interface is a notifier. It provides notifications to the Logger Manager, 
   which in turn will determine what to do with the message received.
*/
_COMNET_INTERFACE_ Log {
public:
  /**
     Default Constructor.
   */
  Log();
  /**
     Polymorphic destructor.
   */
  virtual ~Log();

  virtual char* getMessage() = 0;
  virtual char* trace() = 0;

  virtual logMessage(const char* message) = 0;
};
} // Debug namespace
} // Comnet namespace
#endif // __LOG_H