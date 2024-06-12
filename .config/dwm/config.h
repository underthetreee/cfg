/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=9.5" };
static const char dmenufont[]       = "monospace:size=9.5";
static const char col_font[]        = "#f5f5f5";
static const char col_font2[]       = "#888888";
static const char col_bg[]          = "#222222";
static const char col_fg[]          = "#444444";
static const char *colors[][3]      = {
	/*               fg         bg       border   */
	[SchemeNorm] = { col_font,  col_bg,  col_bg },
	[SchemeSel]  = { col_font2, col_bg,  col_fg },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* class               instance    title       tags mask     isfloating   monitor */
	{ "pavucontrol",       NULL,       NULL,       0,            True,       -1 },
};

/* layout(s) */
static const float mfact     = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ KeyPress,   MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ KeyPress,   MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ KeyPress,   MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ KeyPress,   MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_bg, "-nf", col_font, "-sb", col_bg, "-sf", col_font2, NULL };
static const char *termcmd[]  = { "wezterm", NULL };

static Key keys[] = {
	/* type       modifier                      key        function        argument */
	{ KeyPress,   MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ KeyPress,   MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ KeyPress,   MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ KeyPress,   MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ KeyPress,   MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ KeyPress,   MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ KeyPress,   MODKEY,                       XK_space,  zoom,           {0} },
	{ KeyPress,   MODKEY,                       XK_q,      killclient,     {0} },
	{ KeyPress,   MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ KeyPress,   MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	TAGKEYS(                                    XK_1,                      0)
	TAGKEYS(                                    XK_2,                      1)
	TAGKEYS(                                    XK_3,                      2)
	TAGKEYS(                                    XK_4,                      3)
	TAGKEYS(                                    XK_5,                      4)
	TAGKEYS(                                    XK_6,                      5)
	TAGKEYS(                                    XK_7,                      6)
	TAGKEYS(                                    XK_8,                      7)
	TAGKEYS(                                    XK_9,                      8)
	{ KeyRelease, 0,                            XK_Print,  spawn,          CMD("scrot '/tmp/%F_%T_$wx$h.png' -s -e 'xclip -selection clipboard -target image/png -i $f'") },
	{ KeyPress,   MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
