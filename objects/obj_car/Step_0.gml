/// @description Insert description here
// You can write your code in this editor
var str = 0;

if (keyboard_check_pressed(vk_left)){
	x-=20;
	str = gmw_SetRTCPValue(796049864,(x/room_width)*(10000 - 1000) + 1000);
	//show_debug_message("gmw_PostEvent: " + string(str));
}

if (keyboard_check_pressed(vk_right)){
	x+=20;
	str = gmw_SetRTCPValue(796049864,(x/room_width)*(10000 - 1000) + 1000);
	//show_debug_message("gmw_PostEvent: " + string(str));
}