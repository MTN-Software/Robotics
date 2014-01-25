// Add global functions here

// Transfer function to convert joystick position to power level
short ApplyPower( short joystick_position, float max_power )
{
	float power;

	if( joystick_position < 0)
	{
		power = ( (float)joystick_position / 128.0 ) * max_power;
		return( (short)power );
	}
	else
	{
		power = ( (float)joystick_position / 127.0 ) * max_power;
		return( (short)power );
	}
}
