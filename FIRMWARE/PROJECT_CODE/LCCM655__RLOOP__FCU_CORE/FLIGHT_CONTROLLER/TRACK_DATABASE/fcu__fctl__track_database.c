/**
 * @file		FCU__FCTL__TRACK_DATABASE.C
 * @brief		Track Management Database
 * @author		Lachlan Grogan
 * @copyright	rLoop Inc.
 */
/**
 * @addtogroup RLOOP
 * @{ */
/**
 * @addtogroup FCU
 * @ingroup RLOOP
 * @{ */
/**
 * @addtogroup FCU__FLIGHT_CTL__TRACK_DATABASE
 * @ingroup FCU
 * @{ */

#include "../../fcu_core.h"

#include "fcu__fctl__track_database__types.h"

#if C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE == 1U
#if C_LOCALDEF__LCCM655__ENABLE_FLIGHT_CONTROL == 1U
#if C_LOCALDEF__LCCM655__ENABLE_TRACK_DB == 1U

//the structure
extern struct _strFCU sFCU;

//The current working track database
struct _strTrackDatabase sTrackDB;

Luint32 u32FCU_FCTL_TRACKDB__Get_Current_TrackEndPosX_mm(void);

void vFCU_FCTL_TRACKDB__Init(void)
{

	//init some vars
	sFCU.sFlightControl.sTrackDB.u32CurrentDB = u32EEPARAM__Read(C_LOCALDEF__LCCM655__FCTL_TRACKDB___CURRENT_DB);
	if(sFCU.sFlightControl.sTrackDB.u32CurrentDB >= C_FCTL_TRACKDB__MAX_MEM_DATABASES)
	{
		//reset to zero
		//don't bother updating EEPROM as we can do this later.
		sFCU.sFlightControl.sTrackDB.u32CurrentDB = 0U;
	}

	vFAULTTREE__Init(&sFCU.sFlightControl.sTrackDB.sFaultFlags);

	//get the memory up
	//The risk here is that we load with DB 0, which is OK for now, but in
	//the actual run we need to make sure as part of our configuration that we
	//have the correct DB selected.
	vFCU_FCTL_TRACKDB_MEM__Init();

#ifdef WIN32
	vFCU_FCTL_TRACKDB_WIN32__Init();
#endif

}



void vFCU_FCTL_TRACKDB__Process(void)
{
	Luint32 u32Test;

	vFCU_FCTL_TRACKDB_MEM__Process();

#ifdef WIN32
	vFCU_FCTL_TRACKDB_WIN32__Process();
#endif

	u32Test = u32FCU_FCTL_TRACKDB__Get_Current_TrackEndPosX_mm();

	u32Test = 0U;

}


//allow the ground to change the current database, this will force a re-load
void vFCU_FCTL_TRACKDB__Set_CurrentDB(Luint32 u32Key, Luint32 u32TrackID)
{
	if(u32Key == 0x11223344U)
	{
		//check
		if(u32TrackID < C_FCTL_TRACKDB__MAX_MEM_DATABASES)
		{
			sFCU.sFlightControl.sTrackDB.u32CurrentDB = u32TrackID;

			//update the EEPROM
			vEEPARAM__WriteU32(C_LOCALDEF__LCCM655__FCTL_TRACKDB___CURRENT_DB, sFCU.sFlightControl.sTrackDB.u32CurrentDB, DELAY_T__IMMEDIATE_WRITE);

			//reinit the track database memory
			vFCU_FCTL_TRACKDB_MEM__Init();
		}
		else
		{
			//big issue, can't set
		}


	}
	else
	{

	}
}

Luint32 u32FCU_FCTL_TRACKDB__Get_CurrentDB(void)
{
	return sFCU.sFlightControl.sTrackDB.u32CurrentDB;

}

Luint32 u32FCU_FCTL_TRACKDB__Get_Current_TrackEndPosX_mm(void)
{
	return u32NUMERICAL_CONVERT__Array(&sTrackDB.sDB.u8TrackEndXPosition_mm[0]);
}


#endif //C_LOCALDEF__LCCM655__ENABLE_TRACK_DB
#ifndef C_LOCALDEF__LCCM655__ENABLE_TRACK_DB
	#error
#endif

#endif //C_LOCALDEF__LCCM655__ENABLE_FLIGHT_CONTROL
#ifndef C_LOCALDEF__LCCM655__ENABLE_FLIGHT_CONTROL
	#error
#endif

#endif //#if C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE == 1U
//safetys
#ifndef C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE
	#error
#endif
/** @} */
/** @} */
/** @} */

