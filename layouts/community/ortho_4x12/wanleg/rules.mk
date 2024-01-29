AUDIO_ENABLE = no
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = yes

ifeq ($(strip $(KEYBOARD)), lets_split/rev2)
	SWAP_HANDS_ENABLE = yes
endif

ifeq ($(strip $(KEYBOARD)), planck/rev6)
	AUDIO_ENABLE = yes
	RGBLIGHT_ENABLE = no
endif

#disable RGB on version 1 of jj40 keyboard (does not exist)
ifeq ($(strip $(KEYBOARD)), jj40)
	RGBLIGHT_ENABLE = no
endif

ifeq ($(strip $(KEYBOARD)), 40percentclub/nori)
	NKRO_ENABLE = no
	BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality on B7 by default
	RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
endif
