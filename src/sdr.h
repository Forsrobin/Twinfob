#ifndef SDR_H
#define SDR_H

#include <SoapySDR/Device.hpp>
#include <SoapySDR/Types.hpp>
#include <SoapySDR/Formats.hpp>

#include <string>
#include <vector>
#include <map>
#include <iostream>

class SDR
{
private:
  SoapySDR::KwargsList results;
public:
  SDR();
  std::vector<std::string> getDevices();
};

#endif