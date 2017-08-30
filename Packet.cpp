#include "Packet.h"

NetworkPacket::NetworkPacket() {

}

NetworkPacket::~NetworkPacket() {

}

DataPacket::DataPacket() : NetworkPacket() {
	engineRpm   = 0;
	speed       = 0;
	coolantTemp = 0;
	fuelLevel   = 0;

	isDriverPresent      = false;
	isTurnLeftOn         = false;
	isTurnRightOn        = false;
	isHeadlampOn         = false;
	hasOpenDoor          = false;
	hasOilPressure       = false;
	isParkingBrakeOn     = false;
	isKeyOnFirstPos      = false;
	isKeyAfterFirstPos   = false;
	isCranking           = false;
	hasDiagnosisSignal   = false;
	hasUcSignal          = false;
	isAlternatorOn       = false;
	isImobilizerOn       = false;
	isAirConditioningOn  = false;
	isDefrostOn          = false;
	isAirRecirculationOn = false;
	ventilatorPosition   = 0;
	ventilatorSpeed      = 0;
	areHazardLightsOn    = false;
}

DataPacket::~DataPacket() {

}

uint8_t DataPacket::getByteArraySize() {
	return sizeof(uint16_t) + 5 * sizeof(uint8_t) + 18 * sizeof(bool);
}

uint8_t DataPacket::toByteArray(uint8_t *buffer) const {
	uint8_t size = 0;
	uint8_t *ptr = buffer;

	memcpy(ptr, &engineRpm, sizeof(uint16_t));
	ptr += sizeof(uint16_t);
	size += sizeof(uint16_t);

	memcpy(ptr, &speed, sizeof(uint8_t));
	ptr += sizeof(uint8_t);
	size += sizeof(uint8_t);

	memcpy(ptr, &coolantTemp, sizeof(uint8_t));
	ptr += sizeof(uint8_t);
	size += sizeof(uint8_t);

	memcpy(ptr, &fuelLevel, sizeof(uint8_t));
	ptr += sizeof(uint8_t);
	size += sizeof(uint8_t);

	memcpy(ptr, &isDriverPresent, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isTurnLeftOn, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isTurnRightOn, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isHeadlampOn, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &hasOpenDoor, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &hasOilPressure, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isParkingBrakeOn, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isKeyOnFirstPos, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isKeyAfterFirstPos, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isCranking, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &hasDiagnosisSignal, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &hasUcSignal, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isAlternatorOn, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isImobilizerOn, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isAirConditioningOn, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isDefrostOn, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &isAirRecirculationOn, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	memcpy(ptr, &ventilatorPosition, sizeof(uint8_t));
	ptr += sizeof(uint8_t);
	size += sizeof(uint8_t);

	memcpy(ptr, &ventilatorSpeed, sizeof(uint8_t));
	ptr += sizeof(uint8_t);
	size += sizeof(uint8_t);

	memcpy(ptr, &areHazardLightsOn, sizeof(bool));
	ptr += sizeof(bool);
	size += sizeof(bool);

	return size;
}

DataPacket *DataPacket::fromByteArray(uint8_t *bytes) {
	DataPacket *packet = new DataPacket();

	memcpy(&(packet->engineRpm), bytes, sizeof(uint16_t));
	bytes += sizeof(uint16_t);

	memcpy(&(packet->speed), bytes, sizeof(uint8_t));
	bytes += sizeof(uint8_t);

	memcpy(&(packet->coolantTemp), bytes, sizeof(uint8_t));
	bytes += sizeof(uint8_t);

	memcpy(&(packet->fuelLevel), bytes, sizeof(uint8_t));
	bytes += sizeof(uint8_t);

	memcpy(&(packet->isDriverPresent), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isTurnLeftOn), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isTurnRightOn), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isHeadlampOn), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->hasOpenDoor), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->hasOilPressure), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isParkingBrakeOn), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isKeyOnFirstPos), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isKeyAfterFirstPos), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isCranking), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->hasDiagnosisSignal), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->hasUcSignal), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isAlternatorOn), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isImobilizerOn), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isAirConditioningOn), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isDefrostOn), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->isAirRecirculationOn), bytes, sizeof(bool));
	bytes += sizeof(bool);

	memcpy(&(packet->ventilatorPosition), bytes, sizeof(uint8_t));
	bytes += sizeof(uint8_t);

	memcpy(&(packet->ventilatorSpeed), bytes, sizeof(uint8_t));
	bytes += sizeof(uint8_t);

	memcpy(&(packet->areHazardLightsOn), bytes, sizeof(bool));
	bytes += sizeof(bool);
	
	return packet;
}

