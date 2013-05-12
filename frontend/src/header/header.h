/*
 * ===================================================================
 *
 *       Filename:  header.h
 *
 *    Description:  Header file for including commom headerfiles.
 *
 *        Version:  0.7
 *        Created:  Friday 15 February 2013 04:53:17  IST
 *       Compiler:  g++
 *
 *         Author:  Mandeep Kaur, meghasimak@gmail.com
 *        License:  GNU General Public License
 *      Copyright:  Copyright (c) 2013, Great Developers
 *
 * ===================================================================
 */

#ifndef HEADER_H
#define HEADER_H

/**-------------------------------------------------------------------
 *  Header file
 *------------------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <exception>

// for using multi-dimentional array
#include <boost/multi_array.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <cassert>

/**-------------------------------------------------------------------
 *  using namespace std
 *------------------------------------------------------------------*/

using namespace std;
using namespace boost::algorithm;

/**
 *  Typedef variables for using vector definiton
 */

typedef vector<string> STRING_VEC;
typedef vector<vector<string> > STRING_2DVEC;
typedef vector<vector<vector<string> > > STRING_3DVEC;
typedef vector<vector<vector<vector<string> > > > STRING_4DVEC;
typedef vector<vector<vector<int> > > INT_3DVEC;
typedef vector<vector<int> > INT_2DVEC;
typedef vector<int> INT_VEC;

#endif
