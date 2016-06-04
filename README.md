### FliteTTSPlugin
Unreal Engine Flite Text To Speech Plugin (Windows only)

## Presentation
Flite is a small fast run-time speech synthesis engine.  It is the
latest addition to the suite of free software synthesis tools
including University of Edinburgh's Festival Speech Synthesis System
and Carnegie Mellon University's FestVox project, tools, scripts and
documentation for building synthetic voices.  However, flite itself
does not require either of these systems to compile and run.

The current plugin version is built upon Flite 2.0.0 release.
Check this link for initial source code: http://www.festvox.org/flite

Unreal Engine Flite Text To Speech Plugin additions are:
- Flite source code ported to Visual Studio 2015
     Current status: 
	    Win32 Debug/Release works !
		x64: builds but does not works
- Unreal Engine plugin encapsulation
     Work in progress	 

## Status: not usable yet - work in progress
- It can be built in Win32 and in x64 but only works in Win32 (which is annoying for Unreal Engine)
- I have "lib not found" issues on some targets including Unreal Editor one
- It is only compatible for Windows at the moment (but as FLITE is cross plateform I expect it could be ported to other plateforms)

## Build instructions
- Microsoft Visual Studio 2015
- Unreal Engine 4.11 or higher

# Flite
1) Open FliteTTSPlugin\ThirdParty\flite\flite.sln
    Build solution (Win32/x64 Debug/Release)
2) Test builds by launching "test.exe" in FliteTTSPlugin\ThirdParty\flite\lib

# Unreal plugin
1) Create an Unreal Engine C++ project, for example "PluginTest"
2) Drop the FilteTTSPlugin directory into the Plugin directory (ex: PluginTest\Plugins\FliteTTSPlugin)
3) Open your project solution and build it (add the adequate flite lib path to your Unreal Engine project solution)
        

