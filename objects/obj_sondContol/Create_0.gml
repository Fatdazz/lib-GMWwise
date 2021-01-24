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
show_debug_message("libWwise.bnk : "  + string(gmw_LoadBank("libWwise.bnk") ));