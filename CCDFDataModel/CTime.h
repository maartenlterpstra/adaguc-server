/******************************************************************************
 * 
 * Project:  CTime
 * Purpose:  Date Time functions
 * Author:   Maarten Plieger, plieger "at" knmi.nl
 * Date:     2013-06-01
 *
 ******************************************************************************
 *
 * Copyright 2013, Royal Netherlands Meteorological Institute (KNMI)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 ******************************************************************************/

#ifndef CTIME_H
#define CTIME_H
#include <udunits.h>

#include "CTypes.h"

#include <time.h>
#include <sys/types.h>
#include <stdlib.h>
#define CTIME_CONVERSION_ERROR 1

#define CTIME_MODE_UTCALENDAR 0
#define CTIME_MODE_YYYYMM 1
#include "CDebugger.h"
class CTime{
  private:
  CT::string currentUnit;
  void safestrcpy(char *s1,const char*s2,size_t size_s1);
  DEF_ERRORFUNCTION();
  public:
  utUnit  dataunits;
  bool isInitialized;
  int mode;
  /**
   * Class which holds date parameters like year, month, day, hour, minute, second and offset
   */
  class Date {
  public:
    int     year, month, day, hour, minute;
    double   second;
    double  offset;
  };
  
  /**
   * Constructor
   */
  CTime();
  
  /**
   * Destructor
   */
  ~CTime();
  
  /**
   * Static function which converts an exception into a readable message
   * @param int The value of catched exception 
   * @return CT::string with the readable message
   */
  static CT::string getErrorMessage(int CTimeParserException);
  
 
  
  /**
   * resets CTime
   */
  void reset();
  
  /**
   * Initializes CTime
   * @param units CF time units
   * @return 0 on success 1 on failure.
   */
  int init(const char *units);
  
  /**
   * Turns double value into a date object
   * Throws integer CTIME_CONVERSION_ERROR when fails
   * @param offset The value to convert to date
   * @return the date object
   */
  Date getDate(double offset);
  
  
  /**
   * Turns date object into double value
   * Throws integer CTIME_CONVERSION_ERROR when fails
   * @param Date the date object
   * @return The value to convert to date
   */
  double dateToOffset( Date date);
  
  /**
   * Converts YYYYmmddThhmmss string to Date
   * Throws integer CTIME_CONVERSION_ERROR when fails.
   * @param szTime the time string to convert
   * @return The Date
   */
  Date stringToDate(const char*szTime);
  

  /**
   * Converts YYYY-mm-ddThh:mm:ss string to Date
   * Throws integer CTIME_CONVERSION_ERROR when fails.
   * @param szTime the time string to convert
   * @return The Date
   */
  Date ISOStringToDate(const char*szTime);
  
  /**
   * Converts YYYYmmddThhmmss string to Date
   * Converts YYYY-mm-ddThh:mm:ss string to Date
   * Throws integer CTIME_CONVERSION_ERROR when fails.
   * @param szTime the time string to convert
   * @return The Date
   */
  Date freeDateStringToDate(const char*szTime);
  
  
  /**
   * Converts date object to string
   * @param date
   * @param string Format YYYYmmddThhmmss
   */
  CT::string dateToString(Date date);
  
  /**
   * Converts date object to string
   * @param date
   * @param string Format YYYY-mm-ddThh:mm:ss
   */
  CT::string dateToISOString(Date date);
  
  /**
   * Get current system time as ISO string
   * @return Current system time as ISO string
   */
  static CT::string currentDateTime();
  
  /**
   * Time values received in the URL as input can be rounded to more discrete time periods. 
   * For example when noon, 12:03:53, is received as input, it is possible to round this to 12:00:00. 
   * This enables the service to respond to fuzzy time intervals.
   * 
   * PT15M/low: 2016-01-13T08:35:00Z --> 2016-01-13T08:30:00Z
   * PT15M/high: 2016-01-13T08:36:00Z --> 2016-01-13T08:45:00Z
   * PT15M/round: 2016-01-13T08:38:00Z --> 2016-01-13T08:45:00Z
   * 
   * @param value The input value to quantize, as date string
   * @param period The time resolution to round to
   * @param method  Can be either low, high and round, defaults to round.
   * @return The quantized date as ISO8601 String
   */
  static CT::string quantizeTimeToISO8601(CT::string value, CT::string period, CT::string method);

};
#endif

