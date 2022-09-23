#ifndef __PORTING_MISC_H__
#define __PORTING_MISC_H__

#include "NuMicro.h"

/**************************************************************************
 * Definitions
 **************************************************************************/
/**
 * @defgroup mcuMisc MCU Miscellaneous Porting
 * @{
 * @ingroup mcuPortingDef
 * @details MCU miscellaneous porting related definition and functions.
 * @}
 * @defgroup mcuMiscDef MCU Miscellaneous Porting Definition
 * @{
 * @ingroup mcuMisc
 * @details MCU miscellaneous setting definitions.
 * @}
 * @defgroup mcuBasicTypeDef Basic Type Porting Definition
 * @{
 * @ingroup mcuMiscDef
 * @details Basic type definitions.
 * @}
 * @defgroup mcuIOMappingDef MCU SPI I/O Re-mapping Definition
 * @{
 * @ingroup mcuMiscDef
 * @details Users can dynamically configure SPI pins through SPI I/O re-mapping settings.
 * @}
 * @defgroup mcuOtherDef MCU Other Definitions
 * @{
 * @ingroup mcuMiscDef
 * @}
 **************************************************************************/

/**
 * @ingroup mcuBasicTypeDef
 * @{
 */
#define BIT1_DEF            BIT1     /**<  Bit 1 mask of an 32 bit integer  */

#define ENABLE_DEF          ENABLE   /**< Define enable.   */
#define DISABLE_DEF         DISABLE  /**< Define disable.   */

#define TRUE_DEF            TRUE     /**< Define true.   */
#define FALSE_DEF           FALSE    /**< Define false.   */
/** @} */


/**
 * @ingroup mcuIOMappingDef
 * @{
 */
#if (_BOARD_SELECTION_==_BOARD_NUVOTON_M031_SIP_ || _BOARD_SELECTION_==_BOARD_NUVOTON_M032_SIP_)
#define SPI_IO_ORDER        6       /**< SPI Order number is set to 6.  */
#elif (_BOARD_SELECTION_==_BOARD_NUVOTON_M031TD2AE_QFN33_)
#define SPI_IO_ORDER        1       /**< SPI Order number is set to 1.  */
#else
#define SPI_IO_ORDER        1       /**< SPI Order number is set to 1(normal).  */
#endif


#if (SPI_IO_ORDER==1)   //GPIO_sel order(0:CS, 1:CK, 2:MOSI, 3:MISO, 4:INT)
#define SPI_CS              PA3     /**< (GPIO0) Initial SPI CS pin.     */
#define SPI_CK              PA2     /**< (GPIO1) Initial SPI Clock pin.  */
#define SPI_MOSI            PA0     /**< (GPIO2) Initial SPI MOSI pin.   */
#define SPI_MISO            PA1     /**< (GPIO3) Initial SPI MISO pin.   */

#if (_BOARD_SELECTION_ == _BOARD_NUVOTON_M031SE_)
#define DEFAULT_INT         PA5     /**< (GPIO4) Initial interrupt pin.   */
#elif (_BOARD_SELECTION_ == _BOARD_NUVOTON_M032SE3AE_)
#define DEFAULT_INT         PA5     /**< (GPIO4) Initial interrupt pin.   */
#elif (_BOARD_SELECTION_ == _BOARD_NUVOTON_M487JIDAE_B3_) //M487_EVK3
#define DEFAULT_INT         PC9     /**< (GPIO4) Initial interrupt pin.   */
#elif (_BOARD_SELECTION_ == _BOARD_NUVOTON_M031TD2AE_QFN33_)
#define DEFAULT_INT         PF15    /**< (GPIO4) Initial interrupt pin.   */
#elif (_BOARD_SELECTION_ == _BOARD_NUVOTON_M031_SIP_)
#define DEFAULT_INT         PC2     /**< (GPIO4) Initial interrupt pin.   */
#endif    //#if(_BOARD_SELECTION_ == _BOARD_NUVOTON_M031SE_)

#elif (SPI_IO_ORDER==6)  //GPIO_sel order(0:INT, 1:CS, 2:CK, 3:MISO, 4:MOSI)

#if (_BOARD_SELECTION_==_BOARD_NUVOTON_M031_SIP_)
#define SPI_CS              PC2     /**< (GPIO0) Initial SPI CS pin.      */
#define SPI_CK              PD3     /**< (GPIO1) Initial SPI Clock pin.   */
#define SPI_MOSI            PD2     /**< (GPIO2) Initial SPI MOSI pin.    */
#define SPI_MISO            PD1     /**< (GPIO3) Initial SPI MISO pin.    */
#define DEFAULT_INT         PD0     /**< (GPIO4) Initial interrupt pin.   */
#elif (_BOARD_SELECTION_==_BOARD_NUVOTON_M032_SIP_)
#define SPI_CS              PD12    /**< (GPIO0) Initial SPI CS pin.      */
#define SPI_CK              PF9     /**< (GPIO1) Initial SPI Clock pin.   */
#define SPI_MOSI            PF8     /**< (GPIO2) Initial SPI MOSI pin.    */
#define SPI_MISO            PF7     /**< (GPIO3) Initial SPI MISO pin.    */
#define DEFAULT_INT         PF6     /**< (GPIO4) Initial interrupt pin.   */
#else
#define SPI_CS              PA5     /**< (GPIO0) Initial SPI CS pin.      */
#define SPI_CK              PA3     /**< (GPIO1) Initial SPI Clock pin.   */
#define SPI_MOSI            PA2     /**< (GPIO2) Initial SPI MOSI pin.    */
#define SPI_MISO            PA1     /**< (GPIO3) Initial SPI MISO pin.    */
#define DEFAULT_INT         PA0     /**< (GPIO4) Initial interrupt pin.   */
#endif //(_BOARD_SELECTION_==xxxxx)

