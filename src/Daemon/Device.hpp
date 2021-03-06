//
// Copyright (C) 2015 Red Hat, Inc.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Authors: Daniel Kopecek <dkopecek@redhat.com>
//
#pragma once

#include "Typedefs.hpp"
#include "Rule.hpp"
#include "USB.hpp"
#include <mutex>

namespace usbguard {
  class Device
  {
  public:
    Device();

    std::mutex& refDeviceMutex();
    Pointer<Rule> getDeviceRule(bool include_port = false);
    uint32_t getSeqn() const;
    String getDeviceHash(bool include_port = false) const;
    void setSeqn(uint32_t seqn);
    void setTarget(Rule::Target target);
    void setDeviceName(const String& name);
    void setVendorID(const String& vendor_id);
    void setProductID(const String& product_id);
    void setDevicePort(const String& port);
    void setSerialNumber(const String& serial_number);
    std::vector<USBInterfaceType>& refInterfaceTypes();

    void loadDeviceDescriptor(const USBDeviceDescriptor* descriptor);
    void loadConfigurationDescriptor(int c_num, const USBConfigurationDescriptor* descriptor);
    void loadInterfaceDescriptor(int c_num, int i_num, const USBInterfaceDescriptor* descriptor);

  private:
    std::mutex _mutex;
    uint32_t _seqn;
    Rule::Target _target;
    String _name;
    String _vendor_id;
    String _product_id;
    String _serial_number;
    String _port;
    std::vector<USBInterfaceType> _interface_types;
    int _num_configurations;
    int _num_interfaces;
  };
} /* namespace usbguard */
