/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const int showbar = 1;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    0; /* 1 will force focus on the fullscreen window */

static const Layout layout = {"[M]", monocle};

/* key definitions */
#define MODKEY Mod4Mask

/* commands */
static const char *termcmd[] = {"/usr/bin/xterm", NULL};
static const char *rebootcmd[] = {"/usr/bin/reboot", NULL};
static const char *shutdowncmd[] = {"/usr/bin/shutdown", "now", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = termcmd}},
    {MODKEY | ShiftMask, XK_r, spawn, {.v = rebootcmd}},
    {MODKEY | ShiftMask, XK_s, spawn, {.v = shutdowncmd}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY | ShiftMask, XK_c, killclient, {0}},
    {MODKEY | ShiftMask, XK_q, quit, {0}},
};