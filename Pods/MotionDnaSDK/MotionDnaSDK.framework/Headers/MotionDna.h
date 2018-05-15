#ifndef MOTIONDNA_DATA_H
#define MOTIONDNA_DATA_H

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

enum MotionType
  {
    STATIONARY,
    FIDGETING,
    FORWARD
  };
typedef enum MotionType MotionType;

enum ErrorCode
  {
    SENSOR_TIMING = 0,
    AUTHENTICATION_FAILED = 1,
    SENSOR_MISSING = 2,
    SDK_EXPIRED = 3,
    WRONG_FLOOR_INPUT = 4
  };
typedef enum ErrorCode ErrorCode;

enum PowerConsumptionMode
  {
    SUPER_LOW_CONSUMPTION,
    LOW_CONSUMPTION,
    MEDIUM_CONSUMPTION,
    PERFORMANCE
  };
typedef enum PowerConsumptionMode PowerConsumptionMode;

enum ExternalPositioningState
  {
    OFF,
    HIGH_ACCURACY,
    LOW_ACCURACY,
    EXTERNAL_UNDEFINED
  };
typedef enum ExternalPositioningState ExternalPositioningState;


enum LocationStatus
  {
    UNINITIALIZED,
    USER_INITIALIZED,
    GPS_INITIALIZED,
    NAVISENS_INITIALIZING,
    NAVISENS_INITIALIZED,
    BEACON_INITIALIZED
  };
typedef enum LocationStatus LocationStatus;
  

enum VerticalMotionStatus
{
  VERTICAL_STATUS_LEVEL_GROUND = 0,
  VERTICAL_STATUS_ESCALATOR_UP = 1,
  VERTICAL_STATUS_ESCALATOR_DOWN = -1,
  VERTICAL_STATUS_ELEVATOR_UP = 2,
  VERTICAL_STATUS_ELEVATOR_DOWN = -2,
  VERTICAL_STATUS_STAIRS_UP = 3,
  VERTICAL_STATUS_STAIRS_DOWN = -3,
};
typedef enum VerticalMotionStatus VerticalMotionStatus;


enum CalibrationStatus
  {
    DONE,
    CALIBRATING,
    NONE
  };
typedef enum CalibrationStatus CalibrationStatus;

enum EstimationMode
{
  LOCAL,
  GLOBAL
};
typedef enum EstimationMode EstimationMode;

enum NetworkCode
{
  RAW_NETWORK_DATA,
  ROOM_CAPACITY_STATUS,
  EXCEEDED_ROOM_CONNECTION_CAPACITY,
  EXCEEDED_SERVER_ROOM_CAPACITY
};
typedef enum NetworkCode NetworkCode;

struct MotionStatistics
{
  double dwelling;
  double walking;
  double stationary;
};
typedef struct MotionStatistics MotionStatistics;


struct Attitude
{
  double roll;
  double pitch;
  double yaw;
};
typedef struct Attitude Attitude;

struct XYZ
{
  double x;
  double y;
  double z;
};
typedef struct XYZ XYZ;

struct XY
{
  double x;
  double y;
};
typedef struct XY XY;

struct GlobalLocation
{
  double latitude;
  double longitude;
  double altitude;
};
typedef struct GlobalLocation GlobalLocation;

struct OrientationQuaternion
{
  double w;
  double x;
  double y;
  double z;
};
typedef struct OrientationQuaternion OrientationQuaternion;

struct Location
{
  LocationStatus locationStatus;
  XYZ localLocation;
  GlobalLocation globalLocation;
  double heading;
  double localHeading;
  XY uncertainty;
  VerticalMotionStatus verticalMotionStatus;
  int floor;
  double absoluteAltitude;
  double absoluteAltitudeUncertainty;
};
typedef struct Location Location;

struct Motion
{
  double stepFrequency;
  MotionType motionType;
};
typedef struct Motion Motion;

enum MapObjectType
  {
    street = 0,
    building = 1,
    voronoi = 2,
    door = 3,
    store = 4,
    elevator = 5,
    escalator = 6,
    obstacle = 7,
    building_side = 8,
    traversable = 9,
    natural = 10,
    parking = 11,
    ble = 12,
    invalid = -1,
    unknown = -2
  };
typedef enum MapObjectType MapObjectType;

@interface MotionDna : NSObject<NSObject>
{
  @protected
  Location location_;
  Location GPSLocation_;
  Attitude attitude_;
  Motion motion_;
  CalibrationStatus calibrationStatus_;
  NSString * ID_;
  NSString * deviceName_;
  NSString * motionName_;
  MotionStatistics motionStatistics_;
  MotionStatistics polygonMotionStatistics_;
  OrientationQuaternion quaternion_;
}

-(Location)getLocation;
-(Location)getGPSLocation;
-(Attitude)getAttitude;
-(Motion)getMotion;
-(CalibrationStatus)getCalibrationStatus;
-(NSString*)getID;
-(NSString*)getDeviceName;
-(NSString*)getMotionName;
-(MotionStatistics)getMotionStatistics;
-(MotionStatistics)getPolygonMotionStatistics;
-(OrientationQuaternion)getQuaternion;
-(XY)getDebugVector;
@end

#endif
