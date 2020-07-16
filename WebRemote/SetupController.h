﻿#pragma once
#pragma once
#include "WebUIController.h"

enum PotentiometerLinearity {
	Linear,
	X2_div_X
};


struct ConfigStruct {
public:

	String ssid;
	String password;

	int min_speed;
	int inertion;

	int gun_min;
	int gun_max;

	int fire_min;
	int fire_max;
	int fire_duration;

	int turbine_min;//0..100
	int turbine_max;//0..100
	int turbine_frequency_min;
	int turbine_frequency_max;

	int smoke_min;//0..300
	int smoke_max;//0..300

};

typedef void(*myFunctionPointer) ();

class SetupController
{
public:
	ConfigStruct* cfg;

	SetupController();
	~SetupController();

	void loadConfig();
	void saveConfig();
	void printConfig(JsonString* out);

	static void Setup_Get();
	static void Setup_Post();

	myFunctionPointer reloadConfig = nullptr;
};


extern SetupController setupController;