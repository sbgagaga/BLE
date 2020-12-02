/**
 ****************************************************************************************
 *
 * @file app_task.h
 *
 * @brief Header file - APPTASK.
 *
 * Copyright (C) RivieraWaves 2009-2015
 *
 *
 ****************************************************************************************
 */

#ifndef APP_TASK_H_
#define APP_TASK_H_

/**
 ****************************************************************************************
 * @addtogroup APPTASK Task
 * @ingroup APP
 * @brief Routes ALL messages to/from APP block.
 *
 * The APPTASK is the block responsible for bridging the final application with the
 * RWBLE software host stack. It communicates with the different modules of the BLE host,
 * i.e. @ref SMP, @ref GAP and @ref GATT.
 *
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"    // SW configuration

#if (BLE_APP_PRESENT)

#include <stdint.h>         // Standard Integer
#include "rwip.h"
#include "rwip_task.h"      // Task definitions
#include "ke_task.h"        // Kernel Task
#include "user.h"
/*
 * DEFINES
 ****************************************************************************************
 */

/// Number of APP Task Instances
#define APP_IDX_MAX                 (1)
#define TIMER_UNIT                  (1)//ZY
#define Tx_Max_Numb					(20)
#define Send_Delay_Numb				(15)
#define NAME_ADDR					0x00018800
/*
 * ENUMERATIONS
 ****************************************************************************************
 */

/// States of APP task
enum appm_state
{
    /// Initialization state
    APPM_INIT,
    /// Database create state
    APPM_CREATE_DB,
    /// Ready State
    APPM_READY,
    /// Advertising state
    APPM_ADVERTISING,
    /// Connected state
    APPM_CONNECTED,
    /// Number of defined states.
    APPM_STATE_MAX
};


/// APP Task messages
enum appm_msg
{
    APPM_DUMMY_MSG = TASK_FIRST_MSG(TASK_ID_APP),
		
    APP_PARAM_UPDATE_REQ_IND,
	
	APP_PERIOD_TIMER,	
	
	APP_SYS_TIMER,
};


/*
 * GLOBAL VARIABLE DECLARATIONS
 ****************************************************************************************
 */
extern uint8_t RxRevFlag;
extern uint8_t RxRevCnt;
extern uint32_t connect_timeout_cnt;
extern uint8_t connect_status_flag;
extern uint8_t TxDatePackEnd;
extern uint8_t p_index;
extern const struct ke_state_handler appm_default_handler;
extern ke_state_t appm_state[APP_IDX_MAX];


/// @} APPTASK

#endif //(BLE_APP_PRESENT)

#endif // APP_TASK_H_
