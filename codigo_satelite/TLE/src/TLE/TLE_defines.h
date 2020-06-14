/*
	-------------------Fuente--------------------
	https://en.wikipedia.org/wiki/Two-line_element_set
	---------------------------------------------
*/

#ifndef _TLE_defines_h_
#define _TLE_defines_h_

// ------------------------------------------------------------------------- Defines genéricos
#define OK 0
#define ERROR 1

#define LINE_TITLE 0
#define LINE_LINE1 1
#define LINE_LINE2 2

// ------------------------------------------------------------------------- Defines Title
#define POS_LINE_TITLE_INIT 0
#define SIZE_LINE_TITLE 24

// ------------------------------------------------------------------------- Defines Line 1

// Indices array line1
#define LINE_NUMBER 0				// Line number
#define CATALOG_NUM 1				// Satellite catalog number
#define CLASSIFICATION 2			// Classification (U=Unclassified, C=Classified, S=Secret)
#define INTER_DESIGN_LAUNCH_YEAR 3	// International Designator (last two digits of launch year)
#define INTER_DESIGN_NUM_YEAR 4		// International Designator (launch number of the year)
#define INTER_DESIGN 5				// International Designator (piece of the launch)
#define EPOCH_YEAR 6				// Epoch Year (last two digits of year)
#define EPOCH_DAY 7					// Epoch (day of the year and fractional portion of the day)
#define FIRST_DERIV_MEAN_MOTION 8	// First Derivative of Mean Motion aka the Ballistic Coefficient [12]
#define SECOND_DERIV_MEARN_MOTION 9 // Second Derivative of Mean Motion (decimal point assumed)
#define DRAG_TERM 10				// Drag Term aka Radiation Pressure Coefficient or BSTAR (decimal point assumed)
#define EPHEM_TYPE 11				// Ephemeris type (internal use only - always zero in distributed TLE data) [13]
#define ELEM_SET_NUM 12				// Element set number. Incremented when a new TLE is generated for this object.
#define CHECKSUM 13					// Checksum (modulo 10)

// Posición en el array
#define POS_LINE1_CATALOG_NUM_INIT 3				 // 3~7. Satellite catalog number
#define POS_LINE1_CLASSIFICATION 8					 // 8. Classification (U=Unclassified, C=Classified, S=Secret)
#define POS_LINE1_INTERN_DES_LAUNCH_YEAR_INIT 10	 // 10~11. International Designator (last two digits of launch year)
#define POS_LINE1_INTERN_DES_LAUNCH_NUM_YEAR_INIT 12 // 12~14. International Designator (launch number of the year)
#define POS_LINE1_INTERN_DESIGN_INIT 15				 // 15~17. International Designator (piece of the launch)
#define POS_LINE1_EPOCH_YEAR_INIT 19				 // 19~20. Epoch Year (last two digits of year)
#define POS_LINE1_EPOCH_DAY_INIT 21					 // 21~32. Epoch (day of the year and fractional portion of the day)
#define POS_LINE1_FIRST_DERIV_MEAN_MOTION_INIT 34	 // 34~43. First Derivative of Mean Motion aka the Ballistic Coefficient [12]
#define POS_LINE1_SECOND_DERIV_MEAN_MOTION_INIT 45	 // 45~52. Second Derivative of Mean Motion (decimal point assumed)
#define POS_LINE1_RADIATION_PRESSURE_COEF_INIT 54	 // 54~61. Drag Term aka Radiation Pressure Coefficient or BSTAR (decimal point assumed)
#define POS_LINE1_EPHEMERIS 63						 // 63. Ephemeris type (internal use only - always zero in distributed TLE data) [13]
#define POS_LINE1_ELEM_SET_NUM_INIT 65				 // 65~68. Element set number. Incremented when a new TLE is generated for this object.
#define POS_LINE1_CHECKSUM 69						 // 69. Checksum (modulo 10)

// ------------------------------------------------------------------------- Defines Line 2
//#define POS_LINE2_NUMBER 2		   // Line number
#define POS_LINE2_CATALOG_NUM_INIT 3   // 3~7. Satellite catalog number
#define POS_LINE2_INCLINATION_INIT 9   // 9~16. Inclination (degrees)
#define POS_LINE2_RIGHT_ASCEN_INIT 18  // 18~25. Right Ascension of the Ascending Node (degrees)
#define POS_LINE2_ECCENTRICITY_INIT 27 // 27~33. Eccentricity (decimal point assumed)
#define POS_LINE2_PERIGEE_INIT 35	   // 35~42. Argument of Perigee (degrees)
#define POS_LINE2_MEAN_ANOMALY_INIT 44 // 44~51. Mean Anomaly (degrees)
#define POS_LINE2_MEAN_MOTION_INIT 53  // 53~63. Mean Motion (revolutions per day)
#define POS_LINE2_REVOLUTIONS_INIT 64  // 64~68. Revolution number at epoch (revolutions)
#define POS_LINE2_CHECKSUM 69		   // 69. Checksum (modulo 10)

#endif
