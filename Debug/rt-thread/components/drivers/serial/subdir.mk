################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/components/drivers/serial/serial.c 

OBJS += \
./rt-thread/components/drivers/serial/serial.o 

C_DEPS += \
./rt-thread/components/drivers/serial/serial.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/components/drivers/serial/%.o: ../rt-thread/components/drivers/serial/%.c
	arm-none-eabi-gcc -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\applications\lvgl" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\applications" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\board" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\libraries\n9h30\Driver\Include" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\libraries\n9h30\UsbHostLib\inc" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\libraries\n9h30\rtt_port" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\libraries\nu_packages\ADC_TOUCH" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\libraries\nu_packages\AudioCodec" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\libraries\nu_packages\NuUtils\inc" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\libraries\nu_packages\TPC" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\demos\benchmark\assets" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\demos\benchmark" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\demos\keypad_encoder" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\demos\music\assets" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\demos\music" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\demos\stress\assets" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\demos\stress" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\demos\widgets\assets" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\demos\widgets" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\demos" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\env_support\rt-thread" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\core" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\draw\nxp_pxp" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\draw\nxp_vglite" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\draw\sdl" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\draw\stm32_dma2d" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\draw\sw" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\draw" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\layouts\flex" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\layouts\grid" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\layouts" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\libs\bmp" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\libs\ffmpeg" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\libs\freetype" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\libs\fsdrv" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\libs\gif" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\libs\png" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\libs\qrcode" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\libs\rlottie" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\libs\sjpg" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\libs" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\others\gridnav" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\others\monkey" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\others\snapshot" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\others" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\themes\basic" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\themes\default" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\themes\mono" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\themes" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\animimg" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\calendar" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\chart" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\colorwheel" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\imgbtn" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\keyboard" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\led" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\list" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\menu" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\meter" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\msgbox" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\span" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\spinbox" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\spinner" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\tabview" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\tileview" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets\win" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra\widgets" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\extra" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\font" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\gpu" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\hal" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\misc" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src\widgets" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\LVGL-v8.2.0\src" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\packages\ramdisk-latest\inc" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\dfs\filesystems\devfs" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\dfs\filesystems\elmfat" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\dfs\include" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\drivers\audio" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\drivers\include" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\drivers\spi\sfud\inc" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\drivers\spi" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\drivers\touch" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\drivers\usb\usbdevice" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\drivers\usb\usbhost\class" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\drivers\usb\usbhost\core" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\drivers\usb\usbhost" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\fal\inc" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\finsh" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\libc\compilers\common" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\libc\compilers\newlib" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\libc\posix\io\poll" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\libc\posix\io\stdio" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\libc\posix\ipc" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\net\lwip\lwip-2.0.3\src\include\netif" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\net\lwip\lwip-2.0.3\src\include" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\net\lwip\port" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\net\netdev\include" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\net\sal\impl" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\net\sal\include\dfs_net" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\net\sal\include\socket\sys_socket" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\net\sal\include\socket" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\net\sal\include" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\components\utilities\utest" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\include" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\libcpu\arm\arm926" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rt-thread\libcpu\arm\common" -I"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\applications\demo" -include"F:\board\NuMaker-emWin-N9H30\program\rt-thread-n9h30-prj\rt-thread-n9h30-prj\rtconfig_preinc.h" -std=gnu11 -mcpu=arm926ej-s -O2 -g -gdwarf-2 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

