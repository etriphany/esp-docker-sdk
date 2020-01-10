#ifndef _USER_CONFIG_H
#define _USER_CONFIG_H

// ESP01 (black 1MB) Flash Addresses
#define SPI_FLASH_SIZE_MAP                          2
#define SYSTEM_PARTITION_OTA_SIZE                   0x6A000     // ignored
#define SYSTEM_PARTITION_OTA_2_ADDR                 0x81000     // ignored
#define SYSTEM_PARTITION_RF_CAL_ADDR                0xfb000
#define SYSTEM_PARTITION_PHY_DATA_ADDR              0xfc000
#define SYSTEM_PARTITION_SYSTEM_PARAMETER_ADDR      0xfd000
#define SYSTEM_PARTITION_CUSTOMER_PRIV_PARAM_ADDR   0x7c000
#define SYSTEM_PARTITION_CUSTOMER_PRIV_PARAM        SYSTEM_PARTITION_CUSTOMER_BEGIN


#endif