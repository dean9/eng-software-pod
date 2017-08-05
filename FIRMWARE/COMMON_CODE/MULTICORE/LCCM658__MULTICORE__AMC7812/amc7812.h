/**
 * @file		AMC7812.H
 * @brief		AMC7812 header file.
 * @author		Lachlan Grogan
 * @copyright	This file contains proprietary and confidential information of
 *				SIL3 Pty. Ltd. (ACN 123 529 064). This code may be distributed
 *				under a license from SIL3 Pty. Ltd., and may be used, copied
 *				and/or disclosed only pursuant to the terms of that license agreement.
 *				This copyright notice must be retained as part of this file at all times.
 * @copyright	This file is copyright SIL3 Pty. Ltd. 2003-2016, All Rights Reserved.
 * @st_fileID	LCCM658R0.FILE.001
 */

#ifndef _AMC7812_H_
#define _AMC7812_H_
	#include <localdef.h>
	#if C_LOCALDEF__LCCM658__ENABLE_THIS_MODULE == 1U

		/*******************************************************************************
		Includes
		*******************************************************************************/
		#include <MULTICORE/LCCM284__MULTICORE__FAULT_TREE/fault_tree__public.h>
		#include <MULTICORE/LCCM658__MULTICORE__AMC7812/amc7812__fault_flags.h>

		/*******************************************************************************
		Defines
		*******************************************************************************/

		/** DAC output voltage limit*/
		#define DAC_OUT_MAX_MVOLTS 		5000
		/** DAC output voltage min */
		#define DAC_OUT_MIN_MVOLTS 		0

		/** Num of DAC channels in the device */
		#define NUM_DAC_CHANNELS					(12U)

		/** DAC reference supply */
		#define C_AMC8172__DAC_VREF_VOLTS			(5.0F)

		/** Total precision of the DAC */
		#define C_AMC8172__DAC_PRECISION			(4096.0F)

		/** Multiply volts by thsi value to get DAC units*/
		#define C_AMC8172__DAC_SCALING_VALUE		(C_AMC8172__DAC_PRECISION / C_AMC8172__DAC_VREF_VOLTS)

		// AMC7812 external control pins driven by RM48 N2HET1 and GIOA pins

        #define RM48_N2HET1_PIN__AMC7812_CLR0      		(16U)
        #define RM48_N2HET1_PIN__AMC7812_CLR1      		(17U)
        #define RM48_N2HET1_PIN__AMC7812_CNVT      		(19U)
        #define RM48_GIOA_PIN__AMC7812_DAV      		(5U)



		#define NUM_GPIO_PINS							(8U)


		// DAC Vref (millivolts)
		#define AMC7812_DAC_VREF						2500U

		// DAC gain flag: 0 for low gain (2*Vref), 1 for high gain (5*Vref)
		#define AMC7812_DAC_GAIN_FLAG					0U

		// DAC configuration mode flag: 0 for asynchronous, 1 for synchronous
		#define	AMC7812_DAC_CONFIG_MODE_FLAG			0U

		/** AMC7812 Registers */
		typedef enum
		{

			AMC7812_REG_ADR__LT_TEMP_DATA = 0x00U,

			AMC7812_REG_ADR__D1_TEMP_DATA = 0x01U,

			AMC7812_REG_ADR__D2_TEMP_DATA = 0x02U,

			AMC7812_REG_ADR__TEMP_CONFIG = 0x0AU,

			AMC7812_REG_ADR__TEMP_CONVERT_RATE = 0x0BU,

			AMC7812_REG_ADR__N_FACTOR_D1 = 0x21U,

			AMC7812_REG_ADR__N_FACTOR_D2 = 0x022U,

			AMC7812_REG_ADR__ADC0_DATA = 0x23U,
			AMC7812_REG_ADR__ADC1_DATA = 0x24U,
			AMC7812_REG_ADR__ADC2_DATA = 0x25U,
			AMC7812_REG_ADR__ADC3_DATA = 0x26U,
			AMC7812_REG_ADR__ADC4_DATA = 0x27U,
			AMC7812_REG_ADR__ADC5_DATA = 0x28U,
			AMC7812_REG_ADR__ADC6_DATA = 0x29U,
			AMC7812_REG_ADR__ADC7_DATA = 0x2AU,
			AMC7812_REG_ADR__ADC8_DATA = 0x2BU,
			AMC7812_REG_ADR__ADC9_DATA = 0x2CU,
			AMC7812_REG_ADR__ADC10_DATA = 0x2DU,
			AMC7812_REG_ADR__ADC11_DATA = 0x2EU,
			AMC7812_REG_ADR__ADC12_DATA = 0x2FU,
			AMC7812_REG_ADR__ADC13_DATA = 0x30U,
			AMC7812_REG_ADR__ADC14_DATA = 0x31U,
			AMC7812_REG_ADR__ADC15_DATA = 0x32U,


			AMC7812_REG_ADR__DAC_0_DATA = 0x33U,
			AMC7812_REG_ADR__DAC_1_DATA = 0x34U,
			AMC7812_REG_ADR__DAC_2_DATA = 0x35U,
			AMC7812_REG_ADR__DAC_3_DATA = 0x36U,
			AMC7812_REG_ADR__DAC_4_DATA = 0x37U,
			AMC7812_REG_ADR__DAC_5_DATA = 0x38U,
			AMC7812_REG_ADR__DAC_6_DATA = 0x39U,
			AMC7812_REG_ADR__DAC_7_DATA = 0x3AU,
			AMC7812_REG_ADR__DAC_8_DATA = 0x3BU,
			AMC7812_REG_ADR__DAC_9_DATA = 0x3CU,
			AMC7812_REG_ADR__DAC_10_DATA = 0x3DU,
			AMC7812_REG_ADR__DAC_11_DATA = 0x3EU,

			AMC7812_REG_ADR__GPIO = 0x4BU,

			AMC7812_REG_ADR__SW_DAC_CLEAR = 0x55U,

			AMC7812_REG_ADR__HW_DAC_CLR_EN_0 = 0x56U,

			AMC7812_REG_ADR__HW_DAC_CLR_EN_1 = 0x57U,

			AMC7812_REG_ADR__DAC_CONFIG = 0x58U,

			AMC7812_REG_ADR__DAC_GAIN = 0x59U,

			AMC7812_REG_ADR__POWER_DOWN = 0x6BU,

			AMC7812_REG_ADR__DEVICE_ID = 0x6CU,

			AMC7812_REG_ADR__SW_RESET = 0x7CU,



		} TE_AMC7812__REG_ADDX;


		/** States for the AMC7812 main state machine */
		typedef enum
		{

			/** Rest state out of power up */
			AMC7812_STATE__RESET = 0U,

			/** Configure the DAC to suit our needs.
			 * Do this after reset */
			AMC7812_STATE__CONFIGURE_DAC,

			/** Idle, waiting for a command */
			AMC7812_STATE__IDLE,

			/** Update the DAC Settings */
			AMC7812_STATE__UPDATE_DAC,

			/** Some fault has occurred with the DAC
			 * Stay in this state until its fixed */
			AMC7812_STATE__FAULT,

		}E_AMC7812__MNAIN_STATES_T;




		/*******************************************************************************
		Structures
		*******************************************************************************/

		/** Main DAC structure */
		struct _strAMC7812
		{

			/** The current state */
			E_AMC7812__MNAIN_STATES_T eState;

			/** Top level fault handling structure */
			FAULT_TREE__PUBLIC_T sFaultTree;

			/** DAC Specific Structure */
			struct
			{

				/** The requested output values for each DAC channel */
				Luint16 u16DAC_OutputValue[NUM_DAC_CHANNELS];

				/** Indicate that a new DAC value has been latched */
				Luint8 u8NewValueLatched[NUM_DAC_CHANNELS];

				/** For round robbin updates */
				Luint8 u8UpdatePos;

			}sDAC;
#if 0

			// counter for the number of main program loops

			Luint32 u32LoopCounter;

			// DAC voltage limits - millivolts

			Luint16 u16MaxVoltage;
			Luint16 u16MinVoltage;

			// Input data to be set by function calling DAC:

			// Commanded value (e.g., RPMs)

			Luint16 u16Command;

			// Highest permissible value for the commanded quantity

			Luint16 u16MaxCommandValue;

			// Lowest permissible value for the commanded quantity

			Luint16 u16MinCommandValue;

			// Output channel data

			Luint8 u8DACRegAddr;

			// DAC gain flag

			Luint8 u8Gain;

			// DAC output scale factor

			Lfloat32 f32ScaleFactor;
#endif //0
		};



		/*******************************************************************************
		Function Prototypes
		*******************************************************************************/
		void vAMC7812__Init(void);
		void vAMC7812__Process(void);
		void vAMC7182__DAC_SetVoltage(Luint8 u8Channel, Lfloat32 f32Voltage);
		Luint32 u32AMC7812__Get_FaultFlags(void);
		E_AMC7812__MNAIN_STATES_T eAMC7812__Get_State(void);
		
		//Lowlevel
		void vAMC7812_LOWLEVEL__Init(void);
		void vAMC7812_LOWLEVEL__Reset(void);

		//I2C
		void vAMC7812_I2C__Init(void);

		Lint16 s16AMC7812_I2C__TxCommand(Luint8 u8DeviceAddx, TE_AMC7812__REG_ADDX eReg);
		Lint16 s16AMC7812_I2C__WriteU16(Luint8 u8DeviceAddx, TE_AMC7812__REG_ADDX eReg, Luint16 u16Value);
		Lint16 s16AMC7812_I2C__ReadU16(Luint8 u8DeviceAddx, TE_AMC7812__REG_ADDX eReg, Luint16 *pu16Value);

		
		//DAC
		void vAMC7812_DAC__Init(void);
		void vAMC7812_DAC__Process(void);
		void vAMC7182_DAC__DAC_UpdateVoltage(Luint8 u8Channel, Lfloat32 f32Voltage);

		//ADC
		void vAMC7812_ADC__Init(void);
		void vAMC7812_ADC__Process(void);
		
		//setup the GPIO
		void vAMC7812_GPIO__Init(void);
		void vAMC7812_GPIO__Process(void);
		
		#ifdef WIN32
			typedef void (__cdecl * pAMC7812_WIN32__DACVoltsCallback_FuncType)(Luint8 u8Channel, Lfloat32 f32Volts);
			DLL_DECLARATION void vAMC7812_WIN32__Set_DACVoltsCallback(pAMC7812_WIN32__DACVoltsCallback_FuncType pFunc);
			void vAMC7182_WIN32__DAC_SetVolage(Luint8 u8Channel, Lfloat32 f32Volts);
		#endif

	#endif //#if C_LOCALDEF__LCCM658__ENABLE_THIS_MODULE == 1U
	//safetys
	#ifndef C_LOCALDEF__LCCM658__ENABLE_THIS_MODULE
		#error
	#endif
#endif //_AMC7812_H_

