
if(alarm[0]<0){
	lockJump = false;
	lockJumpTime = false;
	}

show_debug_message("switch: " + string(other.soundSwich));
show_debug_message( gmw_SetSwitch(2966532765,other.soundSwich,1));