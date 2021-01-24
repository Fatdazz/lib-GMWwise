/// @description Insert description here
// You can write your code in this editor

for(var i = 0; i < phy_collision_points ; i ++){
	
	if( phy_col_normal_y[i] < 0 ){
		lockJump = false;
		lockJumpTime = false;
		//show_debug_message(	  "phy_col_normal_x: " + string(phy_col_normal_x[i])
		//				+ " phy_col_normal_y: " + string(phy_col_normal_y[i]) + " t: " + string(current_time) );
		
		}
	if(phy_col_normal_y[i]>0){
		lockJump = true;
		alarm[0] = -1;
	}
	
}
