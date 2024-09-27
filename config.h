// clang-format off

#include <X11/XF86keysym.h>

#define FONT "IosevkaNerdFontMono-Regular"

static const char *upvol[] = { "/home/petrside/.config/dwm_scripts/volume/vol_inc.sh", NULL};
static const char *downvol[] = { "/home/petrside/.config/dwm_scripts/volume/vol_dec.sh", NULL};
static const char *mutevol[] = { "/home/petrside/.config/dwm_scripts/volume/vol_toggle.sh", NULL};

static const char *mednextcmd[] = {"playerctl", "next", NULL};
static const char *medprevcmd[] = {"playerctl", "previous", NULL};
static const char *dimmer[] = {"brightnessctl", "set", "10%-", NULL};
static const char *brighter[] = {"brightnessctl", "set", "10%+", NULL};
static const char *medplaypausecmd[] = {"playerctl", "play-pause", NULL};

static const int topbar = 1;
static const int showbar = 1;
static const Rule rules[] = {0};
static const int showsystray = 1;
static const unsigned int snap = 10;
static const unsigned int borderpx = 3;
static const unsigned int systrayonleft = 0;
static const unsigned int systraypinning = 0;
static const int systraypinningfailfirst = 1;
static const unsigned int systrayspacing = 10;
static const char *fonts[] = {FONT":size=12"};
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#005577";
static const char *colors[][3] = {
	[SchemeNorm] = {col_gray3, col_gray1, col_gray2},
	[SchemeSel] = {col_gray4, col_cyan, col_cyan},
};

static const int nmaster = 1;
static const float mfact = 0.55;
static const int resizehints = 1;
static const int lockfullscreen = 1;

static const Layout layouts[] = {
  {"[]=", tile},
  {"><>", NULL},
  {"[M]", monocle },
  {"|M|", centeredmaster },
  {">M>", centeredfloatingmaster },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0";
static const char *termcmd[] = {"/usr/bin/alacritty", NULL};
static const char *dmenucmd[] = {"/home/petrside/.config/dwm_scripts/dmenu.sh", NULL};
static const char *screenshot[] = {"/home/petrside/.config/dwm_scripts/screenshot.sh", NULL};
static const char *power_menu[] = {"/home/petrside/.config/dwm_scripts/power_menu.sh", NULL};
static const char *screenshotsel[] = {"/home/petrside/.config/dwm_scripts/screenshotsel.sh", NULL};

static const Key keys[] = {
  {0, XK_Print, spawn, {.v = screenshot}},
  {ShiftMask, XK_Print, spawn, {.v = screenshotsel}},

  {0, XF86XK_AudioPlay, spawn, {.v = medplaypausecmd}},
  {0, XF86XK_AudioNext, spawn, {.v = mednextcmd}},
  {0, XF86XK_AudioPrev, spawn, {.v = medprevcmd}},
  {0, XF86XK_AudioLowerVolume, spawn, {.v = downvol}},
  {0, XF86XK_AudioMute, spawn, {.v = mutevol}},
  {0, XF86XK_AudioRaiseVolume, spawn, {.v = upvol}},
  {0, XF86XK_MonBrightnessDown, spawn, {.v = dimmer}},
  {0, XF86XK_MonBrightnessUp, spawn, {.v = brighter}},

  {MODKEY, XK_Tab, view, {0}},
  {MODKEY, XK_q, killclient, {0}},
  {MODKEY, XK_space, setlayout, {0}},
  {MODKEY, XK_j, focusstack, {.i = +1}},
  {MODKEY, XK_k, focusstack, {.i = -1}},
  {MODKEY, XK_f, togglefullscreen, {0}},
  {MODKEY, XK_d, spawn, {.v = dmenucmd}},
  {MODKEY, XK_Return, spawn, {.v = termcmd}},
  {MODKEY, XK_m, spawn, SHCMD("pavucontrol")},
  {MODKEY, XK_t, spawn, SHCMD("pcmanfm /home/petrside")},
  {MODKEY, XK_v, spawn, SHCMD("pcmanfm /home/petrside/ece")},

  {MODKEY | ShiftMask, XK_q, quit, {0}},
  {MODKEY | ShiftMask, XK_Return, zoom, {0}},
  {MODKEY | ShiftMask, XK_i, incnmaster, {.i = +1}},
  {MODKEY | ShiftMask, XK_d, incnmaster, {.i = -1}},
  {MODKEY | ShiftMask, XK_h, setmfact, {.f = -0.05}},
  {MODKEY | ShiftMask, XK_l, setmfact, {.f = +0.05}},
  {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
  {MODKEY | ShiftMask, XK_e, spawn, {.v = power_menu}},
  {MODKEY | ShiftMask, XK_t, setlayout, {.v = &layouts[0]}},
  {MODKEY | ShiftMask, XK_f, setlayout, {.v = &layouts[1]}},
  {MODKEY | ShiftMask, XK_w, setlayout, {.v = &layouts[2]}},
  {MODKEY | ShiftMask, XK_c, setlayout, {.v = &layouts[3]}},
  {MODKEY | ShiftMask, XK_x, setlayout, {.v = &layouts[4]}},
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
