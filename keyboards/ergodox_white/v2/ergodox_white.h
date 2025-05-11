// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT(                                                          \
    L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
    L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
    L20,L21,L22,L23,L24,L25,L26,           R20,R21,R22,R23,R24,R25,R26,  \
        L30,L31,L32,L33,L34,L35,           R30,R31,R32,R33,R34,R35,      \
            L40,L41,L42,L43,L44,           R40,R41,R42,R43,R44,          \
                            L36,L46,   R46,R36,                          \
                                L45,   R45,                              \
                        L52,L51,L50,   R50,R51,R52 )                     \
                                            \
   /* matrix positions */                   \
{                                       \
       { L06,L05,L04,L03,L02,L01,L00 },       \
       { L16,L15,L14,L13,L12,L11,L10 },       \
       { L26,L25,L24,L23,L22,L21,L20 },       \
       { L36,L35,L34,L33,L32,L31,L30 },    \
       { L46,L52,L44,L43,L42,L41,L40 }, \
       { L45,L51,L50,KC_NO,KC_NO,KC_NO,KC_NO }, \
                                              \
       { R00, R01, R02, R03, R04, R05, R06 },       \
       { R10, R11, R12, R13, R14, R15, R16 },       \
       { R20, R21, R22, R23, R24, R25, R26 },       \
       { R36, R30, R31, R32, R33, R34, R35 },     \
       { R46, R52, R40, R41, R42, R43, R44 },   \
       { R45, R51, R50, KC_NO,KC_NO,KC_NO,KC_NO}      \
   }
