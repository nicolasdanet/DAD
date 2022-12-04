
/* Copyright (c) 2022 Nicolas Danet. */

/* < https://opensource.org/licenses/GPL-3.0 > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

namespace core {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

struct CSV {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

enum Item : int {
    latitude                    = 0,
    longitude                   = 1,
    altitude_m,
    ultrasonicHeight_m,
    speed_mps,
    distance_m,
    max_altitude_m,
    max_ascent_m,
    max_speed_mps,
    max_distance_m,
    time_millisecond,
    datetime_utc,
    datetime_local,
    satellites,
    pressure_Pa,
    temperature_F,
    voltage_v,
    home_latitude,
    home_longitude,
    velocityX_mps,
    velocityY_mps,
    velocityZ_mps,
    pitch_deg,
    roll_deg,
    yaw_deg,
    powerlevel,
    isflying,
    istakingphoto,
    remainPowerPercent,
    remainLifePercent,
    currentCurrent,
    currentElectricity,
    currentVoltage,
    batteryTemperature,
    dischargeCount,
    flightmode,
    isMotorsOn,
    isTakingVideo,
    Rc_elevator,
    Rc_aileron,
    Rc_throttle,
    Rc_rudder,
    Rc_gyro,
    timestamp,
    Battery_Cell1,
    Battery_Cell2,
    Battery_Cell3,
    Battery_Cell4,
    Battery_Cell5,
    Battery_Cell6,
    Dronetype,
    AppVersion,
    Planename,
    FlyControllerSerialNumber,
    RemoteSerialNumber,
    BatterySerialNumber,
    CENTER_BATTERY_productDate,
    CENTER_BATTERY_serialNo,
    CENTER_BATTERY_fullCapacity,
    CENTER_BATTERY_productDateRaw,
    pitchRaw,
    rollRaw,
    yawRaw,
    gimbalPitchRaw,
    gimbalRollRaw,
    gimbalYawRaw,
    flyState,
    altitudeRaw,
    speedRaw,
    distanceRaw,
    velocityXRaw,
    velocityYRaw,
    velocityZRaw,
    data_reuse,
    App_Tip,
    App_Warning,
    downlinkSignalQuality,
    uplinkSignalQuality,
    transmissionChannel,
    rcModeSwitch,
    rcHome,
    rcPause,
    rcTransform,
    rcJoystickMode,
    appMode,
    FlyControllerSerialNumber_legacy,
    RemoteSerialNumber_legacy,
    BatterySerialNumber_legacy,
    Battery2SerialNumber,
    frontAvoidDist,
    backAvoidDist,
    isBrakingToAvoid
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

static constexpr int size() { return static_cast<int> (Item::isBrakingToAvoid) + 1; };

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

static juce::String header()
{
    return "latitude,longitude,altitude(m),ultrasonicHeight(m),speed(mps),distance(m),max_altitude(m),max_ascent(m),max_speed(mps),max_distance(m),time(millisecond),datetime(utc),datetime(local),satellites,pressure(Pa),temperature(F),voltage(v),home_latitude,home_longitude,velocityX(mps),velocityY(mps),velocityZ(mps),pitch(deg),roll(deg),yaw(deg),powerlevel,isflying,istakingphoto,remainPowerPercent,remainLifePercent,currentCurrent,currentElectricity,currentVoltage,batteryTemperature,dischargeCount,flightmode,isMotorsOn,isTakingVideo,Rc_elevator,Rc_aileron,Rc_throttle,Rc_rudder,Rc_gyro,timestamp,Battery_Cell1,Battery_Cell2,Battery_Cell3,Battery_Cell4,Battery_Cell5,Battery_Cell6,Dronetype,AppVersion,Planename,FlyControllerSerialNumber,RemoteSerialNumber,BatterySerialNumber,CENTER_BATTERY.productDate,CENTER_BATTERY.serialNo,CENTER_BATTERY.fullCapacity,CENTER_BATTERY.productDateRaw,pitchRaw,rollRaw,yawRaw,gimbalPitchRaw,gimbalRollRaw,gimbalYawRaw,flyState,altitudeRaw,speedRaw,distanceRaw,velocityXRaw,velocityYRaw,velocityZRaw,data_reuse,App_Tip,App_Warning,downlinkSignalQuality,uplinkSignalQuality,transmissionChannel,rcModeSwitch,rcHome,rcPause,rcTransform,rcJoystickMode,appMode,FlyControllerSerialNumber_legacy,RemoteSerialNumber_legacy,BatterySerialNumber_legacy,Battery2SerialNumber,frontAvoidDist,backAvoidDist,isBrakingToAvoid";
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

