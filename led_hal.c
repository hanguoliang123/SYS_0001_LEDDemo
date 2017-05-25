
#define LOG_TAG "LedHal"

/* 1.实现一个名为HMI的hw_module_t结构体 */

/* 2.实现一个open函数，它会根据name返回led_device_t结构体 */

/* 3.实现led_device_t结构体 */

/* 4.参考文件：/home/ecarx/sdss/android-5.0.2/hardware/libhardware/modules/vibrator/vibrator.c */

#include <hardware/led_hal.h>
#include <hardware/hardware.h>

#include <cutils/log.h>
#include <utils/Log.h>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>


#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

static int fd;

static int led_open(struct led_device_t* dev)
{
	
	fd = open("/dev/leds",O_RDWR);
	
	ALOGI("led_open: %d",fd);
	
	if(fd >= 0)
		return 0;
	else
		return -1;
}

static int led_ctrl(struct led_device_t* dev,int which,int status)
{
	int ret = ioctl(fd,status,which);

	ALOGI("led_ctrl: %d ,%d ,%d",which,status,ret);

	return ret;
}

static int led_close(struct hw_device_t *device)
{
    close(fd);
    return 0;
}

static struct led_device_t led_dev =
{
    .common = 
    {
	.led_close = led_close,
    },
    .led_open  = led_open,
    .led_ctrl  = led_ctrl,
};

static int led_device_open(const hw_module_t* module, const char* id,hw_device_t** device) 
{
    *device = &led_dev;
    return 0;
}

static struct hw_module_methods_t led_module_methods = {
    .open = led_device_open,
};

struct hw_module_t HAL_MODULE_INFO_SYM = {
    .id = "led",
    .methods = &led_module_methods,
};







