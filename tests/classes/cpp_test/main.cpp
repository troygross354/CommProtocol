#include <CommProto/architecture/os/comm_mutex.h>
#include <CommProto/comms.h>
#include <CommProto/callback.h>
#include <CommProto/architecture/os/comm_thread.h>
#include <iostream>

class Cat {
};
// Ping testing.
class Ping : INHERITS_ABSPACKET {
public:
  Ping() : CHAIN_ABSPACKET(Ping) { }
  Ping(std::string cc) 
  : CHAIN_ABSPACKET(Ping)
  , cat(cc) { }

  void Pack(REF_OBJECTSTREAM obj) {
    obj << cat;  // add cat
  }

  void Unpack(REF_OBJECTSTREAM obj) {
    obj >> cat;
  }
  
  ABSPACKET* Create() {
    return new Ping();
  }

  const std::string& GetCat() const { return cat; }
private:

  std::string cat;
};


error_t PingCallback(const comnet::Header& header, const Ping& packet) {
  std::cout << "Packet contains: " << packet.GetCat() << std::endl;
  return comnet::CALLBACK_SUCCESS | comnet::CALLBACK_DESTROY_PACKET;
}


int main(int c, char** args) {
  std::condition_variable cond;
  comnet::Comms comm1(1);
  std::cout << sizeof(comnet::Header) << std::endl;
  comnet::architecture::os::CommMutex mut;
  comnet::architecture::os::CommLock commlock(mut);
  // This will cause the thread to wait for a few milliseconds, causing any other thread to wait.
  comnet::architecture::os::WaitForMilliseconds(commlock, cond, 1000); 

  std::cout << "Test complete!" << std::endl;
  std::cout << "Init connection succeeded: " 
            << std::boolalpha
            << comm1.InitConnection(ZIGBEE_LINK, "COM3")
            << std::endl;
  std::cout << "Connected to address: "
            << std::boolalpha
            << comm1.AddAddress(2, "0013A20040762067")
            << std::endl;
  comm1.LinkCallback(new Ping(), new comnet::Callback((comnet::callback_t)PingCallback));
  Ping bing("I like cats");
  comm1.Run();
  while (true) {
    std::cout << "Sleeping..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  std::cin.ignore();
  return 0;
}
