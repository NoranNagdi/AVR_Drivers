/*
 * KEYPAD_cfg.h
 *
 * Created: 10/21/2023 2:54:44 PM
 *  Author: DELL
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                   4
#define KEYPAD_NUM_ROWS                   4

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT_ID                PORTC_ID

#define KEYPAD_FIRST_ROW_PIN_ID           PIN5_ID
#define KEYPAD_SECOND_ROW_PIN_ID          PIN4_ID
#define KEYPAD_THIRD_ROW_PIN_ID           PIN3_ID
#define KEYPAD_FORTH_ROW_PIN_ID           PIN2_ID

#define KEYPAD_COL_PORT_ID                PORTD_ID

#define KEYPAD_FIRST_COL_PIN_ID           PIN7_ID
#define KEYPAD_SECOND_COL_PIN_ID          PIN6_ID
#define KEYPAD_THIRD_COL_PIN_ID           PIN5_ID
#define KEYPAD_FORTH_COL_PIN_ID           PIN3_ID







#endif /* KEYPAD_CFG_H_ */