// Add global variables here

typedef struct
{
	int threshold_;	// joystick threshold
	float max_power_;	// maximum power applied to robot drive motors

	// IRSeeker Information
	int direction_;	// value of 1 - 9, with 5 being dead ahead
	int ss1_;	// Channel 1 signal strength
	int ss2_;	// Channel 2 signal strength
	int ss3_;	// Channel 3 signal strength
	int ss4_;	// Channel 4 signal strength
	int ss5_;	// Channel 5 signal strength

	bool joyEnabled; // joystick 1 responsive state ( "true" = reponds to controller input, "false" = ignores input )

} TGlobVars;

TGlobVars GlobVars;
