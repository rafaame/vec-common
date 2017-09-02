#ifndef PACKET_H
#define PACKET_H

#include "common.h"
#include "const.h"

using namespace std;

enum PacketDataType_t {
	PACKET_DATA_TYPE_BOOL,
	PACKET_DATA_TYPE_INTEGER,
	PACKET_DATA_TYPE_DOUBLE,
	PACKET_DATA_TYPE_STRING
};

class NetworkPacket {
public:
	NetworkPacket();
	virtual ~NetworkPacket();

	virtual uint8_t toByteArray(uint8_t *buffer) const = 0;

#ifdef QT_CORE_LIB
	virtual QString toJson() const = 0;
#endif
};

class DataPacket : public NetworkPacket {
public:
	uint16_t engineRpm;
	uint8_t speed;
	uint8_t coolantTemp;
	uint8_t fuelLevel;

	bool isDriverPresent;
	bool isTurnLeftOn;
	bool isTurnRightOn;
	bool isHeadlampOn;
	bool hasOpenDoor;
	bool hasOilPressure;
	bool isParkingBrakeOn;
	bool isKeyOnFirstPos;
	bool isKeyAfterFirstPos;
	bool isCranking;
	bool hasDiagnosisSignal;
	bool hasUcSignal;
	bool isAlternatorOn;
	bool isImobilizerOn;
	bool isAirConditioningOn;
	bool isDefrostOn;
	bool isAirRecirculationOn;
	uint8_t ventilatorPosition;
	uint8_t ventilatorSpeed;
	bool areHazardLightsOn;

	DataPacket();
	virtual ~DataPacket();

	static uint8_t getByteArraySize();
	virtual uint8_t toByteArray(uint8_t *buffer) const;
	static DataPacket *fromByteArray(uint8_t *bytes);

#ifdef QT_CORE_LIB
	virtual QString toJson() const;
	static DataPacket *fromJson(QJsonDocument json);
#endif
};

class RequestPacket : public NetworkPacket {
public:
	string module;
	string action;
	PacketDataType_t dataType;
	string data;

	RequestPacket();
	virtual ~RequestPacket();

	static uint8_t getByteArraySize();
	virtual uint8_t toByteArray(uint8_t *buffer) const;
	static RequestPacket *fromByteArray(uint8_t *bytes);

#ifdef QT_CORE_LIB
	virtual QString toJson() const;
	static RequestPacket *fromJson(QJsonDocument json);
#endif
};

#ifdef QT_CORE_LIB
Q_DECLARE_METATYPE(DataPacket)
Q_DECLARE_METATYPE(RequestPacket)
#endif

#endif