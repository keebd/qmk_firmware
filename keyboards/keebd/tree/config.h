/*
Copyright 2021 KEEBD

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6264 // bd = "KEEBD"
#define PRODUCT_ID      0x1705
#define DEVICE_VER      0x0301
#define MANUFACTURER    KEEBD
#define PRODUCT         Tree

/* Key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 1

/* Key matrix pins */
#define MATRIX_ROW_PINS { D0, D4 }
#define MATRIX_COL_PINS { C6 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
