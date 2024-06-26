# ScottoAlp

![ScottoAlp](https://i.imgur.com/XKpYcMgh.jpeg)

A 35 or 43-key ortholinear keyboard with a 3u spacebar and is compatible with both MX or Alps. Case files available [here](https://github.com/joe-scotto/scottokeebs).

*   Keyboard Maintainer: [Joe Scotto](https://github.com/joe-scotto)
*   Hardware Supported: ATmega32U4
*   Hardware Availability: [Amazon](https://amazon.com)

Make example for this keyboard (after setting up your build environment):

    make handwired/jscotto/scottoalp:default

Flashing example for this keyboard:

    make handwired/jscotto/scottoalp:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,1) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available