#endif //(SPI_IO_ORDER)



#if ((_BOARD_SELECTION_ == _BOARD_NUVOTON_M031SE_) || (_BOARD_SELECTION_ == _BOARD_NUVOTON_M032SE3AE_))
#define  RESET_RF           PA4     /**< RF reset pin.   */
#elif (_BOARD_SELECTION_ == _BOARD_NUVOTON_M031TD2AE_QFN33_)
#define  RESET_RF           PC1     /**< RF reset pin.   */
#elif (_BOARD_SELECTION_ == _BOARD_NUVOTON_M031_SIP_)
#define  RESET_RF           PA12    /**< RF reset pin.   */
#elif (_BOARD_SELECTION_ == _BOARD_NUVOTON_M032_SIP_)
#define  RESET_RF           PH4     /**< RF reset pin.   */
#else
#define  RESET_RF           PC10    /**< RF reset pin.   */
#endif
/** @} */ //(@ingroup mcuIOMappingDef)

/**
 * @ingroup mcuOtherDef
 * @{
 */
#ifdef BLE_DEMO
#if (BLE_DEMO==DEMO_HRS_DTM)
#if (_BOARD_SELECTION_ == _BOARD_NUVOTON_M031TD2AE_QFN33_)
#define  DEMO_GPI_SEL_PIN   PC0     /**< DTM Demo Control Pin.   */
#elif (_BOARD_SELECTION_ == _BOARD_NUVOTON_M031_SIP_)
#define  DEMO_GPI_SEL_PIN   PC0     /**< DTM Demo Control Pin.   */
#elif (_BOARD_SELECTION_ == _BOARD_NUVOTON_M032_SIP_)
#define  DEMO_GPI_SEL_PIN   PC0     /**< DTM Demo Control Pin.   */
#else
#endif
#endif
#endif


#if (_BOARD_SELECTION_ == _BOARD_NUVOTON_M031_SIP_ || _BOARD_SELECTION_ == _BOARD_NUVOTON_M032_SIP_)
#define  LED_1              PF15    /**< LED_1 Pin.   */
#else
#define  LED_1              PB14    /**< LED_1 Pin.   */
#endif

/** @} */ //(@ingroup mcuOtherDef)



/**************************************************************************
* Functions
**************************************************************************/
/** @defgroup mcuMiscFunc MCU Miscellaneous Porting Function
 * @{
 * @ingroup mcuMisc
 * @details MCU miscellaneous function definitions.
 * @}
 *@defgroup mcuIOMappingFunc MCU SPI I/O Re-mapping Function
 * @{
 * @details Here shows the MCU SPI I/O re-mapping function.
 * @ingroup mcuMiscFunc
 * @}
 * @defgroup mcuGpioFunc MCU GPIO Related Function
 * @{
 * @details Here shows the MCU GPIO related function definitions.
 * @ingroup mcuMiscFunc
 * @}
 * @defgroup mcuSysFunc MCU System Related Function
 * @{
 * @details Here shows the MCU system related function definitions.
 * @ingroup mcuMiscFunc
 * @}
 **************************************************************************/

/** MCU SPI IO mapping.
 *  Must do this after Power ON and MCU GPIO initialed.
 *
 * @ingroup mcuIOMappingFunc
 */
void setRF_SpiIoMapping(void);


/** MCU Implemented RF Reset
 *
 * @ingroup mcuGpioFunc
 */
void seBLE_GpioReset(void);


/** MCU Set Enable RF Interrupt Pin.
 *
 * @ingroup mcuGpioFunc
 */
void setBLE_GpioIntEnable(void);


/** MCU Set Disable RF Interrupt Pin.
 *
 * @ingroup mcuGpioFunc
 */
void setBLE_GpioIntDisable(void);


/** MCU Enter System Power Down Mode.
 *
 * @ingroup mcuSysFunc
 */
void setMCU_SystemPowerDown(void);


/** MCU Implemented Tiny Delay Function for BLE Stack.
 *
 * @ingroup mcuSysFunc
 * @param[in] u32Usec   : delay time in microseconds.
 */
void setMCU_TinyDelay(uint32_t u32Usec);

void MCU_WDTmr_En(void);
void BLE_SPI_DATAready_IRQHandler(void);

#endif  //__PORTING_MISC_H__

