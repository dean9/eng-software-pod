#ifndef _LCCM655__04__FAULT_FLAGS_H_
#define _LCCM655__04__FAULT_FLAGS_H_
/*
 * @fault_index
 * 00
 * 
 * @brief
 * GENERAL 
 * 
 * @note
 * A general fault has occurred. 
 * 
 * @tool
 * [BRAKES]|[00]|[GENERAL ]|[A general fault has occurred. ]
*/
#define C_LCCM655__BRAKES__FAULT_INDEX__00				0x00000000U
#define C_LCCM655__BRAKES__FAULT_INDEX_MASK__00			0x00000001U

/*
 * @fault_index
 * 01
 * 
 * @brief
 * MLP_RANGE_LIMIT_LOW 
 * 
 * @note
 * The MLP sensor has a low range reading. 
 * 
 * @tool
 * [BRAKES]|[01]|[MLP_RANGE_LIMIT_LOW ]|[The MLP sensor has a low range reading. ]
*/
#define C_LCCM655__BRAKES__FAULT_INDEX__01				0x00000001U
#define C_LCCM655__BRAKES__FAULT_INDEX_MASK__01			0x00000002U

/*
 * @fault_index
 * 02
 * 
 * @brief
 * MLP_RANGE_LIMIT_HIGH 
 * 
 * @note
 * The MLP sensor has a high range reading. 
 * 
 * @tool
 * [BRAKES]|[02]|[MLP_RANGE_LIMIT_HIGH ]|[The MLP sensor has a high range reading. ]
*/
#define C_LCCM655__BRAKES__FAULT_INDEX__02				0x00000002U
#define C_LCCM655__BRAKES__FAULT_INDEX_MASK__02			0x00000004U

/*
 * @fault_index
 * 03
 * 
 * @brief
 * CALIBRATION DATA RELOAD
 
 * 
 * @note
 * The calibration data was reloaded. This could indicate the cal data is 
 * invalid. 
 * 
 * @tool
 * [BRAKES]|[03]|[CALIBRATION DATA RELOAD
 ]|[The calibration data was reloaded. This could indicate the cal data is 
invalid. ]
*/
#define C_LCCM655__BRAKES__FAULT_INDEX__03				0x00000003U
#define C_LCCM655__BRAKES__FAULT_INDEX_MASK__03			0x00000008U

/*
 * @fault_index
 * 04
 * 
 * @brief
 * DEVELOPMENT MODE ENABLE 
 * 
 * @note
 * Dev mode is enabled.  Some functions may be unavailable. 
 * 
 * @tool
 * [BRAKES]|[04]|[DEVELOPMENT MODE ENABLE ]|[Dev mode is enabled.  Some functions may be unavailable. ]
*/
#define C_LCCM655__BRAKES__FAULT_INDEX__04				0x00000004U
#define C_LCCM655__BRAKES__FAULT_INDEX_MASK__04			0x00000010U

#endif //#ifndef _LCCM655__FAULT_FLAGS_H_

