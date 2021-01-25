/// @description Insert description here
// You can write your code in this editor
global.listener = id;
lockJump = false
lockJumpTime = false;
phy_active = true;
phy_fixed_rotation  = true;

show_debug_message("id avatar: " + string(id));
gmw_RegisterGameObjet(id);
show_debug_message("gmw_SetListeners : "  + string(gmw_SetListeners(global.listener,id) ));
show_debug_message("gmw_RegisterListener : "  + string(gmw_RegisterListener(id) ));

//
mo = 0;
//gmw_PostEvent(683783014,id);