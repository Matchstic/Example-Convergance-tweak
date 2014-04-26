Example Convergance tweak
=========================

Convergance offers support for other developers to extend or modify itself at runtime. This particular tweak changes the toggle page layout to a 4x4 grid, but is intended to be used as a base for modifying Convergance.

To access Convergance at runtime, simply call

*[objc_getClass("CVAPI") mainWindow]*

which will return an object of type CVLockController.

Headers can be either be found in /Headers, or can be class-dump'ed from the latest dylib.
