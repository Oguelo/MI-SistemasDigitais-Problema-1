#include "ADXL345.h"
#include "address_map_arm.h"
#include "physical.h"
#include <stdio.h>

static unsigned int * i2c0_base_ptr, * sysmgr_base_ptr;
static void * i2c0base_virtual, * sysmgrbase_virtual;
static int fd_i2c0base = -1, fd_sysmgr = -1;

int main(void){

    uint8_t devid;
    int16_t mg_per_lsb = 4;
    int16_t XYZ[3];

    //Configure MUX to connect I2C0 controller to ADXL345
	if ((fd_sysmgr = open_physical(fd_sysmgr)) == -1) {
		return(-1);
	}

	if ((sysmgrbase_virtual = map_physical(fd_sysmgr, SYSMGR_BASE, SYSMGR_SPAN)) == NULL) {
		return(-1);
	}

	sysmgr_base_ptr = (unsigned int *) sysmgrbase_virtual;

    printf("%p\n", sysmgr_base_ptr);
	printf("Starting mux_init()\n");

	mux_init();
	printf("Finished mux_init()\n");


    if ((fd_i2c0base = open_physical(fd_i2c0base)) == -1) {
		return(-1);
	}

	if ((i2c0base_virtual = map_physical(fd_i2c0base, I2C0_BASE, I2C0_SPAN)) == NULL) {
		return(-1);
	}

	i2c0_base_ptr = (unsigned int *) i2c0base_virtual;
	printf("Starting I2C0_Init()\n");

	I2C0_Init();
	printf("Getting ID\n");

	ADXL345_IdRead(&devid);
	printf("%#x\n", devid);
    
    // Configure Pin Muxing
    //Pinmux_Config();
    
    // Initialize I2C0 Controller
    I2C0_Init();
    
    // 0xE5 is read from DEVID(0x00) if I2C is functioning correctly
    ADXL345_REG_READ(0x00, &devid);
    
    // Correct Device ID
    if (devid == 0xE5){
        // Initialize accelerometer chip
        ADXL345_Init();
        
        while(1){
            if (ADXL345_WasActivityUpdated()){
                ADXL345_XYZ_Read(XYZ);
                printf("X=%d mg, Y=%d mg, Z=%d mg\n", XYZ[0]*mg_per_lsb, XYZ[1]*mg_per_lsb, XYZ[2]*mg_per_lsb);
            }
        }
    } else {
        printf("Incorrect device ID\n");
    }
    
    return 0;
}