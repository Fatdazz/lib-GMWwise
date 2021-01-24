/// @description Insert description here
// You can write your code in this editor
show_debug_message("id brid: " + string(id) + " x: " + string(x));
gmw_RegisterGameObjet(id);
show_debug_message("gmw_SetListeners : "  + string(gmw_SetListeners(global.listener,id) ));
show_debug_message(" brid : " + string(gmw_SetPosition2D(id,(x/room_width - 0.5)*200,(y/room_height -0.5)*200)));
gmw_PostEvent(3894661812,id);
