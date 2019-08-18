#ifndef KEYNAMES_H
#define KEYNAMES_H



// https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/plain/include/uapi/linux/input-event-codes.h
// awk '$2~/^KEY/&&$1=="#define"{n=strtonum($3);a[n]=$2;d[n]=$0;} END{for(i=0;i<600;i++){printf "/*%3d*/ \"%s\", // %s\n", i, a[i]?a[i]:i, d[i];}}'
static const char * keynames[] = {
/*  0*/ "CNT", // #define KEY_CNT			(KEY_MAX+1)
/*  1*/ "ESC", // #define KEY_ESC			1
/*  2*/ "1", // #define KEY_1			2
/*  3*/ "2", // #define KEY_2			3
/*  4*/ "3", // #define KEY_3			4
/*  5*/ "4", // #define KEY_4			5
/*  6*/ "5", // #define KEY_5			6
/*  7*/ "6", // #define KEY_6			7
/*  8*/ "7", // #define KEY_7			8
/*  9*/ "8", // #define KEY_8			9
/* 10*/ "9", // #define KEY_9			10
/* 11*/ "0", // #define KEY_0			11
/* 12*/ "MINUS", // #define KEY_MINUS		12
/* 13*/ "EQUAL", // #define KEY_EQUAL		13
/* 14*/ "BACKSPACE", // #define KEY_BACKSPACE		14
/* 15*/ "TAB", // #define KEY_TAB			15
/* 16*/ "Q", // #define KEY_Q			16
/* 17*/ "W", // #define KEY_W			17
/* 18*/ "E", // #define KEY_E			18
/* 19*/ "R", // #define KEY_R			19
/* 20*/ "T", // #define KEY_T			20
/* 21*/ "Y", // #define KEY_Y			21
/* 22*/ "U", // #define KEY_U			22
/* 23*/ "I", // #define KEY_I			23
/* 24*/ "O", // #define KEY_O			24
/* 25*/ "P", // #define KEY_P			25
/* 26*/ "LEFTBRACE", // #define KEY_LEFTBRACE		26
/* 27*/ "RIGHTBRACE", // #define KEY_RIGHTBRACE		27
/* 28*/ "ENTER", // #define KEY_ENTER		28
/* 29*/ "LEFTCTRL", // #define KEY_LEFTCTRL		29
/* 30*/ "A", // #define KEY_A			30
/* 31*/ "S", // #define KEY_S			31
/* 32*/ "D", // #define KEY_D			32
/* 33*/ "F", // #define KEY_F			33
/* 34*/ "G", // #define KEY_G			34
/* 35*/ "H", // #define KEY_H			35
/* 36*/ "J", // #define KEY_J			36
/* 37*/ "K", // #define KEY_K			37
/* 38*/ "L", // #define KEY_L			38
/* 39*/ "SEMICOLON", // #define KEY_SEMICOLON		39
/* 40*/ "APOSTROPHE", // #define KEY_APOSTROPHE		40
/* 41*/ "GRAVE", // #define KEY_GRAVE		41
/* 42*/ "LEFTSHIFT", // #define KEY_LEFTSHIFT		42
/* 43*/ "BACKSLASH", // #define KEY_BACKSLASH		43
/* 44*/ "Z", // #define KEY_Z			44
/* 45*/ "X", // #define KEY_X			45
/* 46*/ "C", // #define KEY_C			46
/* 47*/ "V", // #define KEY_V			47
/* 48*/ "B", // #define KEY_B			48
/* 49*/ "N", // #define KEY_N			49
/* 50*/ "M", // #define KEY_M			50
/* 51*/ "COMMA", // #define KEY_COMMA		51
/* 52*/ "DOT", // #define KEY_DOT			52
/* 53*/ "SLASH", // #define KEY_SLASH		53
/* 54*/ "RIGHTSHIFT", // #define KEY_RIGHTSHIFT		54
/* 55*/ "KPASTERISK", // #define KEY_KPASTERISK		55
/* 56*/ "LEFTALT", // #define KEY_LEFTALT		56
/* 57*/ "SPACE", // #define KEY_SPACE		57
/* 58*/ "CAPSLOCK", // #define KEY_CAPSLOCK		58
/* 59*/ "F1", // #define KEY_F1			59
/* 60*/ "F2", // #define KEY_F2			60
/* 61*/ "F3", // #define KEY_F3			61
/* 62*/ "F4", // #define KEY_F4			62
/* 63*/ "F5", // #define KEY_F5			63
/* 64*/ "F6", // #define KEY_F6			64
/* 65*/ "F7", // #define KEY_F7			65
/* 66*/ "F8", // #define KEY_F8			66
/* 67*/ "F9", // #define KEY_F9			67
/* 68*/ "F10", // #define KEY_F10			68
/* 69*/ "NUMLOCK", // #define KEY_NUMLOCK		69
/* 70*/ "SCROLLLOCK", // #define KEY_SCROLLLOCK		70
/* 71*/ "KP7", // #define KEY_KP7			71
/* 72*/ "KP8", // #define KEY_KP8			72
/* 73*/ "KP9", // #define KEY_KP9			73
/* 74*/ "KPMINUS", // #define KEY_KPMINUS		74
/* 75*/ "KP4", // #define KEY_KP4			75
/* 76*/ "KP5", // #define KEY_KP5			76
/* 77*/ "KP6", // #define KEY_KP6			77
/* 78*/ "KPPLUS", // #define KEY_KPPLUS		78
/* 79*/ "KP1", // #define KEY_KP1			79
/* 80*/ "KP2", // #define KEY_KP2			80
/* 81*/ "KP3", // #define KEY_KP3			81
/* 82*/ "KP0", // #define KEY_KP0			82
/* 83*/ "KPDOT", // #define KEY_KPDOT		83
/* 84*/ "84", // 
/* 85*/ "ZENKAKUHANKAKU", // #define KEY_ZENKAKUHANKAKU	85
/* 86*/ "102ND", // #define KEY_102ND		86
/* 87*/ "F11", // #define KEY_F11			87
/* 88*/ "F12", // #define KEY_F12			88
/* 89*/ "RO", // #define KEY_RO			89
/* 90*/ "KATAKANA", // #define KEY_KATAKANA		90
/* 91*/ "HIRAGANA", // #define KEY_HIRAGANA		91
/* 92*/ "HENKAN", // #define KEY_HENKAN		92
/* 93*/ "KATAKANAHIRAGANA", // #define KEY_KATAKANAHIRAGANA	93
/* 94*/ "MUHENKAN", // #define KEY_MUHENKAN		94
/* 95*/ "KPJPCOMMA", // #define KEY_KPJPCOMMA		95
/* 96*/ "KPENTER", // #define KEY_KPENTER		96
/* 97*/ "RIGHTCTRL", // #define KEY_RIGHTCTRL		97
/* 98*/ "KPSLASH", // #define KEY_KPSLASH		98
/* 99*/ "SYSRQ", // #define KEY_SYSRQ		99
/*100*/ "RIGHTALT", // #define KEY_RIGHTALT		100
/*101*/ "LINEFEED", // #define KEY_LINEFEED		101
/*102*/ "HOME", // #define KEY_HOME		102
/*103*/ "UP", // #define KEY_UP			103
/*104*/ "PAGEUP", // #define KEY_PAGEUP		104
/*105*/ "LEFT", // #define KEY_LEFT		105
/*106*/ "RIGHT", // #define KEY_RIGHT		106
/*107*/ "END", // #define KEY_END			107
/*108*/ "DOWN", // #define KEY_DOWN		108
/*109*/ "PAGEDOWN", // #define KEY_PAGEDOWN		109
/*110*/ "INSERT", // #define KEY_INSERT		110
/*111*/ "DELETE", // #define KEY_DELETE		111
/*112*/ "MACRO", // #define KEY_MACRO		112
/*113*/ "MUTE", // #define KEY_MUTE		113
/*114*/ "VOLUMEDOWN", // #define KEY_VOLUMEDOWN		114
/*115*/ "VOLUMEUP", // #define KEY_VOLUMEUP		115
/*116*/ "POWER", // #define KEY_POWER		116	/* SC System Power Down */
/*117*/ "KPEQUAL", // #define KEY_KPEQUAL		117
/*118*/ "KPPLUSMINUS", // #define KEY_KPPLUSMINUS		118
/*119*/ "PAUSE", // #define KEY_PAUSE		119
/*120*/ "SCALE", // #define KEY_SCALE		120	/* AL Compiz Scale (Expose) */
/*121*/ "KPCOMMA", // #define KEY_KPCOMMA		121
/*122*/ "HANGEUL", // #define KEY_HANGEUL		122
/*123*/ "HANJA", // #define KEY_HANJA		123
/*124*/ "YEN", // #define KEY_YEN			124
/*125*/ "LEFTMETA", // #define KEY_LEFTMETA		125
/*126*/ "RIGHTMETA", // #define KEY_RIGHTMETA		126
/*127*/ "COMPOSE", // #define KEY_COMPOSE		127
/*128*/ "STOP", // #define KEY_STOP		128	/* AC Stop */
/*129*/ "AGAIN", // #define KEY_AGAIN		129
/*130*/ "PROPS", // #define KEY_PROPS		130	/* AC Properties */
/*131*/ "UNDO", // #define KEY_UNDO		131	/* AC Undo */
/*132*/ "FRONT", // #define KEY_FRONT		132
/*133*/ "COPY", // #define KEY_COPY		133	/* AC Copy */
/*134*/ "OPEN", // #define KEY_OPEN		134	/* AC Open */
/*135*/ "PASTE", // #define KEY_PASTE		135	/* AC Paste */
/*136*/ "FIND", // #define KEY_FIND		136	/* AC Search */
/*137*/ "CUT", // #define KEY_CUT			137	/* AC Cut */
/*138*/ "HELP", // #define KEY_HELP		138	/* AL Integrated Help Center */
/*139*/ "MENU", // #define KEY_MENU		139	/* Menu (show menu) */
/*140*/ "CALC", // #define KEY_CALC		140	/* AL Calculator */
/*141*/ "SETUP", // #define KEY_SETUP		141
/*142*/ "SLEEP", // #define KEY_SLEEP		142	/* SC System Sleep */
/*143*/ "WAKEUP", // #define KEY_WAKEUP		143	/* System Wake Up */
/*144*/ "FILE", // #define KEY_FILE		144	/* AL Local Machine Browser */
/*145*/ "SENDFILE", // #define KEY_SENDFILE		145
/*146*/ "DELETEFILE", // #define KEY_DELETEFILE		146
/*147*/ "XFER", // #define KEY_XFER		147
/*148*/ "PROG1", // #define KEY_PROG1		148
/*149*/ "PROG2", // #define KEY_PROG2		149
/*150*/ "WWW", // #define KEY_WWW			150	/* AL Internet Browser */
/*151*/ "MSDOS", // #define KEY_MSDOS		151
/*152*/ "COFFEE", // #define KEY_COFFEE		152	/* AL Terminal Lock/Screensaver */
/*153*/ "ROTATE_DISPLAY", // #define KEY_ROTATE_DISPLAY	153	/* Display orientation for e.g. tablets */
/*154*/ "CYCLEWINDOWS", // #define KEY_CYCLEWINDOWS	154
/*155*/ "MAIL", // #define KEY_MAIL		155
/*156*/ "BOOKMARKS", // #define KEY_BOOKMARKS		156	/* AC Bookmarks */
/*157*/ "COMPUTER", // #define KEY_COMPUTER		157
/*158*/ "BACK", // #define KEY_BACK		158	/* AC Back */
/*159*/ "FORWARD", // #define KEY_FORWARD		159	/* AC Forward */
/*160*/ "CLOSECD", // #define KEY_CLOSECD		160
/*161*/ "EJECTCD", // #define KEY_EJECTCD		161
/*162*/ "EJECTCLOSECD", // #define KEY_EJECTCLOSECD	162
/*163*/ "NEXTSONG", // #define KEY_NEXTSONG		163
/*164*/ "PLAYPAUSE", // #define KEY_PLAYPAUSE		164
/*165*/ "PREVIOUSSONG", // #define KEY_PREVIOUSSONG	165
/*166*/ "STOPCD", // #define KEY_STOPCD		166
/*167*/ "RECORD", // #define KEY_RECORD		167
/*168*/ "REWIND", // #define KEY_REWIND		168
/*169*/ "PHONE", // #define KEY_PHONE		169	/* Media Select Telephone */
/*170*/ "ISO", // #define KEY_ISO			170
/*171*/ "CONFIG", // #define KEY_CONFIG		171	/* AL Consumer Control Configuration */
/*172*/ "HOMEPAGE", // #define KEY_HOMEPAGE		172	/* AC Home */
/*173*/ "REFRESH", // #define KEY_REFRESH		173	/* AC Refresh */
/*174*/ "EXIT", // #define KEY_EXIT		174	/* AC Exit */
/*175*/ "MOVE", // #define KEY_MOVE		175
/*176*/ "EDIT", // #define KEY_EDIT		176
/*177*/ "SCROLLUP", // #define KEY_SCROLLUP		177
/*178*/ "SCROLLDOWN", // #define KEY_SCROLLDOWN		178
/*179*/ "KPLEFTPAREN", // #define KEY_KPLEFTPAREN		179
/*180*/ "KPRIGHTPAREN", // #define KEY_KPRIGHTPAREN	180
/*181*/ "NEW", // #define KEY_NEW			181	/* AC New */
/*182*/ "REDO", // #define KEY_REDO		182	/* AC Redo/Repeat */
/*183*/ "F13", // #define KEY_F13			183
/*184*/ "F14", // #define KEY_F14			184
/*185*/ "F15", // #define KEY_F15			185
/*186*/ "F16", // #define KEY_F16			186
/*187*/ "F17", // #define KEY_F17			187
/*188*/ "F18", // #define KEY_F18			188
/*189*/ "F19", // #define KEY_F19			189
/*190*/ "F20", // #define KEY_F20			190
/*191*/ "F21", // #define KEY_F21			191
/*192*/ "F22", // #define KEY_F22			192
/*193*/ "F23", // #define KEY_F23			193
/*194*/ "F24", // #define KEY_F24			194
/*195*/ "195", // 
/*196*/ "196", // 
/*197*/ "197", // 
/*198*/ "198", // 
/*199*/ "199", // 
/*200*/ "PLAYCD", // #define KEY_PLAYCD		200
/*201*/ "PAUSECD", // #define KEY_PAUSECD		201
/*202*/ "PROG3", // #define KEY_PROG3		202
/*203*/ "PROG4", // #define KEY_PROG4		203
/*204*/ "DASHBOARD", // #define KEY_DASHBOARD		204	/* AL Dashboard */
/*205*/ "SUSPEND", // #define KEY_SUSPEND		205
/*206*/ "CLOSE", // #define KEY_CLOSE		206	/* AC Close */
/*207*/ "PLAY", // #define KEY_PLAY		207
/*208*/ "FASTFORWARD", // #define KEY_FASTFORWARD		208
/*209*/ "BASSBOOST", // #define KEY_BASSBOOST		209
/*210*/ "PRINT", // #define KEY_PRINT		210	/* AC Print */
/*211*/ "HP", // #define KEY_HP			211
/*212*/ "CAMERA", // #define KEY_CAMERA		212
/*213*/ "SOUND", // #define KEY_SOUND		213
/*214*/ "QUESTION", // #define KEY_QUESTION		214
/*215*/ "EMAIL", // #define KEY_EMAIL		215
/*216*/ "CHAT", // #define KEY_CHAT		216
/*217*/ "SEARCH", // #define KEY_SEARCH		217
/*218*/ "CONNECT", // #define KEY_CONNECT		218
/*219*/ "FINANCE", // #define KEY_FINANCE		219	/* AL Checkbook/Finance */
/*220*/ "SPORT", // #define KEY_SPORT		220
/*221*/ "SHOP", // #define KEY_SHOP		221
/*222*/ "ALTERASE", // #define KEY_ALTERASE		222
/*223*/ "CANCEL", // #define KEY_CANCEL		223	/* AC Cancel */
/*224*/ "BRIGHTNESSDOWN", // #define KEY_BRIGHTNESSDOWN	224
/*225*/ "BRIGHTNESSUP", // #define KEY_BRIGHTNESSUP	225
/*226*/ "MEDIA", // #define KEY_MEDIA		226
/*227*/ "SWITCHVIDEOMODE", // #define KEY_SWITCHVIDEOMODE	227	/* Cycle between available video
/*228*/ "KBDILLUMTOGGLE", // #define KEY_KBDILLUMTOGGLE	228
/*229*/ "KBDILLUMDOWN", // #define KEY_KBDILLUMDOWN	229
/*230*/ "KBDILLUMUP", // #define KEY_KBDILLUMUP		230
/*231*/ "SEND", // #define KEY_SEND		231	/* AC Send */
/*232*/ "REPLY", // #define KEY_REPLY		232	/* AC Reply */
/*233*/ "FORWARDMAIL", // #define KEY_FORWARDMAIL		233	/* AC Forward Msg */
/*234*/ "SAVE", // #define KEY_SAVE		234	/* AC Save */
/*235*/ "DOCUMENTS", // #define KEY_DOCUMENTS		235
/*236*/ "BATTERY", // #define KEY_BATTERY		236
/*237*/ "BLUETOOTH", // #define KEY_BLUETOOTH		237
/*238*/ "WLAN", // #define KEY_WLAN		238
/*239*/ "UWB", // #define KEY_UWB			239
/*240*/ "UNKNOWN", // #define KEY_UNKNOWN		240
/*241*/ "VIDEO_NEXT", // #define KEY_VIDEO_NEXT		241	/* drive next video source */
/*242*/ "VIDEO_PREV", // #define KEY_VIDEO_PREV		242	/* drive previous video source */
/*243*/ "BRIGHTNESS_CYCLE", // #define KEY_BRIGHTNESS_CYCLE	243	/* brightness up, after max is min */
/*244*/ "BRIGHTNESS_AUTO", // #define KEY_BRIGHTNESS_AUTO	244	/* Set Auto Brightness: manual
/*245*/ "DISPLAY_OFF", // #define KEY_DISPLAY_OFF		245	/* display device to off state */
/*246*/ "WWAN", // #define KEY_WWAN		246	/* Wireless WAN (LTE, UMTS, GSM, etc.) */
/*247*/ "RFKILL", // #define KEY_RFKILL		247	/* Key that controls all radios */
/*248*/ "MICMUTE", // #define KEY_MICMUTE		248	/* Mute / unmute the microphone */
/*249*/ "249", // 
/*250*/ "250", // 
/*251*/ "251", // 
/*252*/ "252", // 
/*253*/ "253", // 
/*254*/ "254", // 
/*255*/ "255", // 
/*256*/ "256", // 
/*257*/ "257", // 
/*258*/ "258", // 
/*259*/ "259", // 
/*260*/ "260", // 
/*261*/ "261", // 
/*262*/ "262", // 
/*263*/ "263", // 
/*264*/ "264", // 
/*265*/ "265", // 
/*266*/ "266", // 
/*267*/ "267", // 
/*268*/ "268", // 
/*269*/ "269", // 
/*270*/ "270", // 
/*271*/ "271", // 
/*272*/ "272", // 
/*273*/ "273", // 
/*274*/ "274", // 
/*275*/ "275", // 
/*276*/ "276", // 
/*277*/ "277", // 
/*278*/ "278", // 
/*279*/ "279", // 
/*280*/ "280", // 
/*281*/ "281", // 
/*282*/ "282", // 
/*283*/ "283", // 
/*284*/ "284", // 
/*285*/ "285", // 
/*286*/ "286", // 
/*287*/ "287", // 
/*288*/ "288", // 
/*289*/ "289", // 
/*290*/ "290", // 
/*291*/ "291", // 
/*292*/ "292", // 
/*293*/ "293", // 
/*294*/ "294", // 
/*295*/ "295", // 
/*296*/ "296", // 
/*297*/ "297", // 
/*298*/ "298", // 
/*299*/ "299", // 
/*300*/ "300", // 
/*301*/ "301", // 
/*302*/ "302", // 
/*303*/ "303", // 
/*304*/ "304", // 
/*305*/ "305", // 
/*306*/ "306", // 
/*307*/ "307", // 
/*308*/ "308", // 
/*309*/ "309", // 
/*310*/ "310", // 
/*311*/ "311", // 
/*312*/ "312", // 
/*313*/ "313", // 
/*314*/ "314", // 
/*315*/ "315", // 
/*316*/ "316", // 
/*317*/ "317", // 
/*318*/ "318", // 
/*319*/ "319", // 
/*320*/ "320", // 
/*321*/ "321", // 
/*322*/ "322", // 
/*323*/ "323", // 
/*324*/ "324", // 
/*325*/ "325", // 
/*326*/ "326", // 
/*327*/ "327", // 
/*328*/ "328", // 
/*329*/ "329", // 
/*330*/ "330", // 
/*331*/ "331", // 
/*332*/ "332", // 
/*333*/ "333", // 
/*334*/ "334", // 
/*335*/ "335", // 
/*336*/ "336", // 
/*337*/ "337", // 
/*338*/ "338", // 
/*339*/ "339", // 
/*340*/ "340", // 
/*341*/ "341", // 
/*342*/ "342", // 
/*343*/ "343", // 
/*344*/ "344", // 
/*345*/ "345", // 
/*346*/ "346", // 
/*347*/ "347", // 
/*348*/ "348", // 
/*349*/ "349", // 
/*350*/ "350", // 
/*351*/ "351", // 
/*352*/ "OK", // #define KEY_OK			0x160
/*353*/ "SELECT", // #define KEY_SELECT		0x161
/*354*/ "GOTO", // #define KEY_GOTO		0x162
/*355*/ "CLEAR", // #define KEY_CLEAR		0x163
/*356*/ "POWER2", // #define KEY_POWER2		0x164
/*357*/ "OPTION", // #define KEY_OPTION		0x165
/*358*/ "INFO", // #define KEY_INFO		0x166	/* AL OEM Features/Tips/Tutorial */
/*359*/ "TIME", // #define KEY_TIME		0x167
/*360*/ "VENDOR", // #define KEY_VENDOR		0x168
/*361*/ "ARCHIVE", // #define KEY_ARCHIVE		0x169
/*362*/ "PROGRAM", // #define KEY_PROGRAM		0x16a	/* Media Select Program Guide */
/*363*/ "CHANNEL", // #define KEY_CHANNEL		0x16b
/*364*/ "FAVORITES", // #define KEY_FAVORITES		0x16c
/*365*/ "EPG", // #define KEY_EPG			0x16d
/*366*/ "PVR", // #define KEY_PVR			0x16e	/* Media Select Home */
/*367*/ "MHP", // #define KEY_MHP			0x16f
/*368*/ "LANGUAGE", // #define KEY_LANGUAGE		0x170
/*369*/ "TITLE", // #define KEY_TITLE		0x171
/*370*/ "SUBTITLE", // #define KEY_SUBTITLE		0x172
/*371*/ "ANGLE", // #define KEY_ANGLE		0x173
/*372*/ "ZOOM", // #define KEY_ZOOM		0x174
/*373*/ "MODE", // #define KEY_MODE		0x175
/*374*/ "KEYBOARD", // #define KEY_KEYBOARD		0x176
/*375*/ "SCREEN", // #define KEY_SCREEN		0x177
/*376*/ "PC", // #define KEY_PC			0x178	/* Media Select Computer */
/*377*/ "TV", // #define KEY_TV			0x179	/* Media Select TV */
/*378*/ "TV2", // #define KEY_TV2			0x17a	/* Media Select Cable */
/*379*/ "VCR", // #define KEY_VCR			0x17b	/* Media Select VCR */
/*380*/ "VCR2", // #define KEY_VCR2		0x17c	/* VCR Plus */
/*381*/ "SAT", // #define KEY_SAT			0x17d	/* Media Select Satellite */
/*382*/ "SAT2", // #define KEY_SAT2		0x17e
/*383*/ "CD", // #define KEY_CD			0x17f	/* Media Select CD */
/*384*/ "TAPE", // #define KEY_TAPE		0x180	/* Media Select Tape */
/*385*/ "RADIO", // #define KEY_RADIO		0x181
/*386*/ "TUNER", // #define KEY_TUNER		0x182	/* Media Select Tuner */
/*387*/ "PLAYER", // #define KEY_PLAYER		0x183
/*388*/ "TEXT", // #define KEY_TEXT		0x184
/*389*/ "DVD", // #define KEY_DVD			0x185	/* Media Select DVD */
/*390*/ "AUX", // #define KEY_AUX			0x186
/*391*/ "MP3", // #define KEY_MP3			0x187
/*392*/ "AUDIO", // #define KEY_AUDIO		0x188	/* AL Audio Browser */
/*393*/ "VIDEO", // #define KEY_VIDEO		0x189	/* AL Movie Browser */
/*394*/ "DIRECTORY", // #define KEY_DIRECTORY		0x18a
/*395*/ "LIST", // #define KEY_LIST		0x18b
/*396*/ "MEMO", // #define KEY_MEMO		0x18c	/* Media Select Messages */
/*397*/ "CALENDAR", // #define KEY_CALENDAR		0x18d
/*398*/ "RED", // #define KEY_RED			0x18e
/*399*/ "GREEN", // #define KEY_GREEN		0x18f
/*400*/ "YELLOW", // #define KEY_YELLOW		0x190
/*401*/ "BLUE", // #define KEY_BLUE		0x191
/*402*/ "CHANNELUP", // #define KEY_CHANNELUP		0x192	/* Channel Increment */
/*403*/ "CHANNELDOWN", // #define KEY_CHANNELDOWN		0x193	/* Channel Decrement */
/*404*/ "FIRST", // #define KEY_FIRST		0x194
/*405*/ "LAST", // #define KEY_LAST		0x195	/* Recall Last */
/*406*/ "AB", // #define KEY_AB			0x196
/*407*/ "NEXT", // #define KEY_NEXT		0x197
/*408*/ "RESTART", // #define KEY_RESTART		0x198
/*409*/ "SLOW", // #define KEY_SLOW		0x199
/*410*/ "SHUFFLE", // #define KEY_SHUFFLE		0x19a
/*411*/ "BREAK", // #define KEY_BREAK		0x19b
/*412*/ "PREVIOUS", // #define KEY_PREVIOUS		0x19c
/*413*/ "DIGITS", // #define KEY_DIGITS		0x19d
/*414*/ "TEEN", // #define KEY_TEEN		0x19e
/*415*/ "TWEN", // #define KEY_TWEN		0x19f
/*416*/ "VIDEOPHONE", // #define KEY_VIDEOPHONE		0x1a0	/* Media Select Video Phone */
/*417*/ "GAMES", // #define KEY_GAMES		0x1a1	/* Media Select Games */
/*418*/ "ZOOMIN", // #define KEY_ZOOMIN		0x1a2	/* AC Zoom In */
/*419*/ "ZOOMOUT", // #define KEY_ZOOMOUT		0x1a3	/* AC Zoom Out */
/*420*/ "ZOOMRESET", // #define KEY_ZOOMRESET		0x1a4	/* AC Zoom */
/*421*/ "WORDPROCESSOR", // #define KEY_WORDPROCESSOR	0x1a5	/* AL Word Processor */
/*422*/ "EDITOR", // #define KEY_EDITOR		0x1a6	/* AL Text Editor */
/*423*/ "SPREADSHEET", // #define KEY_SPREADSHEET		0x1a7	/* AL Spreadsheet */
/*424*/ "GRAPHICSEDITOR", // #define KEY_GRAPHICSEDITOR	0x1a8	/* AL Graphics Editor */
/*425*/ "PRESENTATION", // #define KEY_PRESENTATION	0x1a9	/* AL Presentation App */
/*426*/ "DATABASE", // #define KEY_DATABASE		0x1aa	/* AL Database App */
/*427*/ "NEWS", // #define KEY_NEWS		0x1ab	/* AL Newsreader */
/*428*/ "VOICEMAIL", // #define KEY_VOICEMAIL		0x1ac	/* AL Voicemail */
/*429*/ "ADDRESSBOOK", // #define KEY_ADDRESSBOOK		0x1ad	/* AL Contacts/Address Book */
/*430*/ "MESSENGER", // #define KEY_MESSENGER		0x1ae	/* AL Instant Messaging */
/*431*/ "DISPLAYTOGGLE", // #define KEY_DISPLAYTOGGLE	0x1af	/* Turn display (LCD) on and off */
/*432*/ "SPELLCHECK", // #define KEY_SPELLCHECK		0x1b0   /* AL Spell Check */
/*433*/ "LOGOFF", // #define KEY_LOGOFF		0x1b1   /* AL Logoff */
/*434*/ "DOLLAR", // #define KEY_DOLLAR		0x1b2
/*435*/ "EURO", // #define KEY_EURO		0x1b3
/*436*/ "FRAMEBACK", // #define KEY_FRAMEBACK		0x1b4	/* Consumer - transport controls */
/*437*/ "FRAMEFORWARD", // #define KEY_FRAMEFORWARD	0x1b5
/*438*/ "CONTEXT_MENU", // #define KEY_CONTEXT_MENU	0x1b6	/* GenDesc - system context menu */
/*439*/ "MEDIA_REPEAT", // #define KEY_MEDIA_REPEAT	0x1b7	/* Consumer - transport control */
/*440*/ "10CHANNELSUP", // #define KEY_10CHANNELSUP	0x1b8	/* 10 channels up (10+) */
/*441*/ "10CHANNELSDOWN", // #define KEY_10CHANNELSDOWN	0x1b9	/* 10 channels down (10-) */
/*442*/ "IMAGES", // #define KEY_IMAGES		0x1ba	/* AL Image Browser */
/*443*/ "443", // 
/*444*/ "444", // 
/*445*/ "445", // 
/*446*/ "446", // 
/*447*/ "447", // 
/*448*/ "DEL_EOL", // #define KEY_DEL_EOL		0x1c0
/*449*/ "DEL_EOS", // #define KEY_DEL_EOS		0x1c1
/*450*/ "INS_LINE", // #define KEY_INS_LINE		0x1c2
/*451*/ "DEL_LINE", // #define KEY_DEL_LINE		0x1c3
/*452*/ "452", // 
/*453*/ "453", // 
/*454*/ "454", // 
/*455*/ "455", // 
/*456*/ "456", // 
/*457*/ "457", // 
/*458*/ "458", // 
/*459*/ "459", // 
/*460*/ "460", // 
/*461*/ "461", // 
/*462*/ "462", // 
/*463*/ "463", // 
/*464*/ "FN", // #define KEY_FN			0x1d0
/*465*/ "FN_ESC", // #define KEY_FN_ESC		0x1d1
/*466*/ "FN_F1", // #define KEY_FN_F1		0x1d2
/*467*/ "FN_F2", // #define KEY_FN_F2		0x1d3
/*468*/ "FN_F3", // #define KEY_FN_F3		0x1d4
/*469*/ "FN_F4", // #define KEY_FN_F4		0x1d5
/*470*/ "FN_F5", // #define KEY_FN_F5		0x1d6
/*471*/ "FN_F6", // #define KEY_FN_F6		0x1d7
/*472*/ "FN_F7", // #define KEY_FN_F7		0x1d8
/*473*/ "FN_F8", // #define KEY_FN_F8		0x1d9
/*474*/ "FN_F9", // #define KEY_FN_F9		0x1da
/*475*/ "FN_F10", // #define KEY_FN_F10		0x1db
/*476*/ "FN_F11", // #define KEY_FN_F11		0x1dc
/*477*/ "FN_F12", // #define KEY_FN_F12		0x1dd
/*478*/ "FN_1", // #define KEY_FN_1		0x1de
/*479*/ "FN_2", // #define KEY_FN_2		0x1df
/*480*/ "FN_D", // #define KEY_FN_D		0x1e0
/*481*/ "FN_E", // #define KEY_FN_E		0x1e1
/*482*/ "FN_F", // #define KEY_FN_F		0x1e2
/*483*/ "FN_S", // #define KEY_FN_S		0x1e3
/*484*/ "FN_B", // #define KEY_FN_B		0x1e4
/*485*/ "485", // 
/*486*/ "486", // 
/*487*/ "487", // 
/*488*/ "488", // 
/*489*/ "489", // 
/*490*/ "490", // 
/*491*/ "491", // 
/*492*/ "492", // 
/*493*/ "493", // 
/*494*/ "494", // 
/*495*/ "495", // 
/*496*/ "496", // 
/*497*/ "BRL_DOT1", // #define KEY_BRL_DOT1		0x1f1
/*498*/ "BRL_DOT2", // #define KEY_BRL_DOT2		0x1f2
/*499*/ "BRL_DOT3", // #define KEY_BRL_DOT3		0x1f3
/*500*/ "BRL_DOT4", // #define KEY_BRL_DOT4		0x1f4
/*501*/ "BRL_DOT5", // #define KEY_BRL_DOT5		0x1f5
/*502*/ "BRL_DOT6", // #define KEY_BRL_DOT6		0x1f6
/*503*/ "BRL_DOT7", // #define KEY_BRL_DOT7		0x1f7
/*504*/ "BRL_DOT8", // #define KEY_BRL_DOT8		0x1f8
/*505*/ "BRL_DOT9", // #define KEY_BRL_DOT9		0x1f9
/*506*/ "BRL_DOT10", // #define KEY_BRL_DOT10		0x1fa
/*507*/ "507", // 
/*508*/ "508", // 
/*509*/ "509", // 
/*510*/ "510", // 
/*511*/ "511", // 
/*512*/ "NUMERIC_0", // #define KEY_NUMERIC_0		0x200	/* used by phones, remote controls, */
/*513*/ "NUMERIC_1", // #define KEY_NUMERIC_1		0x201	/* and other keypads */
/*514*/ "NUMERIC_2", // #define KEY_NUMERIC_2		0x202
/*515*/ "NUMERIC_3", // #define KEY_NUMERIC_3		0x203
/*516*/ "NUMERIC_4", // #define KEY_NUMERIC_4		0x204
/*517*/ "NUMERIC_5", // #define KEY_NUMERIC_5		0x205
/*518*/ "NUMERIC_6", // #define KEY_NUMERIC_6		0x206
/*519*/ "NUMERIC_7", // #define KEY_NUMERIC_7		0x207
/*520*/ "NUMERIC_8", // #define KEY_NUMERIC_8		0x208
/*521*/ "NUMERIC_9", // #define KEY_NUMERIC_9		0x209
/*522*/ "NUMERIC_STAR", // #define KEY_NUMERIC_STAR	0x20a
/*523*/ "NUMERIC_POUND", // #define KEY_NUMERIC_POUND	0x20b
/*524*/ "NUMERIC_A", // #define KEY_NUMERIC_A		0x20c	/* Phone key A - HUT Telephony 0xb9 */
/*525*/ "NUMERIC_B", // #define KEY_NUMERIC_B		0x20d
/*526*/ "NUMERIC_C", // #define KEY_NUMERIC_C		0x20e
/*527*/ "NUMERIC_D", // #define KEY_NUMERIC_D		0x20f
/*528*/ "CAMERA_FOCUS", // #define KEY_CAMERA_FOCUS	0x210
/*529*/ "WPS_BUTTON", // #define KEY_WPS_BUTTON		0x211	/* WiFi Protected Setup key */
/*530*/ "TOUCHPAD_TOGGLE", // #define KEY_TOUCHPAD_TOGGLE	0x212	/* Request switch touchpad on or off */
/*531*/ "TOUCHPAD_ON", // #define KEY_TOUCHPAD_ON		0x213
/*532*/ "TOUCHPAD_OFF", // #define KEY_TOUCHPAD_OFF	0x214
/*533*/ "CAMERA_ZOOMIN", // #define KEY_CAMERA_ZOOMIN	0x215
/*534*/ "CAMERA_ZOOMOUT", // #define KEY_CAMERA_ZOOMOUT	0x216
/*535*/ "CAMERA_UP", // #define KEY_CAMERA_UP		0x217
/*536*/ "CAMERA_DOWN", // #define KEY_CAMERA_DOWN		0x218
/*537*/ "CAMERA_LEFT", // #define KEY_CAMERA_LEFT		0x219
/*538*/ "CAMERA_RIGHT", // #define KEY_CAMERA_RIGHT	0x21a
/*539*/ "ATTENDANT_ON", // #define KEY_ATTENDANT_ON	0x21b
/*540*/ "ATTENDANT_OFF", // #define KEY_ATTENDANT_OFF	0x21c
/*541*/ "ATTENDANT_TOGGLE", // #define KEY_ATTENDANT_TOGGLE	0x21d	/* Attendant call on or off */
/*542*/ "LIGHTS_TOGGLE", // #define KEY_LIGHTS_TOGGLE	0x21e	/* Reading light on or off */
/*543*/ "543", // 
/*544*/ "544", // 
/*545*/ "545", // 
/*546*/ "546", // 
/*547*/ "547", // 
/*548*/ "548", // 
/*549*/ "549", // 
/*550*/ "550", // 
/*551*/ "551", // 
/*552*/ "552", // 
/*553*/ "553", // 
/*554*/ "554", // 
/*555*/ "555", // 
/*556*/ "556", // 
/*557*/ "557", // 
/*558*/ "558", // 
/*559*/ "559", // 
/*560*/ "ALS_TOGGLE", // #define KEY_ALS_TOGGLE		0x230	/* Ambient light sensor */
/*561*/ "ROTATE_LOCK_TOGGLE", // #define KEY_ROTATE_LOCK_TOGGLE	0x231	/* Display rotation lock */
/*562*/ "562", // 
/*563*/ "563", // 
/*564*/ "564", // 
/*565*/ "565", // 
/*566*/ "566", // 
/*567*/ "567", // 
/*568*/ "568", // 
/*569*/ "569", // 
/*570*/ "570", // 
/*571*/ "571", // 
/*572*/ "572", // 
/*573*/ "573", // 
/*574*/ "574", // 
/*575*/ "575", // 
/*576*/ "BUTTONCONFIG", // #define KEY_BUTTONCONFIG		0x240	/* AL Button Configuration */
/*577*/ "TASKMANAGER", // #define KEY_TASKMANAGER		0x241	/* AL Task/Project Manager */
/*578*/ "JOURNAL", // #define KEY_JOURNAL		0x242	/* AL Log/Journal/Timecard */
/*579*/ "CONTROLPANEL", // #define KEY_CONTROLPANEL		0x243	/* AL Control Panel */
/*580*/ "APPSELECT", // #define KEY_APPSELECT		0x244	/* AL Select Task/Application */
/*581*/ "SCREENSAVER", // #define KEY_SCREENSAVER		0x245	/* AL Screen Saver */
/*582*/ "VOICECOMMAND", // #define KEY_VOICECOMMAND		0x246	/* Listening Voice Command */
/*583*/ "ASSISTANT", // #define KEY_ASSISTANT		0x247	/* AL Context-aware desktop assistant */
/*584*/ "584", // 
/*585*/ "585", // 
/*586*/ "586", // 
/*587*/ "587", // 
/*588*/ "588", // 
/*589*/ "589", // 
/*590*/ "590", // 
/*591*/ "591", // 
/*592*/ "BRIGHTNESS_MIN", // #define KEY_BRIGHTNESS_MIN		0x250	/* Set Brightness to Minimum */
/*593*/ "BRIGHTNESS_MAX", // #define KEY_BRIGHTNESS_MAX		0x251	/* Set Brightness to Maximum */
/*594*/ "594", // 
/*595*/ "595", // 
/*596*/ "596", // 
/*597*/ "597", // 
/*598*/ "598", // 
/*599*/ "599", // 
};

int getkey(const char * keyname)
{
  for(int i = 0; i < 600; i++) if(!strcasecmp(keyname, keynames[i])) return i;
  return -1;
}


#endif /* KEYNAMES_H */
