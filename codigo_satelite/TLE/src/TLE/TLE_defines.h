/*
	-------------------Fuente--------------------
	https://en.wikipedia.org/wiki/Two-line_element_set
	---------------------------------------------
*/

#ifndef _TLE_defines_h_
#define _TLE_defines_h_

// ------------------------------------------------------------------------- Defines genéricos
#define LINE_TITLE 72 // cualquier número que no esté ocupado (1~69)
#define LINE1 73
#define LINE2 74

#define SIZE_LINES 71

// ------------------------------------------------------------------------- Defines Title
#define SIZE_LINE_TITLE 24

// ------------------------------------------------------------------------- Defines Line 1
#define LINE1_NUM 1 // 1. Line number

#define LINE1_CATALOG_NUM 3 // 3~7. Satellite catalog number
#define LINE1_CATALOG_NUM_END 7

#define LINE1_CLASSIFICATION 8 // 8. Classification (U=Unclassified, C=Classified, S=Secret)

#define LINE1_INTERN_DES_LAUNCH_YEAR 10 // 10~11. International Designator (last two digits of launch year)

#define LINE1_INTERN_DES_LAUNCH_NUM_YEAR 12 // 12~14. International Designator (launch number of the year)

#define LINE1_INTERN_DESIGN 15 // 15~17. International Designator (piece of the launch)

#define LINE1_EPOCH_YEAR 19 // 19~20. Epoch Year (last two digits of year)

#define LINE1_EPOCH_DAY 21 // 21~32. Epoch (day of the year and fractional portion of the day)
#define LINE1_EPOCH_DAY_END 32

#define LINE1_FIRST_DERIV_MEAN_MOTION 34 // 34~43. First Derivative of Mean Motion aka the Ballistic Coefficient [12]
#define LINE1_FIRST_DERIV_MEAN_MOTION_END 43

#define LINE1_SECOND_DERIV_MEAN_MOTION 45 // 45~52. Second Derivative of Mean Motion (decimal point assumed)
#define LINE1_SECOND_DERIV_MEAN_MOTION_END 52

#define LINE1_DRAG_TERM_COEF 54 // 54~61. Drag Term aka Radiation Pressure Coefficient or BSTAR (decimal point assumed)
#define LINE1_DRAG_TERM_COEF_END 61

#define LINE1_EPHEMERIS 63 // 63. Ephemeris type (internal use only - always zero in distributed TLE data) [13]

#define LINE1_ELEM_SET_NUM 65 // 65~68. Element set number. Incremented when a new TLE is generated for this object.
#define LINE1_ELEM_SET_NUM_END 68

#define LINE1_CHECKSUM 69 // 69. Checksum (modulo 10)

// ------------------------------------------------------------------------- Defines Line 2
#define LINE2_NUM 1 // Line number

#define LINE2_CATALOG_NUM 3 // 3~7. Satellite catalog number
#define LINE2_CATALOG_NUM_END 7

#define LINE2_INCLINATION 9		 // 9~16. Inclination (degrees)
#define LINE2_INCLINATION_END 16 // 9~16. Inclination (degrees)

#define LINE2_RIGHT_ASCEN 18 // 18~25. Right Ascension of the Ascending Node (degrees)
#define LINE2_RIGHT_ASCEN_END 25

#define LINE2_ECCENTRICITY 27 // 27~33. Eccentricity (decimal point assumed)
#define LINE2_ECCENTRICITY_END 33

#define LINE2_PERIGEE 35 // 35~42. Argument of Perigee (degrees)
#define LINE2_PERIGEE_END 42

#define LINE2_MEAN_ANOMALY 44 // 44~51. Mean Anomaly (degrees)
#define LINE2_MEAN_ANOMALY_END 51

#define LINE2_MEAN_MOTION 53 // 53~63. Mean Motion (revolutions per day)
#define LINE2_MEAN_MOTION_END 63

#define LINE2_REVOLUTIONS 64 // 64~68. Revolution number at epoch (revolutions)
#define LINE2_REVOLUTIONS_END 68

#define LINE2_CHECKSUM 69 // 69. Checksum (modulo 10)

#endif