#ifdef QT_CORE_LIB
QString DataPacket::toJson() const {
	QJsonObject json;
	json["engineRpm"] = engineRpm;
	json["speed"] = speed;
	json["coolantTemp"] = coolantTemp;
	json["fuelLevel"] = fuelLevel;

	json["isDriverPresent"] = isDriverPresent;
	json["isTurnLeftOn"] = isTurnLeftOn;
	json["isTurnRightOn"] = isTurnRightOn;
	json["isHeadlampOn"] = isHeadlampOn;
	json["hasOpenDoor"] = hasOpenDoor;
	json["hasOilPressure"] = hasOilPressure;
	json["isParkingBrakeOn"] = isParkingBrakeOn;
	json["isKeyOnFirstPos"] = isKeyOnFirstPos;
	json["isKeyAfterFirstPos"] = isKeyAfterFirstPos;
	json["isCranking"] = isCranking;
	json["hasDiagnosisSignal"] = hasDiagnosisSignal;
	json["hasUcSignal"] = hasUcSignal;
	json["isAlternatorOn"] = isAlternatorOn;
	json["isImobilizerOn"] = isImobilizerOn;
	json["isAirConditioningOn"] = isAirConditioningOn;
	json["isDefrostOn"] = isDefrostOn;
	json["isAirRecirculationOn"] = isAirRecirculationOn;
	json["ventilatorPosition"] = ventilatorPosition;
	json["ventilatorSpeed"] = ventilatorSpeed;
	json["areHazardLightsOn"] = areHazardLightsOn;

	return QString(QJsonDocument(json).toJson());
}

DataPacket *DataPacket::fromJson(QJsonDocument json) {
	DataPacket *packet = new DataPacket();
	packet->engineRpm = json.object()["engineRpm"].toInt();
	packet->speed = json.object()["speed"].toInt();
	packet->coolantTemp = json.object()["coolantTemp"].toInt();
	packet->fuelLevel = json.object()["fuelLevel"].toInt();

	packet->isDriverPresent = json.object()["isDriverPresent"].toBool();
	packet->isTurnLeftOn = json.object()["isTurnLeftOn"].toBool();
	packet->isTurnRightOn = json.object()["isTurnRightOn"].toBool();
	packet->isHeadlampOn = json.object()["isHeadlampOn"].toBool();
	packet->hasOpenDoor = json.object()["hasOpenDoor"].toBool();
	packet->hasOilPressure = json.object()["hasOilPressure"].toBool();
	packet->isParkingBrakeOn = json.object()["isParkingBrakeOn"].toBool();
	packet->isKeyOnFirstPos = json.object()["isKeyOnFirstPos"].toBool();
	packet->isKeyAfterFirstPos = json.object()["isKeyAfterFirstPos"].toBool();
	packet->isCranking = json.object()["isCranking"].toBool();
	packet->hasDiagnosisSignal = json.object()["hasDiagnosisSignal"].toBool();
	packet->hasUcSignal = json.object()["hasUcSignal"].toBool();
	packet->isAlternatorOn = json.object()["isAlternatorOn"].toBool();
	packet->isImobilizerOn = json.object()["isImobilizerOn"].toBool();
	packet->isAirConditioningOn = json.object()["isAirConditioningOn"].toBool();
	packet->isDefrostOn = json.object()["isDefrostOn"].toBool();
	packet->isAirRecirculationOn = json.object()["isAirRecirculationOn"].toBool();
	packet->ventilatorPosition = json.object()["ventilatorPosition"].toInt();
	packet->ventilatorSpeed = json.object()["ventilatorSpeed"].toInt();
	packet->areHazardLightsOn = json.object()["areHazardLightsOn"].toBool();

	return packet;
}
#endif

RequestPacket::RequestPacket() : NetworkPacket() {
		
}

RequestPacket::~RequestPacket() {

}

uint8_t RequestPacket::toByteArray(uint8_t *buffer) const {
	uint8_t size = 3;

	if (module == "comfort") {
		buffer[0] = 0;
	} else {
		return 0;
	}

	if (action == "set-ventilator-position") {
		buffer[1] = 0;
	} else if (action == "set-ventilator-speed") {
		buffer[1] = 1;
	} else if (action == "set-air-conditioning") {
		buffer[1] = 2;
	} else if (action == "set-air-recirculation") {
		buffer[1] = 3;
	} else if (action == "set-hazard-lights") {
		buffer[1] = 4;
	} else if (action == "toggle-door-locks") {
		buffer[1] = 5;
	} else if (action == "toggle-defrost") {
		buffer[1] = 6;
	} else if (action == "open-trunk") {
		buffer[1] = 7;
	} else {
		return 0;
	}

	buffer[2] = 0;
	if (data.length() > 0) {
		size++;
		buffer[2] = 1;
		switch (dataType) {
			case PACKET_DATA_TYPE_BOOL: {
				buffer[3] = PACKET_DATA_TYPE_BOOL;
				bool b = (bool) atoi(data.c_str());
				memcpy(buffer + size, &b, sizeof(bool));
				size += sizeof(bool);
				break;
			}

			case PACKET_DATA_TYPE_INTEGER: {
				buffer[3] = PACKET_DATA_TYPE_INTEGER;
				int64_t i = (int64_t) atol(data.c_str());
				memcpy(buffer + size, &i, sizeof(int64_t));
				size += sizeof(int64_t);
				break;
			}

			case PACKET_DATA_TYPE_DOUBLE: {
				buffer[3] = PACKET_DATA_TYPE_DOUBLE;
				double f = (double) atof(data.c_str());
				memcpy(buffer + size, &f, sizeof(double));
				size += sizeof(double);
				break;
			}

			case PACKET_DATA_TYPE_STRING: {
				size++;
				buffer[3] = PACKET_DATA_TYPE_STRING;
				buffer[4] = (uint8_t) data.length();
				memcpy(buffer + size, data.c_str(), data.length());
				size += data.length();
				break;
			}

			default:
				return 0;
		}
	}

	return size;
}

