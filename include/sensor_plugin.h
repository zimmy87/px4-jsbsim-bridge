/****************************************************************************
 *
 *   Copyright (c) 2020 Auterion AG. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/
/**
 * @brief JSBSim Sensor Plugin base class
 *
 * This is a base class for the JSBSim sensor plugin
 *
 * @author Jaeyoung Lim <jaeyoung@auterion.com>
 * @author Roman Bapst <roman@auterion.com>
 */

#pragma once

#include "common.h"
#include "mavlink_interface.h"
#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"

#include <FGFDMExec.h>

class SensorPlugin {
 public:
  SensorPlugin(JSBSim::FGFDMExec *jsbsim, msr::airlib::MultirotorRpcLibClient *client);
  ~SensorPlugin();
  virtual void setSensorConfigs(const TiXmlElement &configs) = 0;
  void setUpdateRate(double update_rate);
  bool updated();

 protected:
  JSBSim::FGFDMExec *_sim_ptr;
  msr::airlib::MultirotorRpcLibClient *_airsim_client;
  double _last_sim_time{0.};
  double _update_rate{0.};

  std::default_random_engine _random_generator;
};
