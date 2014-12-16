#include "Trigger.h"
#include <Arduino.h>
#include <Time.h>

Trigger::Trigger(){

	this->isEnabled = false;
	this->state = WAITING;
	this->activationTime = 0;
	this->minute = 0;
	this->hour = 0;
	this->startTime = 0;

}

void Trigger::setTime(int hour, int minute){

	this->minute = minute;
	this->hour = hour;

}

int Trigger::getMinute(){

	return this->minute;
}

int Trigger::getHour(){

	return Trigger::hour;
}

boolean Trigger::checkTrigger(){

	TimeElements tTime;
	breakTime(now(),tTime);

	tTime.Hour = this->getHour();
	tTime.Minute = this->getMinute();


		if ( (now() >= makeTime(tTime))
			&& (now() < makeTime(tTime)+(Trigger::activationTime*60)) ){

				Trigger::state = Trigger::WATERING;
				return true;
			}
			else
				{
				Trigger::state = Trigger::WAITING;
				return false;
				}




	}

void Trigger::setActivationTime(int minutes){

this->activationTime = minutes;

}
