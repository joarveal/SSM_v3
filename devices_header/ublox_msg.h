/*
 * ublox_msg.h
 *
 *  Created on: Apr 26, 2017
 *      Author: waseemh
 */

#ifndef SRC_UBLOX_MSG_H_
#define SRC_UBLOX_MSG_H_

	//command classes
#define 	NAV			0x01
#define 	RXM			0x02
#define 	INF			0x04
#define 	ACK			0x05
#define 	CFG			0x06
#define 	MON			0x0A
#define 	TIM			0x0D
	//IDs for messages
// MON class
#define 	VER			0x04
//CFG class
#define 	CFG_CFG		0x09
#define 	MSG			0x01
#define 	DAT			0x06
#define 	PRT 		0x00
#define 	PM2 		0x3B
#define     PMS			0x86
#define 	RXM_CFG		0x11
#define 	SBAS		0x16
//NAV class
#define 	PVT			0x07
#define		SAT			0x35
//TIM class
//ACK class
	//Synch words
#define 	SYNCH_1		0xB5
#define 	SYNCH_2		0x62

/*
 * macros for sd card
 */

/*
 * typedefs
 */
/*
 * private constants
 */
static const uint8_t cfg_msg_sw_backup[] = {
		0xB5,
		0x62,
		0x02, 0x41, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
		0x4d,
		0x3b
};
static const uint8_t cfg_msg_poll_nav[] = {
		SYNCH_1, SYNCH_2, CFG, MSG,	0x02, 0x00,
		NAV, PVT,		//message NAV type PVT
		0x11,0x3a		//checksum (a and b)
		};
static const uint8_t nav_pvt_gps_data[] = {
		SYNCH_1, SYNCH_2, NAV, PVT, 0x00, 0x00,
		0x08, 0x19		//checksum (a and b)
		};
static const uint8_t cfg_pm2_on_off[] = {
		SYNCH_1, SYNCH_2, CFG, PM2, 0x2C, 0x00,
		0x01,							//msgVersion
		0x00,							//reserved
		0x00,							//reserved
		0x00,							//reserved
		0x00,	0x06,	0x00,	0x00,	//flags =Update RTC & wait for timeFix & ON/OFF mode
		0xD8,	0xD6,	0x00,	0x00,	//updatePeriod=55sec
		0x60,	0xEA,	0x00,	0x00,	//seacrhPeriod=60sec
		0x00,	0x00,	0x00,	0x00,	//gridOffset=0 msec
		0x06,	0x00,					//onTime=6 sec
		0x05,	0x00,					//minAcqTime=5 sec
		0x00,	0x00,					//reserved
		0x00,	0x00,					//reserved
		0x00,	0x00,	0x00,	0x00,	//reserved
		0x00,	0x00,	0x00,	0x00,	//reserved
		0x00,							//reserved
		0x00,							//reserved
		0x00,	0x00,					//reserved
		0x00,	0x00,	0x00,	0x00,	//reserved
		0x77,	0xE9					//checksum (a and b)
		};
static const uint8_t cfg_sbas_disable[] = {
		SYNCH_1, SYNCH_2, CFG, SBAS, 0x08, 0x00,
		0x00,							//mode=disable
		0x00,							//usage
		0x00,							//maxSBAS
		0x00,							//scanMode2
		0x00,	0x00,	0x00,	0x00,	//scanMode1
		0x24,	0x8A					//checksum (a and b)
		};
static const uint8_t cfg_rxm_psm_mode[] = {
		SYNCH_1, SYNCH_2, CFG, RXM_CFG, 0x02, 0x00,
		0x08,							//reserved
		0x01,							//lpmode=power save
		0x22,	0x92					//checksum (a and b)
		};
static const uint8_t cfg_rxm_poll_psm[] = {
		SYNCH_1, SYNCH_2, CFG, RXM_CFG, 0x00, 0x00,
		0x17,	0x4b					//checksum (a and b)
		};
#endif /* SRC_UBLOX_MSG_H_ */