uint8_t RequestPacket::getByteArraySize() {
	return BUFFER_LENGTH;
}

RequestPacket *RequestPacket::fromByteArray(uint8_t *bytes) {
	RequestPacket *packet = new RequestPacket();
	
	switch (bytes[0]) {
		case 0:
			packet->module = "comfort";
			break;

		default:
			return NULL;
	}

	switch (bytes[1]) {
		case 0:
			packet->action = "set-ventilator-position";
			break;

		case 1:
			packet->action = "set-ventilator-speed";
			break;

		case 2:
			packet->action = "set-air-conditioning";
			break;

		case 3:
			packet->action = "set-air-recirculation";
			break;

		case 4:
			packet->action = "set-hazard-lights";
			break;

		case 5:
			packet->action = "toggle-door-locks";
			break;

		case 6:
			packet->action = "toggle-defrost";
			break;

		case 7:
			packet->action = "open-trunk";
			break;

		default:
			return NULL;
	}

	if (bytes[2]) {
		PacketDataType_t type = (PacketDataType_t) bytes[3];
		switch (type) {
			case PACKET_DATA_TYPE_BOOL: {
				bool b;
				memcpy(&b, &(bytes[4]), sizeof(bool));
				stringstream ss;
				ss << b;
				packet->data = ss.str();
				break;
			}

			case PACKET_DATA_TYPE_INTEGER: {
				int64_t i;
				memcpy(&i, &(bytes[4]), sizeof(int64_t));
				stringstream ss;
				ss << i;
				packet->data = ss.str();
				break;
			}

			case PACKET_DATA_TYPE_DOUBLE: {
				double f;
				memcpy(&f, &(bytes[4]), sizeof(double));
				stringstream ss;
				ss << f;
				packet->data = ss.str();
				break;
			}

			case PACKET_DATA_TYPE_STRING: {
				uint8_t length;
				memcpy(&length, &(bytes[4]), sizeof(uint8_t));
				
				char *buffer = new char[length + 1];
				memcpy(buffer, &(bytes[5]), length);
				buffer[length] = '\0';

				packet->data = string(buffer);
				delete[] buffer;
				break;
			}

			default:
				return NULL;
		}
	}

	return packet;
}

#ifdef QT_CORE_LIB
QString RequestPacket::toJson() const {
	QJsonObject json;
	json["module"] = QJsonValue(module.c_str());
	json["action"] = QJsonValue(action.c_str());

	switch (dataType) {
		case PACKET_DATA_TYPE_BOOL: {
			json["data"] = QJsonValue((bool) atoi(data.c_str()));
			break;
		}

		case PACKET_DATA_TYPE_INTEGER: {
			json["data"] = QJsonValue((qint64) atol(data.c_str()));
			break;
		}

		case PACKET_DATA_TYPE_DOUBLE: {
			json["data"] = QJsonValue((double) atof(data.c_str()));
			break;
		}

		case PACKET_DATA_TYPE_STRING:
		default: {
			json["data"] = QJsonValue(data.c_str());
		}
	}

	return QString(QJsonDocument(json).toJson());
}

RequestPacket *RequestPacket::fromJson(QJsonDocument json) {
	RequestPacket *packet = new RequestPacket();
	packet->module = json.object()["module"].toString().toStdString();
	packet->action = json.object()["action"].toString().toStdString();

	if (json.object().contains("data")) {
		if (json.object()["data"].isBool()) {
			packet->dataType = PACKET_DATA_TYPE_BOOL;
			packet->data = QString::number(json.object()["data"].toBool()).toStdString();
		} else if (json.object()["data"].isDouble()) {
			double value = json.object()["data"].toDouble();
			if ((value - (int32_t) value) < 0.000001) {
				packet->dataType = PACKET_DATA_TYPE_INTEGER;
				packet->data = QString::number((int32_t) value).toStdString();
			} else {
				packet->dataType = PACKET_DATA_TYPE_DOUBLE;
				packet->data = QString::number(value).toStdString();
			}
		} else if (json.object()["data"].isString()) {
			packet->dataType = PACKET_DATA_TYPE_STRING;
			packet->data = json.object()["data"].toString().toStdString();
		}
	}

	return packet;
}
#endif