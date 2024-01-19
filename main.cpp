#include "ESTT.h"
#include <cmath>
#include "ESTT_utils.h"
#include <iostream>
#include <iomanip>

#ifdef _WIN32
#pragma comment(lib, "ESTT.lib")
#define CONSOLE_CLEAR "CLS"
#else
#define CONSOLE_CLEAR "clear"
#endif

int main()
{
ESTT_STATUS err = 0;
ESTT et;
std::vector<int32_t> device_list;
et.getDeviceList(device_list);

if (device_list.empty())
{
std::cout << "Device list is empty\n";
return 0;
}
err = et.openDevice(device_list[0]);
if(err == ESTT::STATUS_OK)
{
std::cout << "ESTT is connected in USB3 mode!\n";
}
else if(err == ESTT::STATUS_DEVICE_OPEN_USB2_MODE)
{
std::cout << "ESTT is connected in USB2 mode!\n";
}
else
{
std::cout << "ESTT connection failed! Error code: " << err << std::endl;
return 0;
}
//………………………….
//………………………….
et.closeDevice();
}
