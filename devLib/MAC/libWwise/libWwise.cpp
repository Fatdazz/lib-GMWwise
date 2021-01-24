//
//  libWwise.cpp
//  libWwise
//
//  Created by FatDazz on 21/01/2021.
//  Copyright © 2021 FatDazz. All rights reserved.
//
#include "libWwise.h"
#include <iostream>
extern "C" {
#if defined(_WIN32)
    // Allocates a string
    char* stralloc(size_t size)
    {
        return new char[size];
    }
    
    // Allocates a wchar_t string
    wchar_t* wstralloc(size_t size){
        return new wchar_t[size];
    }
    
    // Frees a string
    void strfree(char* str){
        if(str)
        {
            delete[] str;
        }
    }
    
    // Frees a wchar_t string
    void wstrfree(wchar_t* str){
        if(str)
        {
            delete[] str;
        }
    }
    
    // Converts a string to a wchar_t string
    wchar_t* str2wstr(const char* str){
        if(str)
        {
            size_t size = strlen(str);
            wchar_t* wstr = wstralloc(mbstowcs(0, str, size + 1) + 1);
            mbstowcs(wstr, str, size + 1);
            
            return wstr;
        }
        
        return 0;
    }
    
    // Converts a wchar_t string to a string
    char* wstr2str(const wchar_t* wstr){
        if(wstr)
        {
            size_t size = wcslen(wstr);
            char* str = stralloc(wcstombs(0, wstr, size + 1) + 1);
            wcstombs(str, wstr, size + 1);
            
            return str;
        }
        
        return 0;
    }
#endif

    double MyExtension_Init( void ){
        g_Initialised = true;
        return -1.0;
    }
    double MyExtension_Function( double _value ){
        if( !g_Initialised ) return -1.0;
        return _value*150.0;
    }
    
    double gmw_Init( void ){
        AkMemSettings memSettings;
        AK::MemoryMgr::GetDefaultSettings(memSettings);
        AKRESULT result = AK::MemoryMgr::Init( &memSettings );
        if ( result != AK_Success ){
            //assert( ! "Could not create the memory manager." );
            return result;
        }
        //
        // Create and initialize an instance of the default streaming manager. Note
        // that you can override the default streaming manager with your own.
        //
        
        AkStreamMgrSettings stmSettings;
        AK::StreamMgr::GetDefaultSettings( stmSettings );
        // Customize the Stream Manager settings here.
        if ( !AK::StreamMgr::Create( stmSettings ) ){
            //assert( ! "Could not create the Streaming Manager" );
            return  (double) AKRESULT::AK_Fail;
        }
        //
        // Create a streaming device with blocking low-level I/O handshaking.
        // Note that you can override the default low-level I/O module with your own.
        //
        
        AkDeviceSettings deviceSettings;
        AK::StreamMgr::GetDefaultDeviceSettings( deviceSettings );
        
        // Customize the streaming device settings here.
        // CAkFilePackageLowLevelIOBlocking::Init() creates a streaming device
        // in the Stream Manager, and registers itself as the File Location Resolver.
        result = g_lowLevelIO.Init( deviceSettings );
        if ( result != AK_Success ){
            //assert( ! "Could not create the streaming device and Low-Level I/O system" );
            return (double) result;
            
        }
        
        //
        // Create the Sound Engine
        // Using default initialization parameters
        //
        AkInitSettings initSettings;
        AkPlatformInitSettings platformInitSettings;
        AK::SoundEngine::GetDefaultInitSettings( initSettings );
        AK::SoundEngine::GetDefaultPlatformInitSettings( platformInitSettings );
        result = AK::SoundEngine::Init( &initSettings, &platformInitSettings );
        if ( result != AK_Success ){
            //assert( ! "Could not initialize the Sound Engine." );
            return (double) result;
        }
        
        
        //
        // Initialize the music engine
        // Using default initialization parameters
        //
        AkMusicSettings musicInit;
        AK::MusicEngine::GetDefaultInitSettings( musicInit );
        result = AK::MusicEngine::Init( &musicInit );
        if ( result != AK_Success ){
            //assert( ! "Could not initialize the Music Engine." );
            return (double) result;
            
        }
        
        //
        // Initialize Spatial Audio
        // Using default initialization parameters
        //
        AkSpatialAudioInitSettings settings; // The constructor fills AkSpatialAudioInitSettings with the recommended default settings.
        result = AK::SpatialAudio::Init( settings );
        if ( result != AK_Success ){
            //assert( ! "Could not initialize the Spatial Audio." );
            return (double) result;
            
        }
        
        
        
//#ifndef AK_OPTIMIZED
//        //
//        // Initialize communications (not in release build!)
//        //
//        AkCommSettings commSettings;
//        AK::Comm::GetDefaultInitSettings( commSettings );
//        result = AK::Comm::Init( commSettings );
//        if ( result != AK_Success ){
//            //assert( ! "Could not initialize communication." );
//            return (double) result;
//        }
//#endif // AK_OPTIMIZED
        
        return (double) result;
    }
    double gmw_Term( void ){
//#ifndef AK_OPTIMIZED
//            //
//            // Terminate Communication Services
//            //
//            AK::Comm::Term();
//#endif // AK_OPTIMIZED
        //
        // Terminate Spatial Audio
        //
        //AK::SpatialAudio::Term();
        
        //
        // Terminate the music engine
        //
        AK::MusicEngine::Term();
        
        //
        // Terminate the sound engine
        //
        AK::SoundEngine::Term();
        
            
        // Terminate the streaming device and streaming manager
        // CAkFilePackageLowLevelIOBlocking::Term() destroys its associated streaming device
        // that lives in the Stream Manager, and unregisters itself as the File Location Resolver.
            
        g_lowLevelIO.Term();
        
        if ( AK::IAkStreamMgr::Get() )AK::IAkStreamMgr::Get()->Destroy();
            
        // Terminate the Memory Manager
        AK::MemoryMgr::Term();
        
        return (double) AKRESULT::AK_Success;
    }
    double gmw_Render(void){
    // Process bank requests, events, positions, RTPC, etc.
    AKRESULT result = AK::SoundEngine::RenderAudio();
    return (double) result;
}

    double gmw_SetBasePath(char* _text){
        
#if defined(_WIN32)
        wlng_path = str2wstr(_text);
        AKRESULT result =  g_lowLevelIO.SetBasePath(wlng_path);
#elif defined(__APPLE__) || defined(__unix__)
        AKRESULT result =  g_lowLevelIO.SetBasePath(_text);
#endif
        
        return (double) result ;
    }
    double gmw_SetBaseLanguage(char* _text){
        
#if defined(_WIN32)
        wlng_language = str2wstr(_text);
        AKRESULT result = AK::StreamMgr::SetCurrentLanguage (wlng_language);
#elif defined(__APPLE__) || defined(__unix__)
        AKRESULT result = AK::StreamMgr::SetCurrentLanguage (_text);
#endif
        return (double) result ;
    }
    double gmw_LoadBank( char* _text ){
        
        
        AkBankID bankID; // Not used. These banks can be unloaded with their file name.
#if defined(_WIN32)
        wlng_bank = str2wstr(_text);
        AKRESULT result = AK::SoundEngine::LoadBank(wlng_bank, bankID );
#elif defined(__APPLE__) || defined(__unix__)
        AKRESULT result = AK::SoundEngine::LoadBank(_text, bankID );
#endif
        
        if (result != AK_Success) {
            return -10.0;
        }
        bancksLoaded.push_back(bankID);
        return (double) bankID ;
    }
    
    double gmw_RegisterGameObjet(double _gameObjId){
        AkGameObjectID obj  = static_cast<AkGameObjectID>(_gameObjId);
        return (double) AK::SoundEngine::RegisterGameObj(obj);
    }
    double gmw_UnregisterGameObj(double _gameObjId){
        AkGameObjectID obj  = static_cast<AkGameObjectID>(_gameObjId);
        return (double)AK::SoundEngine::UnregisterGameObj(obj);
    }
    
    double gmw_SetDefaultListeners(double _gameObjId){
        AkGameObjectID obj  = static_cast<AkGameObjectID>(_gameObjId);
        return (double) AK::SoundEngine::SetDefaultListeners(&obj, 1);
    }
    double gmw_SetListeners(double _listenId, double _gameObjId){
        const AkGameObjectID listen[1] = {static_cast<const AkGameObjectID>(_listenId)};
        AkGameObjectID obj = static_cast<AkGameObjectID>(_gameObjId);
//        static const int kNumLstnrsForEm = 1;
//        static const AkGameObjectID aLstnrsForEmitter[kNumLstnrsForEm] = { LISTENER };
//        AK::SoundEngine::SetListeners(EMITTER, aLstnrsForEmitter, kNumLstnrsForEm);
//        AK::SoundEngine::SetListeners(LISTENER, aLstnrsForEmitter, kNumLstnrsForEm);
//
//        // And register our listener as the one and only spatial audio listener.
//        AK::SpatialAudio::RegisterListener(LISTENER);
        return AK::SoundEngine::SetListeners(obj,listen,1);
    }
    double gmw_RegisterListener(double _gameObjId){
        AkGameObjectID obj  = static_cast<AkGameObjectID>(_gameObjId);
        return (double) AK::SpatialAudio::RegisterListener(obj);
    }
    
    double gmw_PostEvent(double _eventId,double _gameObjId){
       return (double) AK::SoundEngine::PostEvent( _eventId, _gameObjId);
    }
    double gmw_PostEventPosition(double _eventId,double _gameObjId){
        return (double) AK::SoundEngine::PostEvent( _eventId, _gameObjId,AK_EnableGetSourcePlayPosition, NULL,NULL);
    }
    double gmw_StopAll( void ){
        AK::SoundEngine::StopAll();
        return 0.;
    }
    double gmw_StopPlayingID(double in_playingID){
        AK::SoundEngine::StopPlayingID(in_playingID);
        return 0.;
    }
    double gmw_ExecuteActionOnPlayingID(double in_playingID,double _ActionOnEventType, double in_uTransitionDuration, double in_eFadeCurve){
        auto action = AK::SoundEngine::AkActionOnEventType_Stop;
        if (_ActionOnEventType == 1) action = AK::SoundEngine::AkActionOnEventType_Pause;
        if (_ActionOnEventType == 2) action = AK::SoundEngine::AkActionOnEventType_Resume;
        if (_ActionOnEventType == 3) action = AK::SoundEngine::AkActionOnEventType_Break;
        
        auto eFadeCurve = AkCurveInterpolation::AkCurveInterpolation_Linear;
        if (in_eFadeCurve == 2) eFadeCurve = AkCurveInterpolation::AkCurveInterpolation_Log3;
        if (in_eFadeCurve == 3) eFadeCurve = AkCurveInterpolation::AkCurveInterpolation_Sine;
        if (in_eFadeCurve == 4) eFadeCurve = AkCurveInterpolation::AkCurveInterpolation_Log1;
        if (in_eFadeCurve == 5) eFadeCurve = AkCurveInterpolation::AkCurveInterpolation_SCurve;
        if (in_eFadeCurve == 6) eFadeCurve = AkCurveInterpolation::AkCurveInterpolation_Exp1;
        AK::SoundEngine::ExecuteActionOnPlayingID(action, in_playingID, in_uTransitionDuration, eFadeCurve);
        return 0.0;
    }
    
    double gmw_GetSourcePlayPosition(double iPlayingID){
        AkTimeMs uPosition;
        AK::SoundEngine::GetSourcePlayPosition( iPlayingID, &uPosition );
        return (double) uPosition;
    }
    
    
    double gmw_SetPosition2D(double _gameObjId, double _x, double _y){
        AkGameObjectID obj  = static_cast<AkGameObjectID>(_gameObjId);
        AkSoundPosition soundPos;
        //soundPos.SetPosition(_x, 0.0, _y);
        AkVector position;
        position.X = _x;
        position.Y = 0;
        position.Z = _y;
        AkVector orientationFront;
        orientationFront.Z = 1;
        orientationFront.Y = orientationFront.X = 0;
        AkVector orientationTop;
        orientationTop.X = orientationTop.Z = 0;
        orientationTop.Y = 1;
        soundPos.Set(position, orientationFront, orientationTop);

        return (double) AK::SoundEngine::SetPosition( obj, soundPos );
        
    }
    double gmw_SetRTCPValue(double _RTCP,double _valure){
        //     AK::SoundEngine::SetRTPCValue( AK::GAME_PARAMETERS::RPM, (AkRtpcValue)sender->GetValue(), GAME_OBJECT_CAR );
        return (double) AK::SoundEngine::SetRTPCValue(_RTCP, _valure);
    }
    double gmw_SetSwitch(double _group, double _switch, double _gameObjId){
       return (double) AK::SoundEngine::SetSwitch( _group, _switch, _gameObjId);
    }
    
}
