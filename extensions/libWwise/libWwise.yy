{
  "optionsFile": "options.json",
  "options": [],
  "exportToGame": true,
  "supportedTargets": -1,
  "extensionVersion": "0.0.1",
  "packageId": "",
  "productId": "",
  "author": "",
  "date": "2021-01-21T18:05:20.687592+11:00",
  "license": "",
  "description": "",
  "helpfile": "",
  "iosProps": false,
  "tvosProps": false,
  "androidProps": false,
  "installdir": "",
  "files": [
    {"filename":"liblibWwise.dylib","origname":"","init":"","final":"","kind":1,"uncompress":false,"functions":[
        {"externalName":"MyExtension_Init","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[],"resourceVersion":"1.0","name":"libWwise_init","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"MyExtension_Function","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
          ],"resourceVersion":"1.0","name":"libWwise_Function","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_Init","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[],"resourceVersion":"1.0","name":"gmw_Init","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_Render","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[],"resourceVersion":"1.0","name":"gmw_Render","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_Term","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[],"resourceVersion":"1.0","name":"gmw_Term","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_SetBasePath","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[
            1,
          ],"resourceVersion":"1.0","name":"gmw_SetBasePath","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_SetBaseLanguage","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[
            1,
          ],"resourceVersion":"1.0","name":"gmw_SetBaseLanguage","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_LoadBank","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[
            1,
          ],"resourceVersion":"1.0","name":"gmw_LoadBank","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_RegisterGameObjet","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
          ],"resourceVersion":"1.0","name":"gmw_RegisterGameObjet","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_UnregisterGameObj","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
          ],"resourceVersion":"1.0","name":"gmw_UnregisterGameObj","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_PostEvent","kind":1,"help":"gmw_PostEvent(double _eventId,double _gameObjId)","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
            2,
          ],"resourceVersion":"1.0","name":"gmw_PostEvent","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_SetDefaultListeners","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
          ],"resourceVersion":"1.0","name":"gmw_SetDefaultListeners","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_SetPosition","kind":1,"help":"","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
          ],"resourceVersion":"1.0","name":"gmw_SetPosition","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_SetRTCPValue","kind":1,"help":"gmw_SetRTCPValue(_RTCP, _valure)","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
            2,
          ],"resourceVersion":"1.0","name":"gmw_SetRTCPValue","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_SetSwitch","kind":1,"help":"gmw_SetSwitch(double _group, double _switch, double _gameObjId)","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
            2,
            2,
          ],"resourceVersion":"1.0","name":"gmw_SetSwitch","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_SetPosition2D","kind":1,"help":"gmw_SetPosition2D(double _gameObjId, double _x, double _y)","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
            2,
            2,
          ],"resourceVersion":"1.0","name":"gmw_SetPosition2D","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_RegisterListener","kind":1,"help":"gmw_RegisterListener(_gameObjId)","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
          ],"resourceVersion":"1.0","name":"gmw_RegisterListener","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_SetListeners","kind":1,"help":"gmw_SetListeners(listenId, gameObjId)","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
            2,
          ],"resourceVersion":"1.0","name":"gmw_SetListeners","tags":[],"resourceType":"GMExtensionFunction",},
        {"externalName":"gmw_GetSourcePlayPosition","kind":1,"help":"gmw_GetSourcePlayPosition(iPlayingID)","hidden":false,"returnType":2,"argCount":0,"args":[
            2,
          ],"resourceVersion":"1.0","name":"gmw_GetSourcePlayPosition","tags":[],"resourceType":"GMExtensionFunction",},
      ],"constants":[],"ProxyFiles":[
        {"TargetMask":6,"resourceVersion":"1.0","name":"gm_wwise_plugin.dll","tags":[],"resourceType":"GMProxyFile",},
      ],"copyToTargets":66,"order":[
        {"name":"libWwise_init","path":"extensions/libWwise/libWwise.yy",},
        {"name":"libWwise_Function","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_Init","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_Render","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_Term","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_SetBasePath","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_SetBaseLanguage","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_LoadBank","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_RegisterGameObjet","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_UnregisterGameObj","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_PostEvent","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_SetDefaultListeners","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_SetPosition","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_SetRTCPValue","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_SetSwitch","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_SetPosition2D","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_RegisterListener","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_SetListeners","path":"extensions/libWwise/libWwise.yy",},
        {"name":"gmw_GetSourcePlayPosition","path":"extensions/libWwise/libWwise.yy",},
      ],"resourceVersion":"1.0","name":"","tags":[],"resourceType":"GMExtensionFile",},
  ],
  "classname": "",
  "tvosclassname": null,
  "tvosdelegatename": null,
  "iosdelegatename": "",
  "androidclassname": "",
  "sourcedir": "",
  "androidsourcedir": "",
  "macsourcedir": "",
  "maccompilerflags": "",
  "tvosmaccompilerflags": "",
  "maclinkerflags": "",
  "tvosmaclinkerflags": "",
  "iosplistinject": null,
  "tvosplistinject": null,
  "androidinject": null,
  "androidmanifestinject": null,
  "androidactivityinject": null,
  "gradleinject": null,
  "iosSystemFrameworkEntries": [],
  "tvosSystemFrameworkEntries": [],
  "iosThirdPartyFrameworkEntries": [],
  "tvosThirdPartyFrameworkEntries": [],
  "IncludedResources": [],
  "androidPermissions": [],
  "copyToTargets": 66,
  "iosCocoaPods": "",
  "tvosCocoaPods": "",
  "iosCocoaPodDependencies": "",
  "tvosCocoaPodDependencies": "",
  "parent": {
    "name": "Extensions",
    "path": "folders/Extensions.yy",
  },
  "resourceVersion": "1.2",
  "name": "libWwise",
  "tags": [],
  "resourceType": "GMExtension",
}