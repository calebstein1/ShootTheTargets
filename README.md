# Shoot The Targets (C Edition)

This is an experiment in porting my other Shoot The Targets game into C using raylib.
The input handler is not nearly as nice as the C# version, but other than that it's basically the same (entirely different under the hood though).
Right now it's just crosshairs you can move around and randomly generated targets, you can't actually shoot anything yet.
On a game controller, movement with the d-pad works, but thumbstick movements aren't supported yet.

## Building

You'll need to install raylib, then it's just a `make` and that should do it for you.
