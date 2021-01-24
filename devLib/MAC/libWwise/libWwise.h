//
//  libWwise.hpp
//  libWwise
//
//  Created by FatDazz on 21/01/2021.
//  Copyright © 2021 FatDazz. All rights reserved.
//

//sous mac
// cd /Users/fatdazz/Library/Application\ Support/com.yoyogames.macyoyorunner/game/assets/
// rm libWwise

#ifndef libWwise_
#define libWwise_
#define GMW_VERSION_STRING "0.0.1"

#include <stdio.h>
#include <string.h>
#include <vector>

#define STDCALL

#if !defined( _MSC_VER)
#define GMW_EXPORT __attribute__((visibility("default")))
#else
#define GMW_EXPORT __declspec(dllexport)
#define snprintf sprintf_s
#define strdup _strdup
#endif


//#define AK_OPTIMIZED


#include <AK/SoundEngine/Common/AkStreamMgrModule.h>
#include <AK/IBytes.h>

#include <AK/SoundEngine/Common/AkMemoryMgr.h>                  // Memory Manager interface
#include <AK/SoundEngine/Common/AkModule.h>                     // Default memory manager

#include <AK/SoundEngine/Common/IAkStreamMgr.h>                 // Streaming Manager
#include <AK/Tools/Common/AkPlatformFuncs.h>                    // Thread defines
#include "AkFilePackageLowLevelIOBlocking.h"

CAkFilePackageLowLevelIOBlocking g_lowLevelIO;

#include <AK/SoundEngine/Common/AkSoundEngine.h>                // Sound engine
#include <AK/MusicEngine/Common/AkMusicEngine.h>                // Music Engine

#include <AK/SpatialAudio/Common/AkSpatialAudio.h>              // Spatial Audio

#include <AK/SoundEngine/Common/IAkPlugin.h>

// Effect plug-ins
#include <AK/Plugin/AkCompressorFXFactory.h>                    // Compressor
#include <AK/Plugin/AkDelayFXFactory.h>                            // Delay
#include <AK/Plugin/AkMatrixReverbFXFactory.h>                    // Matrix reverb
#include <AK/Plugin/AkMeterFXFactory.h>                            // Meter
#include <AK/Plugin/AkExpanderFXFactory.h>                        // Expander
#include <AK/Plugin/AkParametricEQFXFactory.h>                    // Parametric equalizer
#include <AK/Plugin/AkGainFXFactory.h>                            // Gain
#include <AK/Plugin/AkPeakLimiterFXFactory.h>                    // Peak limiter
#include <AK/Plugin/AkRoomVerbFXFactory.h>                        // RoomVerb
#include <AK/Plugin/AkGuitarDistortionFXFactory.h>                // Guitar distortion
#include <AK/Plugin/AkStereoDelayFXFactory.h>                    // Stereo delay
#include <AK/Plugin/AkPitchShifterFXFactory.h>                    // Pitch shifter
#include <AK/Plugin/AkTimeStretchFXFactory.h>                    // Time stretch
#include <AK/Plugin/AkFlangerFXFactory.h>                        // Flanger
#include <AK/Plugin/AkTremoloFXFactory.h>                        // Tremolo
#include <AK/Plugin/AkHarmonizerFXFactory.h>                    // Harmonizer
#include <AK/Plugin/AkRecorderFXFactory.h>                        // Recorder

#include <AK/Plugin/AkSilenceSourceFactory.h>                    // Silence generator
#include <AK/Plugin/AkSineSourceFactory.h>                        // Sine wave generator
#include <AK/Plugin/AkToneSourceFactory.h>                        // Tone generator
#include <AK/Plugin/AkAudioInputSourceFactory.h>                // Audio input
#include <AK/Plugin/AkSynthOneSourceFactory.h>                    // SynthOne

// Include for communication between Wwise and the game -- Not needed in the release version
#ifndef AK_OPTIMIZED
#include <AK/Comm/AkCommunication.h>
#endif // AK_OPTIMIZED



extern "C" {
    static bool g_Initialised = false;
    static std::vector<AkBankID> bancksLoaded;
    //static const AkGameObjectID aLstnrsForEmitter[1];
    static wchar_t* wlng_bank = 0;
    static wchar_t* wlng_path = 0;
    static wchar_t* wlng_language = 0;
    
    GMW_EXPORT double MyExtension_Init( void );
    GMW_EXPORT double MyExtension_Function( double _value );
    
    
    GMW_EXPORT double gmw_Init( void );
    GMW_EXPORT double gmw_Render( void );
    GMW_EXPORT double gmw_Term( void );
    
    
    GMW_EXPORT double gmw_SetBasePath(char* _text);
    GMW_EXPORT double gmw_SetBaseLanguage(char* _text);
    GMW_EXPORT double gmw_LoadBank( char* _text );
    
    
    GMW_EXPORT double gmw_RegisterGameObjet(double _gameObjId);
    GMW_EXPORT double gmw_UnregisterGameObj(double _gameObjId);
    
    GMW_EXPORT double gmw_SetDefaultListeners(double _gameObjId);
    GMW_EXPORT double gmw_RegisterListener(double _gameObjId);
    GMW_EXPORT double gmw_SetListeners(double _listenId, double _gameObjId);
    
    
    GMW_EXPORT double gmw_PostEvent(double _eventId,double _gameObjId);
    GMW_EXPORT double gmw_PostEventPosition(double _eventId,double _gameObjId);
    GMW_EXPORT double gmw_StopAll(void);
    GMW_EXPORT double gmw_StopPlayingID(double in_playingID);
    GMW_EXPORT double gmw_ExecuteActionOnPlayingID(double in_playingID,double _ActionOnEventType, double in_uTransitionDuration, double in_eFadeCurve);
    
    GMW_EXPORT double gmw_GetSourcePlayPosition(double iPlayingID);
    
    
    GMW_EXPORT double gmw_SetPosition2D(double _gameObjId, double _x, double _y);
    GMW_EXPORT double gmw_SetRTCPValue(double _RTCP,double _valure);
    GMW_EXPORT double gmw_SetSwitch(double _group, double _switch, double _gameObjId);
    
}

#endif // libWwise_
