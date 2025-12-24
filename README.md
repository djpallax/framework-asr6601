# framework-asr6601 (WIP)

This repository provides the **ASR6601 / RA-08 "Tremo" framework** files used by my custom PlatformIO platform (`platform-asr6601`).

> Status: **Work in progress**. Expect breaking changes.

## What is this?
- A structured copy of the vendor/framework sources (CMSIS, system startup, peripheral drivers, linker scripts, etc.)
- Intended to be consumed by `platform-asr6601` via `asr_framework_path` for now.

In the future, this may become a proper PlatformIO package instead of a path-based framework.

## Credits / Upstream
This work is based on the original Ai-Thinker RA-08 sources:
- Ai-Thinker-LoRaWAN-Ra-08

Some files were adapted or reorganized to work in a PlatformIO flow.

## Licensing notice
I am not fully sure about the licensing status of all upstream sources.
For that reason, **this repo may not include all original files** or may change structure in the future.

If you are the copyright holder and want changes, attribution, or removal,
please contact me and I will respond quickly.

## Usage (current approach)
In your PlatformIO project:

```ini
[env:ra08]
platform = https://github.com/djpallax/platform-asr6601.git
board = ra08
framework = tremo

; Framework path (temporary)
; Option A (recommended): environment variable
; asr_framework_path = ${sysenv.ASR_FRAMEWORK_PATH}
; Option B: absolute path
asr_framework_path = /absolute/path/to/framework-asr6601

; Upload settings (set your port!)
upload_port = /dev/ttyUSB0
upload_speed = 921600

; Serial monitor
monitor_port  = ${this.upload_port}
monitor_speed = 115200
monitor_rts = 0
monitor_dtr = 0

; Optional features
use_printf = no
debug_uart = UART0
````

## Roadmap

* Make the framework installable as a PlatformIO package (no local path)
* Improve documentation and examples
* Add CI sanity checks

## Disclaimer

This project is provided **as-is**, with no warranty.
Use at your own risk.
