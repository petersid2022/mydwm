/* See LICENSE file for copyright and license details. */
// clang-format off

#include <X11/XF86keysym.h>

static const char *upvol[] = { "/home/petrside/.config/dwm_scripts/volume/vol_inc.sh", NULL};
static const char *downvol[] = { "/home/petrside/.config/dwm_scripts/volume/vol_dec.sh", NULL};
static const char *mutevol[] = { "/home/petrside/.config/dwm_scripts/volume/vol_toggle.sh", NULL};

static const char *brighter[] = {"brightnessctl", "set", "10%+", NULL};
static const char *dimmer[] = {"brightnessctl", "set", "10%-", NULL};
static const char *medplaypausecmd[] = {"playerctl", "play-pause", NULL};
static const char *mednextcmd[] = {"playerctl", "next", NULL};
static const char *medprevcmd[] = {"playerctl", "previous", NULL};

/* appearance */
static const int topbar = 1;            /* 0 means bottom bar */
static const int showbar = 1;           /* 0 means no bar */
static const int showsystray = 1;        /* 0 means no systray */
static const unsigned int snap = 10;    /* snap pixel */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const unsigned int systrayspacing = 20;   /* systray spacing */
static const char *fonts[] = {"monospace:size=13"};
static const char dmenufont[] = "monospace:size=10";

static const char norm_fg[] = "#f2e4df";
static const char norm_bg[] = "#0f1011";
static const char norm_border[] = "#a99f9c";

static const char sel_fg[] = "#f2e4df";
static const char sel_bg[] = "#E02406";
static const char sel_border[] = "#f2e4df";

static const char urg_fg[] = "#f2e4df";
static const char urg_bg[] = "#CF0D03";
static const char urg_border[] = "#CF0D03";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};

/* tagging */
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const Rule rules[] = {0};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints = 1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
  {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},                   \
  {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"/home/petrside/.config/dwm_scripts/dmenu.sh", NULL};
static const char *screenshot[] = {"/home/petrside/.config/dwm_scripts/screenshot.sh", NULL};
static const char *screenshotsel[] = {"/home/petrside/.config/dwm_scripts/screenshotsel.sh", NULL};
static const char *power_menu[] = {"/home/petrside/.config/dwm_scripts/power_menu.sh", NULL};
static const char *termcmd[] = {"/usr/bin/alacritty", NULL};

static const Key keys[] = {
    {0, XF86XK_AudioPlay, spawn, {.v = medplaypausecmd}},
    {0, XF86XK_AudioNext, spawn, {.v = mednextcmd}},
    {0, XF86XK_AudioPrev, spawn, {.v = medprevcmd}},
    {0, XK_Print, spawn, {.v = screenshot}},
    {ShiftMask, XK_Print, spawn, {.v = screenshotsel}},
    {MODKEY, XK_t, spawn, SHCMD("pcmanfm /home/petrside")},
    {MODKEY, XK_v, spawn, SHCMD("pcmanfm /home/petrside/ece")},
    {MODKEY, XK_m, spawn, SHCMD("pavucontrol")},
    {0, XF86XK_AudioLowerVolume, spawn, {.v = downvol}},
    {0, XF86XK_AudioMute, spawn, {.v = mutevol}},
    {0, XF86XK_AudioRaiseVolume, spawn, {.v = upvol}},
    {0, XF86XK_MonBrightnessDown, spawn, {.v = dimmer}},
    {0, XF86XK_MonBrightnessUp, spawn, {.v = brighter}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_d, spawn, {.v = dmenucmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_f, togglefullscreen, {0} },
    {MODKEY | ShiftMask, XK_e, spawn, {.v = power_menu}},
    {MODKEY | ShiftMask, XK_i, incnmaster, {.i = +1}},
    {MODKEY | ShiftMask, XK_d, incnmaster, {.i = -1}},
    {MODKEY | ShiftMask, XK_h, setmfact, {.f = -0.05}},
    {MODKEY | ShiftMask, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_q, quit, {0}},
    {MODKEY | ShiftMask, XK_Return, zoom, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY | ShiftMask, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY | ShiftMask, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY | ShiftMask, XK_w, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY, XK_q, killclient, {0}},
    TAGKEYS(XK_1, 0)
    TAGKEYS(XK_2, 1)
    TAGKEYS(XK_3, 2)
    TAGKEYS(XK_4, 3)
    TAGKEYS(XK_5, 4)
    TAGKEYS(XK_6, 5)
    TAGKEYS(XK_7, 6)
    TAGKEYS(XK_8, 7)
    TAGKEYS(XK_9, 8)
};

static const Button buttons[] = {
  {ClkTagBar, 0, Button1, view, {0}},
  {ClkClientWin, MODKEY, Button1, movemouse, {0}},
  {ClkClientWin, MODKEY | ShiftMask, Button1, resizemouse, {0}},
};
