/// @description Insert description here
// You can write your code in this editor
//if( keyboard_check(vk_left))  speedh -= walk_acc * aniAcc ;
//if( keyboard_check(vk_right)) speedh +=  walk_acc * aniAcc ;
//gmw_SetPosition(); /// x et y 

mo = (mo+1) mod 20;
//if(mo==0)gmw_PostEvent(0000,id);



if( keyboard_check(vk_left))  physics_apply_force(x,y,-walk_acc,0);
if( keyboard_check(vk_right)) physics_apply_force(x,y, walk_acc,0);

if( keyboard_check(vk_space) && !lockJump){
	
	if(!lockJumpTime ){alarm[0]= timeJump; lockJumpTime = true;}
	physics_apply_force(x,y,0,-jump_acc);
	
}

if(keyboard_check_pressed(vk_enter))show_debug_message(gmw_PostEvent(1928490972,global.listener));
//if( mo == 0)  
gmw_SetPosition2D(global.listener ,(x/room_width - 0.5)*200,(y/room_height -0.5)*200);
//show_debug_message("setPosition : " + string(gmw_SetPosition2D(global.listener,(x/room_width - 0.5)*200,(y/room_height -0.5)*200)));
//show_debug_message("setPosition : "  + string(gmw_SetPosition2D(id,x,y) ));
