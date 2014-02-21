Example Convergance tweak
=========================

Convergance offers support for other developers to extend or modify Convergance at runtime. This particular tweak changes the toggle page layout to a 4x4 grid, but is intended to be used as a base for modifying Convergance.

To access at runtime, simply call

*[(SpringBoard*)[UIApplication sharedApplication] converganceLs]*

which will return an object of type CVLockController*

