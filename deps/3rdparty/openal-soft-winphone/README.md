This is an OpenAL-soft shared library project for Windows Store App/Windows Phone 8.0+.

Features:
 * back-end for Xaudio2 (default)
 * back-end for Windows Audio Session API (WASAPI)

This project is forked from normal OpenAL-soft (which doesn't support windows store/phone platform).
 
To build, open Visual Studio solution in winrt.vs2012 folder. 
 
Pre-built binaries are also provided in winrt.vs2012/bin/$(Platform)/Release folder.

Important Notes:
 - Windows Store App: 
	* alcOpenDevice() is not allowed to be called on UI thread. 
	* All OpenAL function are not allowed to be called before UI window is ready/visible.
	* The above notes are applied for WASAPI backend only for now. Currently, Xaudio2 is default backend which doesn't cause such problems.
