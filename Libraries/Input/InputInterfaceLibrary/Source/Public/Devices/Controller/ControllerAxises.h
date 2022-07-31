#pragma once

namespace Input
{
	enum class ControllerTrigger
	{
		Left,
		Right,
	};

	enum class ControllerAnalogueStick
	{
		Left,
		Right,
	};

	enum class ControllerAxis
	{
		// GAMEPAD
		LEFT_STICK_X,
		LEFT_STICK_Y,
		RIGHT_STICK_X,
		RIGHT_STICK_Y,
		LEFT_TRIGGER,
		RIGHT_TRIGGER,

		// WHEEL
		WHEEL_ROTATION = LEFT_STICK_X,
		ACCELERATION_PEDAL = RIGHT_TRIGGER,
		BRAKE_PEDAL = LEFT_TRIGGER,

		// FLIGHT STICK
		PITCH = LEFT_STICK_X,
		ROLL = LEFT_STICK_Y,
		YAW = LEFT_TRIGGER,
		RUDDER = LEFT_TRIGGER,
		THROTTLE = RIGHT_TRIGGER
	};
}
