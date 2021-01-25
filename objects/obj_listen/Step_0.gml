/// @description Insert description here
// You can write your code in this editor

var zone = instance_place(x,y,obj_zone);
var str = 0;
str = gmw_SetSwitch(1834394558,zone.soundSwich,id);
show_debug_message("gmw_SetSwitch: " + string(str));
if (keyboard_check_pressed(vk_left)){
	x-=20;
	gmw_PostEvent(3854155799,id);
	//show_debug_message("gmw_PostEvent: " + string(str));
}

if (keyboard_check_pressed(vk_right)){
	x+=20;
	gmw_PostEvent(3854155799,id);
	//show_debug_message("gmw_PostEvent: " + string(str));
}

if (keyboard_check_pressed(vk_down)){
	y+= 20;
	gmw_PostEvent(3854155799,id);
	//show_debug_message("gmw_PostEvent: " + string(str));
}
if (keyboard_check_pressed(vk_up)){
	y-= 20;
	gmw_PostEvent(3854155799,id);
	//show_debug_message("gmw_PostEvent: " + string(str));
}