/*
;    Project:       Open Vehicle Monitor System
;    Date:          14th March 2017
;
;    Changes:
;    1.0  Initial release
;
;    (C) 2011       Michael Stegen / Stegen Electronics
;    (C) 2011-2017  Mark Webb-Johnson
;    (C) 2011        Sonny Chen @ EPRO/DX
;
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so, subject to the following conditions:
;
; The above copyright notice and this permission notice shall be included in
; all copies or substantial portions of the Software.
;
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
; THE SOFTWARE.
*/

#ifndef __VEHICLE_TOYOTARAV4EV_H__
#define __VEHICLE_TOYOTARAV4EV_H__

#include "vehicle.h"
#include "ovms_metrics.h"
#include "ovms_webserver.h"

using namespace std;

#define TS_CANDATA_TIMEOUT 10

class OvmsVehicleToyotaRav4Ev: public OvmsVehicle
  {
  public:
    OvmsVehicleToyotaRav4Ev();
    ~OvmsVehicleToyotaRav4Ev();

  public:
    void IncomingFrameCan1(CAN_frame_t* p_frame);
    void IncomingFrameCan2(CAN_frame_t* p_frame);
    void IncomingFrameCan3(CAN_frame_t* p_frame);

  protected:
    virtual void Ticker1(uint32_t ticker);
    virtual void Ticker60(uint32_t ticker);
    virtual void Notify12vCritical();
    virtual void Notify12vRecovered();
    virtual void NotifyBmsAlerts();

/*
#ifdef CONFIG_OVMS_COMP_TPMS
  public:
    virtual bool TPMSRead(std::vector<uint32_t> *tpms);
    virtual bool TPMSWrite(std::vector<uint32_t> &tpms);

  protected:
    typedef enum
      {
      Idle = 0,
      Reading,
      DoneReading,
      ReadFailed,
      Writing,
      DoneWriting,
      Writefailed
    } tpms_command_t;
    tpms_command_t m_tpms_cmd;
    uint8_t m_tpms_data[16];
    int m_tpms_pos;
    uint16_t m_tpms_uds_seed;
#endif // #ifdef CONFIG_OVMS_COMP_TPMS
*/

  protected:
    char m_vin[18];
    char m_type[5];
    uint16_t m_charge_w;
    unsigned int m_candata_timer;
    
    OvmsMetricFloat *m_v_bat_cool_in_temp;
    OvmsMetricFloat *m_v_bat_cool_out_temp;
    OvmsMetricFloat *m_v_mot_cool_in_temp;
    OvmsMetricFloat *m_v_mot_cool_out_temp;
    OvmsMetricFloat *m_v_bat_energy_avail;
    OvmsMetricInt *m_v_bat_cool_pump_1;
    OvmsMetricInt *m_v_bat_cool_pump_2;
    OvmsMetricInt *m_v_mot_cool_pump;

  };

#endif //#ifndef __VEHICLE_TOYOTARAV4EV_H__
