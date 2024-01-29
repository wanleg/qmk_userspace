# Let's Split Flashing  
(More information at `qmk_firmware/layouts/community/ortho_3x10/wanleg/readme.md`)
## Flashing with QMK DFU
### Make the QMK DFU .hex
`make lets_split/rev2:wanleg:production dfu=qmk` 

### Burning EEPROM settings and Firmware
Navigate to the directory with your .hex file and the `eeprom-lefthand.eep` and `eeprom-righthand.eep` files in it.  
**Burn Left Side With QMK DFU and Firmware**  
`avrdude -b 19200 -c avrisp -p m32u4 -v -e -U lock:w:0x3F:m -U efuse:w:0xC3:m -U hfuse:w:0xD9:m -U lfuse:w:0x5E:m -U eeprom:w:eeprom-lefthand.eep -P comPORT -U flash:w:YOUR_production.hex:a`  

**Burn Right Side With QMK DFU and Firmware**  
`avrdude -b 19200 -c avrisp -p m32u4 -v -e -U lock:w:0x3F:m -U efuse:w:0xC3:m -U hfuse:w:0xD9:m -U lfuse:w:0x5E:m -U eeprom:w:eeprom-righthand.eep -P comPORT -U flash:w:YOUR_production.hex:a`  

Change `comPORT` to whatever port is used by the Arduino (e.g. `com11` in Windows or `/dev/ttyACM0` in Linux). Use Device Manager in Windows to find the port being used. Use `ls /dev/tty*` in Linux. Change `YOUR_production.hex` to whatever you've created in the previous step.

### Using QMK DFU  
Once QMK DFU is burned to your ProMicro, you can then flash subsequent hex files with
`make lets_split/rev2:<keymap>:dfu dfu=qmk`  
The `dfu=qmk` conditional will set `BOOTLOADER = qmk-dfu` instead of `BOOTLOADER = caterina`  
## Flashing with Caterina
In the event that setting EEPROM handedness (left/right) via QMK Toolbox is not working, you can use the following in a real Linux system (not WSL) to flash firmware & set handedness
### Directly on ProMicro
**Burn Left Side**  
`make lets_split/rev2:wanleg:avrdude-split-left`  
**Burn Right Side**  
`make lets_split/rev2:wanleg:avrdude-split-right`  
### Via Arduino as ISP 
1. Compile normally, e.g. `qmk compile -kb lets_split/rev2 -km wanleg`  
2. Copy the two `.eep` files from `qmk_firmware/quantum/split_common` to the same location as the `.hex` generated from step 1.
3. Use avrdude to write the handedness to EEPROM and flash firmware  
**Burn Left Side**  
`avrdude -b 19200 -c avrisp -p m32u4 -v -e -U lfuse:w:0xFF:m -U hfuse:w:0xD8:m -U efuse:w:0xC3:m -U eeprom:w:eeprom-lefthand.eep:a -P comPORT -U flash:w:lets_split_rev2_wanleg.hex:a -U lock:w:0x3F:m`  
**Burn Right Side**  
`avrdude -b 19200 -c avrisp -p m32u4 -v -e -U lfuse:w:0xFF:m -U hfuse:w:0xD8:m -U efuse:w:0xC3:m -U eeprom:w:eeprom-righthand.eep:a -P comPORT -U flash:w:lets_split_rev2_wanleg.hex:a -U lock:w:0x3F:m` 

# Let's Split LEDs  
In `qmk_firmware/keyboards/lets_split/rev2/rev2.c`, replace contents with 
```  
#include "lets_split.h"

void matrix_init_kb(void) {

    // // green led on
    // DDRD |= (1<<5);
    // PORTD &= ~(1<<5);

    // // orange led on
    // DDRB |= (1<<0);
    // PORTB &= ~(1<<0);
	
	//turn off LEDs on ProMicro
   DDRD &= ~(1<<5);
   PORTD &= ~(1<<5);

   DDRB &= ~(1<<0);
   PORTB &= ~(1<<0);

	matrix_init_user();
};
```  
to turn off LEDs
