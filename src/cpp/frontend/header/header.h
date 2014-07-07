/**
 *
 *       \file       header.h
 *
 *       \brief      Including header files which are common to all.
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       \license    GNU General Public License\n
 *       \copyright  Copyright (c) 2013, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iterator>
//#include <exception>

//#include <boost/date_time/local_time/local_time.hpp>
//#include <boost/algorithm/string/split.hpp>
//#include <boost/algorithm/string.hpp>
//#include <boost/algorithm/string/erase.hpp>
//#include <boost/algorithm/string/trim.hpp>
//#include <cassert>

using namespace std;
//using namespace boost::algorithm;

/*
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

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */

