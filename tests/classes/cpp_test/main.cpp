#include <CommProto/comms.h>
#include <CommProto/architecture/os/comm_mutex.h>

int main(int c, char** args) {
  std::cout << sizeof comnet::Header << std::endl;
  comnet::architecture::os::CommMutex mut;
  comnet::architecture::os::CommLock commlock(mut);
  comnet::Comms comm1(1);
  std::cin.ignore();
  return 0;
}
