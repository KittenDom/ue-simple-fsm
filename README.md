# UE5 Simplified FSM (Finite State Machine)

Simplified version of Finite State Machine for Unreal Engine 5 as a module...

## TOC
Table of Content

## Build
- Generate project files: `./GenerateProjectFiles.sh` (Linux) / `GenerateProjectFiles.bat` (Win)
- Build: `UnrealBuildTool MyPluginEditor Win64 Development`
- Package plugin: `RunUAT BuildPlugin -Plugin=MyPlugin.uplugin -Package=../Build/MyPlugin`

## Architecture
- Main Game Project `Finite/`

## Coding conventions
- UE5 naming: `FTC_Struct`, `UTC_Object`, `ATC_Actor`, `ITC_Interface`
- `UPROPERTY`/`UFUNCTION` macros required for all reflected members
- Use `TObjectPtr<>` instead of raw `UObject*` pointers