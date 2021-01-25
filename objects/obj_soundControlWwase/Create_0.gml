/// @description Insert description here
// You can write your code in this editor
show_debug_message("init : "  + string(gmw_Init() ));

if (os_type == os_macosx)
    var path = working_directory + "sound/banks/Mac/";
else
    var path = working_directory + "sound/banks/Windows/";


show_debug_message("Path : "  + string(gmw_SetBasePath(path) ));
show_debug_message("langue : "  + string(gmw_SetBaseLanguage("English(US)") ));
show_debug_message("init.bnk : "  + string(gmw_LoadBank("Init.bnk") ));
show_debug_message("Metal.bnk : "  + string(gmw_LoadBank("Metal.bnk") ));
show_debug_message("Gravel.bnk : "  + string(gmw_LoadBank("Gravel.bnk") ));

show_debug_message("Dirt.bnk : "  + string(gmw_LoadBank("Dirt.bnk") ));
show_debug_message("Wood.bnk : "  + string(gmw_LoadBank("Wood.bnk") ));


