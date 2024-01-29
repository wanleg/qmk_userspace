TAP_DANCE_ENABLE = yes
ifeq ($(strip $(KEYBOARD)), xiudi/xd75)
#or
#ifeq (,$(findstring xd75,$(KEYBOARD)))
COMBO_ENABLE = yes
SWAP_HANDS_ENABLE = no
LTO_ENABLE = yes
endif

ifeq ($(strip $(KEYBOARD)), 40percentclub/5x5)
#or
#ifeq (,$(findstring 40percentclub/5x5,$(KEYBOARD)))
SWAP_HANDS_ENABLE = yes
endif
