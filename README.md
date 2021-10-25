# dwm - dynamic window manager

dwm is an extremely fast, small, and dynamic window manager for X.

## Requirements

In order to build dwm you need the Xlib header files.

## Installation

Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install

## Running dwm

Add the following line to your .xinitrc to start dwm using startx:

    exec dwm

## Shortcuts cheatsheet

- Mod + Shift + Enter
  - Terminal
- Mod + Shift + Q
  - Quit DWM
- Mod + Shift + S
  - Shutdown
- Mod + Shift + R
  - Reboot
- Mod + Shift + C
  - Quit the focused application
- Mod + Shift + J / Mod + Shift + K
  - Change focused window

## Configuration

The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
